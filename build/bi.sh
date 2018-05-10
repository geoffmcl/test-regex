#!/bin/sh
#< bi.sh - special params
BN=`basename $0`

TMPBOOST="$HOME/projects/install/boost_1_67_0"
# TMPBOOST="/media/geoff/backup/projects/install/boost_1_61_0"
if [ ! -d "$TMPBOOST" ]; then
    echo "$BN: Can NOT locate '$TMPBOOST' - *** FIX ME ***"
    exit 1
fi

TMPOPTS="-DCMAKE_PREFIX_PATH=$TMPBOOST"

./build-me.sh $TMPOPTS $@

# eof

