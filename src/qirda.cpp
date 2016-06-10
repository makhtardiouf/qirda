/*****************************************************************
 * $Id: qirda.cpp 45 2007-06-24 20:59:25Z makhtar $
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
#include "qirda.hpp"
//#include <fstream>

Qirda::Qirda(QWidget* papa)
        : QMainWindow(papa)
{

    qirdaWin.setupUi(this);
    this->setWindowIcon(QIcon(QString::fromUtf8(":/img/qirdaLogo-2.png")));
    qirdaWin.statBar->setFont(QFont("courrier", -1, QFont::DemiBold));

    qirdaWin.labelFiles2Send->setText(tr("Files To Send:"));
    qirdaWin.labelDiagnos->setText(tr("Execution State:"));
    qirdaWin.actFrench->setText(QString::fromUtf8("Français"));

    sysTrayMenu = new QMenu(APP_NAME);
    actEnableRcv = new QAction (tr("&Toggle Receive mode"), sysTrayMenu);
    actRestore = new QAction(tr("&Restore"), sysTrayMenu);
    actQuit = new QAction(tr("&Quit"), sysTrayMenu);

    sysTrayMenu->addAction(actEnableRcv);
    sysTrayMenu->addAction(actRestore);
    sysTrayMenu->addAction(actQuit);

    sysTrayIcon = new QSystemTrayIcon(QIcon(QString::
                                        fromUtf8(":/img/qirdaLogo-2.png")));

    sysTrayIcon->setContextMenu(sysTrayMenu);
    sysTrayIcon->setToolTip(tr("Qirda"));

    qirdaWin.actDetect->setDisabled(true);

//     qirdaSender = new QProcess();
    qirdaReceiver = new QProcess();

    QObject::connect(qirdaWin.actSelectRcvDir, SIGNAL(triggered()),
                     this, SLOT(SelectRcvDir()));

    QObject::connect(qirdaWin.actEnglish, SIGNAL(triggered()),
                     this, SLOT(ResetLocaleLang()));

    QObject::connect(qirdaWin.actFrench, SIGNAL(triggered()),
                     this, SLOT(SetLocaleLang()));

    QObject::connect(qirdaWin.actEnableTrayIcon, SIGNAL(triggered()),
                     sysTrayIcon, SLOT(show()));

    QObject::connect(qirdaWin.actDisableTrayIcon, SIGNAL(triggered()),
                     sysTrayIcon, SLOT(hide()));

    QObject::connect(qirdaWin.actQuit, SIGNAL(triggered()),
                     this, SLOT(QuitNicely()));

//     QObject::connect(qirdaWin.actDetect, SIGNAL(triggered()),
//                      this, SLOT(DetectDevices()));

    QObject::connect(actEnableRcv, SIGNAL(triggered()),
                     this, SLOT(ToggleReceiving()));

    QObject::connect(actRestore, SIGNAL(triggered()),
                     this, SLOT(show()));

    QObject::connect(actQuit, SIGNAL(triggered()),
                     this, SLOT(QuitNicely()));

    QObject::connect(qirdaWin.actAbout, SIGNAL(triggered()),
                     this, SLOT(TellAbout()));

    QObject::connect(qirdaWin.addFileBt, SIGNAL(clicked()),
                     this, SLOT(AddFiles()));

    QObject::connect(qirdaWin.sendBt, SIGNAL(clicked()),
                     this, SLOT(StartSending()));

    QObject::connect(qirdaWin.clearBt, SIGNAL(clicked()),
                     this, SLOT(ClearSelectedFiles()));

    QObject::connect(qirdaWin.rcvBt, SIGNAL(clicked()),
                     this, SLOT(ToggleReceiving()));

    //    sysTrayIcon->show();
    ShowStatMsg(tr("Ready"));
}

void
Qirda::AddFiles(void)
{
    QStringList tmpFilesToSend = QFileDialog::
                                 getOpenFileNames(this, tr("Select files"),
                                                  "", tr(FILETYPES));

    int tmpNumOfFiles = tmpFilesToSend.count();
    NumOfFiles = filesToSend.count();
    int isPreSelected = -1;
    QString files[2];

    for (int i = 0; i < tmpNumOfFiles; ++i) {
        files[0] = GetFileName(tmpFilesToSend, i);

        for (int j = 0; j < NumOfFiles; ++j) {

            files[1] = GetFileName(filesToSend, j);
            isPreSelected = QString::compare(files[0], files[1]);

            if (isPreSelected == 0) {
                filesToSend.removeAt(j);
                NumOfFiles = filesToSend.count();
            }
        }
    }

    filesToSend += tmpFilesToSend;
    filesToSend.sort();
    NumOfFiles = filesToSend.count();
    qirdaWin.inFilesBox->clear();

    for (int k = 0; k < NumOfFiles; ++k) {
        qirdaWin.inFilesBox->append(GetFileName(filesToSend, k));
    }
}

void
Qirda::ClearSelectedFiles(void)
{
    NumOfFiles = filesToSend.count();

    for (int i = 0; i < NumOfFiles; ++i) {
        filesToSend.removeAt(i);
    }
    qirdaWin.inFilesBox->clear();
    qirdaWin.progressBar->setValue(0);
    ShowStatMsg(tr("Ready"));
}

// @TODO: complete this
void
Qirda::DetectDevices(void)
{
    // Suspend the GUI and go to command line mode
    // after finishing detection, bring up the GUI again
    printf("Detecting infrared devices...\n");

    pid_t detecterPid = vfork();
    if (detecterPid == 0) {
        char* const suArgs[] = {"su", "-c", "irdadump -d", NULL
                               };
        execv("su", suArgs);
        //  devDetecter = new QProcess();
        //  QString exeDump;
        //  exeDump.appendtr(tr("su -c \"irdadump -d\"");
        //  devDetecter->start(exeDump);
    }
}

void
Qirda::SelectRcvDir(void)
{
    QDialog* dialog = new QDialog(this);
    rcvDirPopUp.setupUi(dialog);

    newRcvDir = QFileDialog::getExistingDirectory(this, tr("Select a \
                directory"));

    if (!newRcvDir.isEmpty()) {
        rcvDirPopUp.rcvDirWidget->setText(newRcvDir);
        dialog->show();
        rcvDir = strdup(newRcvDir.toStdString().c_str());
        ShowStatMsg(QString(tr("Received files will be stored in "))
                    .append(newRcvDir));

        workingDir.cd(rcvDir);
        workingDir.setCurrent(workingDir.absolutePath());
        qirdaReceiver->terminate();
        qirdaWin.rcvBt->setCheckState(Qt::Unchecked);
    }
}

void
Qirda::ShowDebugData(QProcess* process)
{
    QByteArray debugData;

    while (process->waitForReadyRead()) {
        debugData += process->readAllStandardOutput();
//        qirdaWin.progressBar->setValue(debugData.count());

        if (!debugData.isEmpty()) {
            qirdaWin.debuggingBox->append(QString(debugData).remove("\n\n"));
            qirdaWin.debuggingBox->update();
        }
    }
}

/* FIX THIS: it's the data size itself we need, not the string length */
void
Qirda::Progress(int i)
{
    // [TEMP] A little virtual progression state display
    double progressionRate = (double)((i * 100) / NumOfFiles);
    qirdaWin.progressBar->setValue((int)progressionRate);
    qirdaWin.progressBar->update();
    std::cerr<< "Progression rate: " << progressionRate << "\n";
}

