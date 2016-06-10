/********************************************************************************
** Form generated from reading UI file 'infomsg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOMSG_H
#define UI_INFOMSG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_InfoDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *InfoMsgGroupBox;
    QGridLayout *gridLayout1;
    QTextEdit *infoMsg;

    void setupUi(QDialog *InfoDialog)
    {
        if (InfoDialog->objectName().isEmpty())
            InfoDialog->setObjectName(QStringLiteral("InfoDialog"));
        InfoDialog->setWindowModality(Qt::NonModal);
        InfoDialog->resize(293, 266);
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InfoDialog->sizePolicy().hasHeightForWidth());
        InfoDialog->setSizePolicy(sizePolicy);
        InfoDialog->setMinimumSize(QSize(100, 100));
        InfoDialog->setMaximumSize(QSize(16777215, 16777215));
        InfoDialog->setFocusPolicy(Qt::ClickFocus);
        gridLayout = new QGridLayout(InfoDialog);
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        InfoMsgGroupBox = new QGroupBox(InfoDialog);
        InfoMsgGroupBox->setObjectName(QStringLiteral("InfoMsgGroupBox"));
        gridLayout1 = new QGridLayout(InfoMsgGroupBox);
        gridLayout1->setSpacing(5);
        gridLayout1->setContentsMargins(10, 10, 10, 10);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        infoMsg = new QTextEdit(InfoMsgGroupBox);
        infoMsg->setObjectName(QStringLiteral("infoMsg"));
        infoMsg->setWindowModality(Qt::NonModal);
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(infoMsg->sizePolicy().hasHeightForWidth());
        infoMsg->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("Sans Serif"));
        font.setPointSize(14);
        infoMsg->setFont(font);
        infoMsg->setAutoFormatting(QTextEdit::AutoNone);
        infoMsg->setLineWrapMode(QTextEdit::WidgetWidth);
        infoMsg->setLineWrapColumnOrWidth(0);
        infoMsg->setReadOnly(false);
        infoMsg->setOverwriteMode(false);
        infoMsg->setTextInteractionFlags(Qt::TextEditorInteraction);

        gridLayout1->addWidget(infoMsg, 0, 0, 1, 1);


        gridLayout->addWidget(InfoMsgGroupBox, 0, 0, 1, 1);


        retranslateUi(InfoDialog);

        QMetaObject::connectSlotsByName(InfoDialog);
    } // setupUi

    void retranslateUi(QDialog *InfoDialog)
    {
        InfoMsgGroupBox->setTitle(QApplication::translate("InfoDialog", "Qirda", 0));
        infoMsg->setHtml(QApplication::translate("InfoDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:14pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SUSE Sans'; font-size:12pt;\"></p></body></html>", 0));
        Q_UNUSED(InfoDialog);
    } // retranslateUi

};

namespace Ui {
    class InfoDialog: public Ui_InfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOMSG_H
