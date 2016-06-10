/********************************************************************************
** Form generated from reading UI file 'qirda.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIRDA_H
#define UI_QIRDA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QirdaWindow
{
public:
    QAction *actAbout;
    QAction *actSelectRcvDir;
    QAction *actQuit;
    QAction *actDetect;
    QAction *actEnglish;
    QAction *actFrench;
    QAction *actHelp;
    QAction *actEnableTrayIcon;
    QAction *actDisableTrayIcon;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *vboxLayout;
    QLabel *labelDiagnos;
    QFrame *line_2;
    QHBoxLayout *hboxLayout;
    QTextEdit *debuggingBox;
    QVBoxLayout *vboxLayout1;
    QCheckBox *rcvBt;
    QCheckBox *verbBt;
    QPushButton *clearDiagnosticsBt;
    QProgressBar *progressBar;
    QVBoxLayout *vboxLayout2;
    QLabel *labelFiles2Send;
    QFrame *line_3;
    QHBoxLayout *hboxLayout1;
    QTextEdit *inFilesBox;
    QVBoxLayout *vboxLayout3;
    QPushButton *addFileBt;
    QPushButton *sendBt;
    QPushButton *clearBt;
    QMenuBar *menuBar;
    QMenu *menuInfo;
    QMenu *menuControl;
    QMenu *menuLang;
    QMenu *menuSysTrayIcon;
    QStatusBar *statBar;

    void setupUi(QMainWindow *QirdaWindow)
    {
        if (QirdaWindow->objectName().isEmpty())
            QirdaWindow->setObjectName(QStringLiteral("QirdaWindow"));
        QirdaWindow->resize(454, 453);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QirdaWindow->sizePolicy().hasHeightForWidth());
        QirdaWindow->setSizePolicy(sizePolicy);
        QirdaWindow->setMinimumSize(QSize(100, 100));
        QirdaWindow->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral("img/qirdaLogo-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        QirdaWindow->setWindowIcon(icon);
        actAbout = new QAction(QirdaWindow);
        actAbout->setObjectName(QStringLiteral("actAbout"));
        actSelectRcvDir = new QAction(QirdaWindow);
        actSelectRcvDir->setObjectName(QStringLiteral("actSelectRcvDir"));
        actQuit = new QAction(QirdaWindow);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        actDetect = new QAction(QirdaWindow);
        actDetect->setObjectName(QStringLiteral("actDetect"));
        actEnglish = new QAction(QirdaWindow);
        actEnglish->setObjectName(QStringLiteral("actEnglish"));
        actFrench = new QAction(QirdaWindow);
        actFrench->setObjectName(QStringLiteral("actFrench"));
        actHelp = new QAction(QirdaWindow);
        actHelp->setObjectName(QStringLiteral("actHelp"));
        actEnableTrayIcon = new QAction(QirdaWindow);
        actEnableTrayIcon->setObjectName(QStringLiteral("actEnableTrayIcon"));
        actDisableTrayIcon = new QAction(QirdaWindow);
        actDisableTrayIcon->setObjectName(QStringLiteral("actDisableTrayIcon"));
        centralwidget = new QWidget(QirdaWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(9, 9, 9, 9);
        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        labelDiagnos = new QLabel(centralwidget);
        labelDiagnos->setObjectName(QStringLiteral("labelDiagnos"));

        vboxLayout->addWidget(labelDiagnos);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line_2);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        debuggingBox = new QTextEdit(centralwidget);
        debuggingBox->setObjectName(QStringLiteral("debuggingBox"));
        QFont font;
        font.setFamily(QStringLiteral("Sans Serif"));
        font.setPointSize(13);
        debuggingBox->setFont(font);
        debuggingBox->setUndoRedoEnabled(false);
        debuggingBox->setReadOnly(true);
        debuggingBox->setAcceptRichText(false);

        hboxLayout->addWidget(debuggingBox);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        rcvBt = new QCheckBox(centralwidget);
        rcvBt->setObjectName(QStringLiteral("rcvBt"));
        QFont font1;
        font1.setBold(false);
        font1.setUnderline(true);
        font1.setWeight(50);
        rcvBt->setFont(font1);

        vboxLayout1->addWidget(rcvBt);

        verbBt = new QCheckBox(centralwidget);
        verbBt->setObjectName(QStringLiteral("verbBt"));
        QFont font2;
        font2.setBold(false);
        font2.setUnderline(true);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        verbBt->setFont(font2);

        vboxLayout1->addWidget(verbBt);

        clearDiagnosticsBt = new QPushButton(centralwidget);
        clearDiagnosticsBt->setObjectName(QStringLiteral("clearDiagnosticsBt"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(clearDiagnosticsBt->sizePolicy().hasHeightForWidth());
        clearDiagnosticsBt->setSizePolicy(sizePolicy1);

        vboxLayout1->addWidget(clearDiagnosticsBt);


        hboxLayout->addLayout(vboxLayout1);


        vboxLayout->addLayout(hboxLayout);


        gridLayout->addLayout(vboxLayout, 1, 0, 1, 1);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy2);
        progressBar->setMinimumSize(QSize(100, 25));
        progressBar->setMaximumSize(QSize(16777215, 25));
        progressBar->setValue(0);
        progressBar->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(progressBar, 2, 0, 1, 1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        labelFiles2Send = new QLabel(centralwidget);
        labelFiles2Send->setObjectName(QStringLiteral("labelFiles2Send"));

        vboxLayout2->addWidget(labelFiles2Send);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        vboxLayout2->addWidget(line_3);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        inFilesBox = new QTextEdit(centralwidget);
        inFilesBox->setObjectName(QStringLiteral("inFilesBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(inFilesBox->sizePolicy().hasHeightForWidth());
        inFilesBox->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setFamily(QStringLiteral("Sans Serif"));
        font3.setPointSize(13);
        font3.setKerning(true);
        font3.setStyleStrategy(QFont::PreferDefault);
        inFilesBox->setFont(font3);
        inFilesBox->setReadOnly(true);
        inFilesBox->setAcceptRichText(false);

        hboxLayout1->addWidget(inFilesBox);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(6);
        vboxLayout3->setObjectName(QStringLiteral("vboxLayout3"));
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
        addFileBt = new QPushButton(centralwidget);
        addFileBt->setObjectName(QStringLiteral("addFileBt"));
        sizePolicy1.setHeightForWidth(addFileBt->sizePolicy().hasHeightForWidth());
        addFileBt->setSizePolicy(sizePolicy1);

        vboxLayout3->addWidget(addFileBt);

        sendBt = new QPushButton(centralwidget);
        sendBt->setObjectName(QStringLiteral("sendBt"));

        vboxLayout3->addWidget(sendBt);

        clearBt = new QPushButton(centralwidget);
        clearBt->setObjectName(QStringLiteral("clearBt"));

        vboxLayout3->addWidget(clearBt);


        hboxLayout1->addLayout(vboxLayout3);


        vboxLayout2->addLayout(hboxLayout1);


        gridLayout->addLayout(vboxLayout2, 0, 0, 1, 1);

        QirdaWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(QirdaWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 454, 23));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QStringLiteral("menuInfo"));
        menuControl = new QMenu(menuBar);
        menuControl->setObjectName(QStringLiteral("menuControl"));
        menuLang = new QMenu(menuControl);
        menuLang->setObjectName(QStringLiteral("menuLang"));
        menuSysTrayIcon = new QMenu(menuControl);
        menuSysTrayIcon->setObjectName(QStringLiteral("menuSysTrayIcon"));
        QirdaWindow->setMenuBar(menuBar);
        statBar = new QStatusBar(QirdaWindow);
        statBar->setObjectName(QStringLiteral("statBar"));
        QirdaWindow->setStatusBar(statBar);

        menuBar->addAction(menuControl->menuAction());
        menuBar->addAction(menuInfo->menuAction());
        menuInfo->addAction(actAbout);
        menuInfo->addAction(actHelp);
        menuControl->addAction(actSelectRcvDir);
        menuControl->addAction(menuLang->menuAction());
        menuControl->addSeparator();
        menuControl->addAction(menuSysTrayIcon->menuAction());
        menuControl->addAction(actDetect);
        menuControl->addSeparator();
        menuControl->addAction(actQuit);
        menuLang->addAction(actEnglish);
        menuLang->addAction(actFrench);
        menuSysTrayIcon->addAction(actEnableTrayIcon);
        menuSysTrayIcon->addAction(actDisableTrayIcon);

        retranslateUi(QirdaWindow);
        QObject::connect(clearDiagnosticsBt, SIGNAL(clicked()), debuggingBox, SLOT(clear()));

        QMetaObject::connectSlotsByName(QirdaWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QirdaWindow)
    {
        QirdaWindow->setWindowTitle(QApplication::translate("QirdaWindow", "Qirda - Infrared data exchanger", 0));
        actAbout->setText(QApplication::translate("QirdaWindow", "A&bout Qirda", 0));
        actSelectRcvDir->setText(QApplication::translate("QirdaWindow", "Reception &Directory...", 0));
        actSelectRcvDir->setIconText(QApplication::translate("QirdaWindow", "Reception Directory", 0));
#ifndef QT_NO_TOOLTIP
        actSelectRcvDir->setToolTip(QApplication::translate("QirdaWindow", "Reception Directory", 0));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("QirdaWindow", "&Quit", 0));
        actDetect->setText(QApplication::translate("QirdaWindow", "D&etect devices...", 0));
        actEnglish->setText(QApplication::translate("QirdaWindow", "&English", 0));
        actFrench->setText(QApplication::translate("QirdaWindow", "&Francais", 0));
        actFrench->setIconText(QApplication::translate("QirdaWindow", "Francais", 0));
#ifndef QT_NO_TOOLTIP
        actFrench->setToolTip(QApplication::translate("QirdaWindow", "Fran\303\247ais", 0));
#endif // QT_NO_TOOLTIP
        actHelp->setText(QApplication::translate("QirdaWindow", "&Help", 0));
        actEnableTrayIcon->setText(QApplication::translate("QirdaWindow", "&Enable", 0));
        actDisableTrayIcon->setText(QApplication::translate("QirdaWindow", "Disa&ble", 0));
        labelDiagnos->setText(QString());
        rcvBt->setText(QApplication::translate("QirdaWindow", "Receive", 0));
        verbBt->setText(QApplication::translate("QirdaWindow", "Verbose", 0));
        clearDiagnosticsBt->setText(QApplication::translate("QirdaWindow", "Cl&ear", 0));
        labelFiles2Send->setText(QString());
        inFilesBox->setHtml(QApplication::translate("QirdaWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SUSE Serif'; font-size:12pt;\"><br /></p></body></html>", 0));
        addFileBt->setText(QApplication::translate("QirdaWindow", "&Add Files", 0));
        sendBt->setText(QApplication::translate("QirdaWindow", "&Send", 0));
        clearBt->setText(QApplication::translate("QirdaWindow", "C&lear", 0));
        menuInfo->setTitle(QApplication::translate("QirdaWindow", "&Info", 0));
        menuControl->setTitle(QApplication::translate("QirdaWindow", "&Control", 0));
        menuLang->setTitle(QApplication::translate("QirdaWindow", "&Language", 0));
        menuSysTrayIcon->setTitle(QApplication::translate("QirdaWindow", "System Tray &Icon", 0));
    } // retranslateUi

};

namespace Ui {
    class QirdaWindow: public Ui_QirdaWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIRDA_H
