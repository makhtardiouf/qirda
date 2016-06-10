/*****************************************************************
 * $Id: main.cpp 45 2007-06-24 20:59:25Z makhtar $
 * Copyright (C) 2007-2016 Makhtar Diouf
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
#include <QtCore/QTextCodec>


void
Present(void)
{
    std::cerr<< "\n" << APP_DEFINITION << "\nVersion: " << APP_VERSION
    << "\nBy " << AUTHOR << "\n\n";
}

int
main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Q_INIT_RESOURCE(qirda);
    rcvDir = ".qirdabox";

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8")); //  setCodecForTr
    QTranslator translator;

    /** FIX THIS: Potential segfault if the translation file can not be found.
        Should provide an alternative location, i.e. the build directory
    */
    translator.load(QString("/usr/local/share/qirda/tr_qirda_fr"));

    if (argv[1] != NULL) {
        if ( (strcmp(argv[1], "-h") == 0)
                || (strcmp(argv[1], "--help") == 0) ) {
            Present();

            // We use ' QObject::tr' for translation purpose
            qDebug()<< QObject::tr("-h, --help display available options\n")
            <<  QObject::tr("-V, --version display version information\n")
            << QObject::tr("--lang=fr bring up the interface with the french translation\n");
            return EXIT_SUCCESS;

        } else if ( (strcmp(argv[1], "-V") == 0)
                    || (strcmp(argv[1], "--version") == 0) ) {
            Present();
            return EXIT_SUCCESS;

        } else if ( strcmp(argv[1], "--lang=fr") == 0 ) {
            app.installTranslator(&translator);

        } else
            qDebug()<< QObject::tr("Unrecognized option: ") << argv[1] << "\n";
    }

    QDir workingDir;
    workingDir.cd(QDir::homePath());

    if ( !workingDir.exists(QString(rcvDir)) ) {
        qDebug()<< QObject::tr("Creating receive directory ") << rcvDir << "...\n";
        workingDir.mkdir(QString(rcvDir));
        chmod(rcvDir, S_IRWXU);
    }

    workingDir.cd(rcvDir);
    workingDir.setCurrent(workingDir.absolutePath());

    Qirda* qirda = new Qirda();
    qirda->show();
    return app.exec();
}
