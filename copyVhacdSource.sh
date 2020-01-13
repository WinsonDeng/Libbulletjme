#!/bin/bash

# Copy V-HACD source files used by Libbulletjme
# from the SRC directory to the DST directory.

SRC=/home/sgold/Git/ext/v-hacd/src/VHACD_Lib
DST=/home/sgold/Git/Libbulletjme/src/native/v-hacd

cd $SRC
cp --recursive inc public src $DST

cd $DST
find . -name 'bt*' -exec rm {} \;

git status --short

cd $SRC
pwd
git log -1 --format="updated V-HACD source to SHA1 ID=%h"
