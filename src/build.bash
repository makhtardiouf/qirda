#!/bin/bash
# $Id: build.bash 44 2007-05-22 07:26:54Z makhtar $
# Build qirda, qirdasend, qirdarcv

QIRDA_MANPAGE="qirda.1"

# MAINOPTS="-ansi -ggdb -funsigned-char -O2 -finline-functions -freorder-functions\
#  -static -fpic -fbounds-check -Wformat -Wextra -Wshadow -Wredundant-decls"
MAINOPTS="-ansi -ggdb -funsigned-char -finline-functions -freorder-functions\
 -fpic -fbounds-check -Wformat -Wextra -Wshadow -Wredundant-decls"


function ConfigProject()
{
    PROJ_NAME=$1
    EXTRA_LIB="-L. -lirobex -lopenobex -lusb"

    if [ ! -z $2 ]; then
	CONF_COMPL="$2"
    else
	CONF_COMPL=""
    fi

    qmake -project -o $PROJ_NAME.pro -norecursive \
        "CONFIG += qt debug warn_on " "CONFIG -= gnome glib2 $CONF_COMPL "\
	"QMAKE_CFLAGS_DEBUG += $MAINOPTS -pedantic -Wbad-function-cast \
        -Wold-style-definition -Wmissing-declarations -Wno-pointer-sign "\
	"QMAKE_CXXFLAGS_DEBUG += $MAINOPTS "\
	"LIBS = $EXTRA_LIB" "TARGET = $PROJ_NAME "\
        "MOC_DIR = .tmp " "OBJECTS_DIR = .tmp "
}

function GenLinks()
{
    if [ ! -L irobex.h ]; then
	ln -s ../3rdparty/irobex.h .
    fi

    if [ ! -L libirobex.a ]; then
	ln -s ../3rdparty/libirobex.a .
    fi
}

function Build()
{
    qmake
    make clean
    make

    if [ $? -ne 0 ]; then
	echo "Build failed";
	exit $?
    fi
}

function BuildQirda()
{
    printf "\n\n*** Building qirda...\n\n"
    if [ ! -L irobex.h ]; then
	ln -s 3rdparty/irobex.h .
    fi

    if [ ! -L libirobex.a ]; then
	ln -s 3rdparty/libirobex.a .
    fi

    ConfigProject qirda
    Build
}

function BuildDocs()
{
    printf "\nGenerating documentation...\n"

    txt2man -s 1 -v "Qirda" -t "qirda" -r "Qirda 0.1" -B txt ReadmeQirda.txt > $QIRDA_MANPAGE

    asciidoc -o qirda.html ReadmeQirda.txt
}


{
    clear

    if [ "$1" == "1" ] ; then
	BuildQirda
    else
	printf "\n\n*** Building libirobex.a ...\n\n"
	cd 3rdparty
	gcc -c -fpic *.c
	ar -rcs libirobex.a *.o
	cd -

	BuildQirda

	printf "\n\n*** Building qirdarcv ...\n\n"
	cd qirdarcv
	GenLinks
	ConfigProject qirdarcv
	Build
	cd -

	printf "\n\n*** Building qirdasend ...\n\n"
	cd qirdasend
	GenLinks
	ConfigProject qirdasend qt
	Build
	cd -
	
    fi

    lupdate -noobsolete qirda.pro
    lrelease qirda.pro
    make

    cd ../docs
    BuildDocs
    cd -

    printf "\n\n\tFinished Building. You can run ./install.bash now\n\n"

} | tee build.log

exit $?
