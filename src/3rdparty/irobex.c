/***************************************************************************
 *   Copyright (C) 2004 by Nick Protopapas                                 *
 *   nick_tg@yahoo.com                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/

/* $Id: irobex.c 41 2007-05-07 16:41:25Z makhtar $ */
/* Portion Copyright (C) 2007 by Makhtar Diouf

   Code from the irobex-apps project.
   Modifications are under the license specified above.
*/

#define _GNU_SOURCE
#include "irobex.h"
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

obex_t* handleSend;
obex_t* handleRcv;
int obexProtocolType = OBEX_PROTOCOL_GENERIC;
volatile int sendingFinished;
volatile int receivingFinished;
volatile int lastSendRsp = OBEX_RSP_BAD_REQUEST;

/** Default receiving directory */
char* rcvDir = ".qirdabox";


void
PutDone(obex_object_t* object)
{
    obex_headerdata_t hv;
    uint8_t hi;
    int hlen;
    const uint8_t *body = NULL;
    int bodylen = 0;
    char* name = NULL;
    char* namebuf = NULL;
    int nooverwrite = 0;

    while (OBEX_ObjectGetNextHeader(handleRcv, object, &hi, &hv, (uint32_t*)&hlen)) {
        switch (hi) {
        case OBEX_HDR_BODY:
            body = hv.bs;
            bodylen = hlen;
            break;
        case OBEX_HDR_NAME:
            if ( (namebuf = malloc(hlen / 2))) {
                /* OBEX_UnicodeToChar((uint8_t*)namebuf, hv.bs, hlen);*/
                strcpy(namebuf, hv.bs);
                name = namebuf;
            }
            break;

        case OBEX_HDR_LENGTH:
            printf("HEADERLENGTH = %d\n", hv.bq4);
            break;

        case HEADER_CREATOR_ID:
            printf("CREATORID = %#x\n", hv.bq4);
            break;

        default:
            /*printf(FUNCTION "() Skipped header %02x\n", hi);*/
            printf(" Skipped header %02x\n", hi);
        }
    }

    nooverwrite = TargetExist(name);
    if (nooverwrite == 0) {
        printf("A file named %s already exists in %s - I will not overwrite it.", name, rcvDir);
    } else {
        if (!body) {
            printf("Got a PUT without a body\n");
            return;
        }
        if (!name) {
            printf("Got a PUT without a name. Setting name to %s\n", name);
            name = "OBEX PUT Unknown object";
        }
        SaveSafely(name, body, bodylen);
    }
    free(namebuf);
}

void
ServerRequest(obex_object_t* object, int event, int cmd)
{
    switch (cmd) {
    case OBEX_CMD_SETPATH:
        printf("Received SETPATH command\n");
        OBEX_ObjectSetRsp(object, OBEX_RSP_CONTINUE, OBEX_RSP_SUCCESS);
        break;

    case OBEX_CMD_PUT:
        OBEX_ObjectSetRsp(object, OBEX_RSP_CONTINUE, OBEX_RSP_SUCCESS);
        PutDone(object);
        break;

    case OBEX_CMD_CONNECT:
        OBEX_ObjectSetRsp(object, OBEX_RSP_SUCCESS, OBEX_RSP_SUCCESS);
        break;

    case OBEX_CMD_DISCONNECT:
        OBEX_ObjectSetRsp(object, OBEX_RSP_SUCCESS, OBEX_RSP_SUCCESS);
        break;

    default:
        /* printf(FUNCTION "() Denied %02x request\n", cmd); */
        printf(" Denied %02x request\n", cmd);
        OBEX_ObjectSetRsp(object, OBEX_RSP_NOT_IMPLEMENTED, OBEX_RSP_NOT_IMPLEMENTED);
        break;
    }
    return;
}

void
SetSrvDone(obex_object_t* object, int obexcmd)
{
    if (obexcmd == OBEX_CMD_DISCONNECT)
        receivingFinished = TRUE;
}

