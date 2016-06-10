#!/bin/bash
# $Id: install.bash 42 2007-05-17 22:22:00Z makhtar $
# Install qirda, qirdasend, qirdarcv

INSTALL_PATH=/usr/local/bin
RES_PATH=/usr/local/share/qirda

function Install()
{
    su -c "install -vs -m 755 qirda $INSTALL_PATH ;\
    install -vs qirdasend/qirdasend $INSTALL_PATH ;\
    install -vs qirdarcv/qirdarcv $INSTALL_PATH ;\
    mkdir -p $RES_PATH; install -v tr_qirda_fr.qm $RES_PATH ;\
    install -v -m 644 ../docs/qirda.1 /usr/local/man/man1"
}

{
    echo "Installing qirda in $INSTALL_PATH..."
    sleep 1
    Install
    echo "Done"
} | tee install.log

exit
