/*****************************************************************
 * $Id: qirda.hpp 47 2007-06-24 21:32:36Z makhtar $
 * Copyright (C) 2007-2016 Makhtar Diouf
 *
 *
 * -You can redistribute and/or modify this program
 *  under the terms of the GNU General Public License version 2.
 *  See the file COPYING for further information.
 *
 * -Vous pouvez redistribuer et/ou modifier ce programme
 *  sous les termes de la license GNU General Public version 2.
 *  Voir le fichier COPYING pour plus d'information.
 ****************************************************************/

#ifndef QIRDA_HPP
#define QIRDA_HPP

#include "irobex.h"
#include "ui_infomsg.h"
#include "ui_qirda.h"
#include "ui_rcvdir.h"

extern "C" {
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
}

#include <QtCore>
#include <QtDebug>
#include <QtGlobal>
#include <QtGui>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QSystemTrayIcon>
#include <cstdio>
#include <cstring>
#include <exception>
#include <iostream>
#include <string>
#include <thread>

#define APP_NAME "Qirda"
#define APP_DEFINITION "\tQirda\nInfrared data exchanger"
#define APP_VERSION " 0.2 "__DATE__
#define AUTHOR "Makhtar Diouf"
#define FILETYPES "Files (\"*.jpg *.mid *.png *.vcf\")"


class QirdaReceiver : public QThread
{
public:
    void run(){
        for (;;) {
            // In irobex.c
            Rcv();
        }
        exec();
    }
};


/** Qirda main class<br> */
class Qirda : public QMainWindow {
  Q_OBJECT

public:
  Qirda(QWidget *papa = 0);

public slots:
  /** Select files to send; remove duplicated entries;
  sort and display candidates */
  void AddFiles(void);

  /** Show application information */
  void TellAbout(void);

  /** Remove files selected for sending */
  void ClearSelectedFiles(void);

  /** Detect infrared-enabled devices */
  void DetectDevices(void);

  /** Get selected file name */
  inline QString GetFileName(QStringList container, int i) {
    return QString(container.at(i).toLocal8Bit().constData());
  }

  /** Show progression rate */
  void Progress(int i);

  /** Terminate child threads and quit */
  void QuitNicely(void);

  /** Reset interface language to default */
  void ResetLocaleLang(void);

  /** Selecte receiving directory */
  void SelectRcvDir(void);

  /** Subrouting for @StartSending() */
  int SendFiles(void);

  void Send(void); // to be removed

  /** Set interface language to user's locale */
  void SetLocaleLang(void);

  /** Send files but blocks until all transfers are finished */
  void StartSending(void);

  void ShowDebugData(QProcess *process);

  inline void ShowDebugMsg(QString msg) {
    msg.remove("\n");
    qirdaWin.debuggingBox->append(msg);
    qirdaWin.debuggingBox->update();
  }

 inline void ShowDebugMsg(char* s) {ShowDebugMsg(QString(s));}

  inline void ShowStatMsg(QString msg) {
    qirdaWin.statBar->showMessage(msg);
    qirdaWin.statBar->update();
  }

  /** Enable or disable receiving feature */
  void ToggleReceiving(void);

private:
  Ui::QirdaWindow qirdaWin;
  Ui::InfoDialog infoDialog;
  Ui::rcvDirDialog rcvDirPopUp;

  QDir workingDir;
  QString newRcvDir;

  QSystemTrayIcon *sysTrayIcon;
  QAction *actEnableRcv;
  QAction *actRestore;
  QAction *actQuit;
  QMenu *sysTrayMenu;

  QStringList filesToSend;
  QirdaReceiver* rcvThread = nullptr;
  //    QProcess* qirdaSender;
  QProcess *qirdaReceiver;
  //    QProcess* devDetecter;
};

#endif