void
SetClientDone(obex_object_t* object, int obexcmd, int obexrsp)
{
    lastSendRsp = obexrsp;
    sendingFinished = TRUE;
}

void
ObexEvent(obex_t* handle, obex_object_t *object, int mode, int
           event, int obexcmd, int obexrsp)
{
    switch (event)        {
    case OBEX_EV_PROGRESS:
        printf(".");
        break;

    case OBEX_EV_REQDONE:
        printf("\n");
        if (mode == OBEX_MODE_CLIENT)
            SetClientDone(object, obexcmd, obexrsp);
        else
            SetSrvDone(object, obexcmd);
        break;

    case OBEX_EV_REQHINT:
        /* Comes BEFORE the lib parses anything. */
        switch (obexcmd) {
        case OBEX_CMD_PUT:
        case OBEX_CMD_CONNECT:
        case OBEX_CMD_DISCONNECT:
            OBEX_ObjectSetRsp(object, OBEX_RSP_CONTINUE, OBEX_RSP_SUCCESS);
            break;

        default:
            OBEX_ObjectSetRsp(object, OBEX_RSP_NOT_IMPLEMENTED, OBEX_RSP_NOT_IMPLEMENTED);
            break;
        }
        break;

    case OBEX_EV_REQ:
        ServerRequest(object, event, obexcmd);
        break;

    case OBEX_EV_LINKERR:
        printf("Link broken (this does not have to be an error)!\n");
        if (mode == OBEX_MODE_CLIENT)
            sendingFinished = 1;
        else
            receivingFinished = 1;
        break;

    default:
        printf("Unknown event...\n");
        break;
    }
}

int
WaitRsp(void)
{
    int ret;

    while (!sendingFinished) {
        ret = OBEX_HandleInput(handleSend, 10);
        if (ret < 0)
            return ret;
    }
    return lastSendRsp;
}

int
RequestSync(obex_t* handle, obex_object_t* object, int async)
{
    int ret;
    OBEX_Request(handle, object);
    ret = WaitRsp();
    sendingFinished = FALSE;
    return ret;
}

int
GetFileSize(const char* filename)
{
    struct stat stats;
    stat(filename, &stats);
    return (int)stats.st_size;
}

uint8_t*
ReadEasily(const char* filename, int* filesize)
{
    int actual;
    int fd;
    uint8_t* buf;

    *filesize = GetFileSize(filename);
    printf("OBEX: name=%s, size=%d\n", filename, *filesize);

    fd = open(filename, O_RDONLY, 0);
    if (fd == -1) {
        return NULL;
    }

    if ( !(buf = malloc(*filesize)) ) {
        return NULL;
    }

    actual = read(fd, buf, *filesize);
    close(fd);
    *filesize = actual;
    return buf;
}

obex_object_t*
BuildObjFromFile(obex_t* handle, const char* filename)
{
    obex_headerdata_t hdd;
    uint8_t unicodebuf[200];
    int namebuflen;
    obex_object_t *object;
    uint32_t creatorid = MEMO_PAD;
    int filesize;
    char* name = NULL;
    uint8_t* buf;

    buf = ReadEasily(filename, &filesize);
    if (buf == NULL)
        return NULL;

    creatorid = MEMO_PAD;
    name = strchr(filename, '.');
    if (name) {
        name++;
        if (strcmp(name, "vcf") == 0) {
            printf( "This is a Address Book file\n");
            creatorid = ADDRESS_BOOK;
        } else if (strcmp(name, "vcs") == 0) {
            printf( "This is a Date Book file\n");
            creatorid = DATE_BOOK;
        } else if (strcmp(name, "txt") == 0) {
            printf("This is a Memo pad file\n");
            creatorid = MEMO_PAD;
        } else if (strcmp(name, "prc") == 0) {
            printf("This is a Pilot resource file\n");
            creatorid = PILOT_RESOURCE;
        }
    }

    object = OBEX_ObjectNew(handle, OBEX_CMD_PUT);
    // makhtar
    //namebuflen = OBEX_CharToUnicode(unicodebuf, (const uint8_t *)filename, sizeof(unicodebuf));
    strcpy(unicodebuf, filename);
    namebuflen = sizeof(unicodebuf);

    hdd.bs = unicodebuf;
    OBEX_ObjectAddHeader(handle, object, OBEX_HDR_NAME, hdd, namebuflen, 0);

    hdd.bq4 = filesize;
    OBEX_ObjectAddHeader(handle, object, OBEX_HDR_LENGTH, hdd, sizeof(uint32_t), 0);

    if (obexProtocolType != 1) {
        hdd.bq4 = creatorid;
        OBEX_ObjectAddHeader(handle, object, HEADER_CREATOR_ID, hdd, sizeof(uint32_t), 0);
    }

    hdd.bs = buf;
    OBEX_ObjectAddHeader(handle, object, OBEX_HDR_BODY, hdd, filesize, 0);
    free(buf);
    return object;
}