void
Qirda::QuitNicely(void)
{
    /*     if ( (qirdaSender != NULL) && (qirdaSender->state() !=
      QProcess::NotRunning) )
      qirdaSender->terminate(); */

    if ( (qirdaReceiver != NULL) && (qirdaReceiver->state() !=
                                     QProcess::NotRunning) )
        qirdaReceiver->terminate();
    qApp->quit();
}

void
Qirda::ResetLocaleLang(void)
{
    int response = QMessageBox::question(this, tr("Switching interface language"),
                                         tr("Restart Qirda with the english interface language?"),
                                         QMessageBox::Yes, QMessageBox::No);

    if (response == QMessageBox::Yes) {
        this->hide();
        QProcess* clone = new QProcess();
        if (clone->state() != QProcess::Running)
            clone->start("qirda", QStringList(""));


        this->close();
        //QCoreApplication::removeTranslator(translator);
    }
}

void
Qirda::Send(void)
{
    using namespace std;
    enum { STREAMSIZE = 1024 };
    FILE* proc = NULL;
    NumOfFiles = filesToSend.count();

    for (int i = 0; i < NumOfFiles; ++i) {
        string cmd = "qirdasend ";
        const char* fileName = QString(GetFileName(filesToSend, i))
                               .toStdString().c_str();
        cmd.append(fileName);
        cmd.append(" &");

        proc = popen(cmd.c_str(), "r");
        if (proc == NULL) {
            ShowDebugMsg(tr("[FATAL] Could not run the qirdasend program"));
            QApplication::restoreOverrideCursor();

            QMessageBox::critical(this, tr("Qirda Send Failure"),
                                  QString(tr("Check if qirdasend is \
                                             executable\n"))
                                  .append(tr("Check if the IRDA service \
                                             is running")));
            perror("qirdasend");
        } else {
            QString stdoutData;
            char S[STREAMSIZE];
            // int fileSize = get_filesize(fileName);

            ShowStatMsg(tr("Busy... please wait"));
            while (true) {
                stdoutData += fgets(S, STREAMSIZE, proc);
                Progress(i+1);
                ShowDebugMsg(stdoutData);
                stdoutData = QString("");
                if (feof(proc) != 0)
                    break;
            }
            pclose(proc);
        // filesToSend.removeAt(i);
        }
    }
}

