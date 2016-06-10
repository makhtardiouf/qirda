/*****************************************************************
 * $Id: qirdarcv.cpp 45 2007-06-24 20:59:25Z makhtar $
 * Copyright (C) 2007 Makhtar Diouf
 * elmakdi@users.sourceforge.net
 *
 * -You can redistribute and/or modify this program
 *  under the terms of the GNU General Public License version 2.
 *  See the file COPYING for further information.
 *
 * -Vous pouvez redistribuer et/ou modifier ce programme
 *  sous les termes de la license GNU General Public version 2.
 *  Voir le fichier COPYING pour plus d'information.
 ****************************************************************/
// Receive files sent from an IRDA enabled device

//#include "irobex.h"
#include "../qirda.hpp"
#include <iostream>
#include <QtCore>
#include <QtWidgets/QApplication>
/*
class QirdaReceiver : public QThread
{
//    Q_OBJECT
public:
    void run();
};

void
QirdaReceiver::run()
{
    for (;;) {
        Rcv();
    }
    exec();
}
*/

int
main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    qDebug()<< QObject::tr("Receiving...\n");

    if (argv[1] != NULL)
        rcvDir = argv[1];

    QirdaReceiver* rcv = new QirdaReceiver();
    rcv->start();
    return app.exec();
}
