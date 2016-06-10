/********************************************************************************
** Form generated from reading UI file 'rcvdir.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RCVDIR_H
#define UI_RCVDIR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_rcvDirDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QLineEdit *rcvDirWidget;

    void setupUi(QDialog *rcvDirDialog)
    {
        if (rcvDirDialog->objectName().isEmpty())
            rcvDirDialog->setObjectName(QStringLiteral("rcvDirDialog"));
        rcvDirDialog->resize(374, 82);
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rcvDirDialog->sizePolicy().hasHeightForWidth());
        rcvDirDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(rcvDirDialog);
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(rcvDirDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        label = new QLabel(rcvDirDialog);
        label->setObjectName(QStringLiteral("label"));

        hboxLayout->addWidget(label);

        rcvDirWidget = new QLineEdit(rcvDirDialog);
        rcvDirWidget->setObjectName(QStringLiteral("rcvDirWidget"));

        hboxLayout->addWidget(rcvDirWidget);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);


        retranslateUi(rcvDirDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), rcvDirDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), rcvDirDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(rcvDirDialog);
    } // setupUi

    void retranslateUi(QDialog *rcvDirDialog)
    {
        rcvDirDialog->setWindowTitle(QApplication::translate("rcvDirDialog", "Qirda - Select receiving directory", 0));
        label->setText(QApplication::translate("rcvDirDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SUSE Sans'; font-size:12pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Directory</span>:</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class rcvDirDialog: public Ui_rcvDirDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RCVDIR_H
