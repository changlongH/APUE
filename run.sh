#!/bin/sh
nowPath=`pwd`

filePatch="$nowPath""/$1" 
if [ ! -f $filePatch ]; then
	echo "文件不存在"
	exit 1
fi

gcc $1 -o a.o

runPatch="$nowPath""/a.o"
if [ ! -x "$runPatch" ]; then
	echo "文件不存在或者无权限"
	rm a.o
	exit 1
fi

./a.o
rm a.o
