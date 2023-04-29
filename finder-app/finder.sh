#!/bin/bash

filesdir=$1
searchstr=$2

if [ $# -lt 1 ]; then
	echo "Missing Parameters"
	exit 1
fi
if [[ -d $filesdir ]]; then
fileCount=$(find "$filesdir" -type f | wc -l)
lineCount=$( grep -rc "$filesdir" -e "$searchstr" | wc -l)
echo "The number of files are " $fileCount " and the  number of matching lines are " $lineCount
else 
	echo " Invaild Directry"
	exit 1
fi