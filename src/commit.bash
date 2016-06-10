#!/bin/bash --debugger
# $Id: commit.bash 44 2007-05-22 07:26:54Z makhtar $
# Commit changes of Qirda related files
QIRDA_ROOT_PATH=$HOME/Documents/Dev/DevEmd/Cteam/Qirda/trunk
QIRDA_SRC_DIR=$QIRDA_ROOT_PATH/src
QIRDA_DOCS_DIR=$QIRDA_ROOT_PATH/docs
COMMENTS=$QIRDA_DOCS_DIR/commitmsg.txt

{
    for i in $QIRDA_DOCS_DIR/*.* $QIRDA_SRC_DIR/*.{h,hpp,cpp} \
	$QIRDA_SRC_DIR/qirdasend/*.cpp $QIRDA_SRC_DIR/qirdarcv/*.cpp
      do
      SetId.bash $i
    done

    bash $QIRDA_SRC_DIR/beautify.bash

    cd $QIRDA_ROOT_PATH

    if [ "$1" == "++" ]; then
	svn commit -m "++"
    elif [ "$1" == "txt" ]; then
	echo "Using \"$COMMENTS\" as commit documentation..."
	svn commit -F $COMMENTS
    else
	echo "Usage: `basename $0` ++ OR `basename $0` txt"
    fi
} | tee commit.log

exit