int
SaveSafely(char* name, const uint8_t* buf, int len)
{
    /*         char *s = name; */
    /*     char filename[255] = {0,}; */
    char* filename;
    int fd;
    int actual = 0;
    /*     unsigned int filesize = sizeof(name); */
    /*     char* fileReceived = name; */

    printf("OBEX: Filename = %s\n", name);
    filename = strrchr(name, '/');
    if (filename == NULL)
        filename = name;
    else filename++;

    /*     strncat(filename, s, 250); */
    /*     strncat(filename, name, 254); */
    /*     strncat(fileReceived, name, 254); */

    fd = open(filename, O_RDWR | O_CREAT, DEFFILEMODE);

    if ( fd < 0) {
        perror(filename);
        return EXIT_FAILURE;
    }

    actual = write(fd, buf, len);
    close(fd);
    printf( "OBEX: Wrote %s (%d bytes)\n", filename, actual);
    /*     strncpy(fileReceived, "\0", 254); */
    /*     strncat(fileReceived, filename, 254); */

    return actual;
}

int
Send(char* fileName)
{
    obex_object_t* object;
    int ret, exitval = 0;

    handleSend = OBEX_Init(OBEX_TRANS_IRDA, ObexEvent, 0);
    ret = IrOBEX_TransportConnect(handleSend, "OBEX");
    if (ret < 0) {
        printf("OBEX: Sorry, unable to connect! - Stage 1 -\n");
        return 1;
    }

    object = OBEX_ObjectNew(handleSend, OBEX_CMD_CONNECT);
    ret = RequestSync(handleSend, object, FALSE);
    if ((lastSendRsp != OBEX_RSP_SUCCESS) || (ret < 0)) {
        printf("OBEX: Sorry, unable to connect! - Stage 2 -\n");
        return 1;
    }

    if ((object = BuildObjFromFile(handleSend, fileName ))) {
        ret = RequestSync(handleSend, object, FALSE);
        if ((lastSendRsp != OBEX_RSP_SUCCESS) || (ret < 0))
            exitval = 1;
    } else
        exitval = 1;

    object = OBEX_ObjectNew(handleSend, OBEX_CMD_DISCONNECT);
    ret = RequestSync(handleSend, object, FALSE);

    if ((lastSendRsp != OBEX_RSP_SUCCESS) || (ret < 0))
        exitval = 1;

    if (exitval == 0)
        printf("OBEX: PUT successful\n");
    else
        printf("OBEX: PUT failed\n");

    return exitval;
}

int
Rcv(void)
{
/*     obex_object_t* object; */
    handleRcv = OBEX_Init(OBEX_TRANS_IRDA, ObexEvent, 0);
    IrOBEX_ServerRegister(handleRcv, "OBEX");

    while (!receivingFinished)
        OBEX_HandleInput(handleRcv, 1);

    receivingFinished = 0;
    return 0;
}

/* Overwritting checker */
int
TargetExist(char* name)
{
    struct stat targetstat;
    int exists = -1;

    chdir(rcvDir);
    exists = stat(name, &targetstat);
    return exists;
}

/* $Id: irobex.c 41 2007-05-07 16:41:25Z makhtar $ */