void
Qirda::StartSending(void)
{
    if (qirdaWin.inFilesBox->toPlainText().isEmpty()
            || filesToSend.isEmpty()) {
        //qirdaWin.inFilesBox->clear();
        ShowStatMsg(tr("Add a file to send, then try again"));
    } else {
        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        ShowStatMsg(tr("Busy... please wait"));
        Send();
        ShowStatMsg(tr("Ready"));
    }
    QApplication::restoreOverrideCursor();
}

void
Qirda::SetLocaleLang(void)
{
    int response = QMessageBox::question(this,
                                         tr("Switching interface language"),
                                         tr("Restart Qirda with the french interface language?"),
                                         QMessageBox::Yes, QMessageBox::No);

    if (response == QMessageBox::Yes) {
        this->hide();
        QProcess* clone = new QProcess();
        if (clone->state() != QProcess::Running)
            clone->start("qirda", QStringList("--lang=fr"));

        this->close();
    }
}

void
Qirda::TellAbout(void)
{
    static QString contents =
        QString(tr("<center><IMG SRC=\":/img/qirdaLogo-1.jpg\">\
                   <h5>Qirda<br>Infrared data exchanger<br>\
                   QIRDA_VERSION<br>Copyright (C) 2007-2016 Makhtar Diouf<br></h5>\
                   Using <b><a href=\"http://qt.io\">Qt</a> QT_VERSION</b>\
                   <br><br>Please, send suggestions and bug reports to \
                   <a href=\"mailto:makhtar.diouf@gmail.com\">\
                   makhtar.diouf@gmail.com</a><br><p>\
                   You can redistribute and/or modify this open source \
                   software under the terms of the GNU General PublicLicense \
                   version 2.<br>See the file COPYING for furtherinformation.\
                   </p><center>"));

    contents.replace(tr("QIRDA_VERSION"), APP_VERSION);
    contents.replace(tr("QT_VERSION"), QT_VERSION_STR);

    // Make it show up fast
    static QDialog* msgDialog = new QDialog(this);
    infoDialog.setupUi(msgDialog);
    infoDialog.infoMsg->setHtml(contents);
    infoDialog.infoMsg->setReadOnly(true);
    msgDialog->setWindowTitle(tr("About Qirda"));
    msgDialog->show();
}

void
Qirda::ToggleReceiving(void)
{
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    if (qirdaWin.rcvBt->checkState() == Qt::Checked) {
//        if (qirdaReceiver == NULL)
//            qirdaReceiver = new QProcess();

        if (qirdaReceiver->state() == QProcess::NotRunning) {
            qirdaReceiver->start(QString(tr("qirdarcv ")).append(rcvDir));
            qirdaReceiver->waitForStarted();
            if (qirdaReceiver->state() == QProcess::Running) {
                ShowStatMsg(tr("Reception mode activated..."));
            } else {
                ShowDebugMsg(tr("[FATAL] Could not run the qirdarcv program"));
                QApplication::restoreOverrideCursor();
                QMessageBox::critical(this, tr("Qirda Receive Failure"),
                                      QString(tr("Check if qirdarcv is \
                                                 executable\n"))
                                      .append(tr("Check if the IRDA service \
                                                 is running")));
            }
//     ShowDebugData(qirdaReceiver);
        }
    } else {
        qirdaReceiver->terminate();
        ShowStatMsg(tr("Reception mode deactivated..."));
    }
    QApplication::restoreOverrideCursor();
}

// void
// StdoutCatcher::run()
// {
//     printf(tr("StdoutCather running..."));
//     QFileSystemWatcher* debugWatcher = new QFileSystemWatcher();
//     debugWatcher->addPath(debugFile);
//     QTextStream stdoutStream(debugFile);

//     if(debugWatcher->fileChanged(DEBUG_FILE))
//     {
//  stdoutStream>> debugStr;
// // stdoutStream.flush();
//  papa->ShowDebugData();
//  printf("Caught stdout");
//     }
//     exec();
//}
