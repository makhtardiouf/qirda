/*****************************************************************
 * $Id: qirdasend.cpp 45 2007-06-24 20:59:25Z makhtar $
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
// Send files to IRDA enabled devices.
#include "irobex.h"
#include <cstdlib>
#include <iostream>
#include <unistd.h>

int main(int argc, char* argv[])
{
    using namespace std;
    int result = 1;

    if (argc < 2) {
        cerr<< "Usage: " << argv[0] << " FILE1 [FILE2]...\n";
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        clog<< "Sending " << argv[i] << "\n";
        result = Send(argv[i]);

        if ((i != (argc - 1)) && (argv[i] != NULL)) {
            clog<< "Waiting for the destination device to be ready...\n";
            sleep(3);
        }
    }
    cout<< "Done\n";
    return result;
}
