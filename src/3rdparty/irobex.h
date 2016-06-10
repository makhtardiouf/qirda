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

/* $Id: irobex.h 41 2007-05-07 16:41:25Z makhtar $ */
/* Portion Copyright (C) 2007 by Makhtar Diouf

   -Code from the irobex-apps project.
   Modifications are under the license specified above.
*/

#ifndef IROBEX_H
#define IROBEX_H

#include <openobex/obex.h>
#include <openobex/obex_const.h>

#define HEADER_CREATOR_ID  0xcf

#define ADDRESS_BOOK   0x61646472 /* "addr" *.vcf */
#define MEMO_PAD       0x6d656d6f /* "memo" *.txt */
#define TO_DO_LIST     0x746f646f /* "todo" *.vcs */
#define DATE_BOOK      0x64617465 /* "date" *.vcs */
#define PILOT_RESOURCE 0x6c6e6368 /* "Inch" *.prc */

#ifdef __cplusplus
extern "C"
{
#endif

    int GetFileSize(const char* filename);

    obex_object_t* BuildObjFromFile(obex_t* handle, const char* filename);

    int TargetExist(char* name);

    int SaveSafely(char* name, const uint8_t* buf, int len);

    uint8_t* ReadEasily(const char* filename, int* file_size);

    int RequestSync(obex_t* handle, obex_object_t* object, int async);

    void ObexEvent(obex_t* handle, obex_object_t* object, int mode, int event, int
                    obex_cmd, int obex_rsp);

    int WaitRsp(void);

    void SetSrvDone(obex_object_t* object, int obex_cmd);

    void SetClientDone(obex_object_t* object, int obex_cmd, int obex_rsp);

    void ServerRequest(obex_object_t* object, int event, int cmd);

    void PutDone(obex_object_t* object);

    /* static volatile int finished_receive; */

    extern char* rcvDir;
    /*  extern char* fileReceived; */

    int Rcv(void);
    int Send(char* fileName);
#ifdef  __cplusplus
}
#endif

/* hack to distinguish between different obex protocols */
extern int obexProtocolType;
#define OBEX_PROTOCOL_GENERIC             0
#define OBEX_PROTOCOL_WIN95_IRXFER        1

#endif
