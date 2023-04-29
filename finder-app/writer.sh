#!/bin/bash


if [ $# -ne 2 ]; then
	echo "Missing Parameters"
	exit 1
elif [ $# -lt 1 ]; then
	echo "Missing Parameters"
	exit 1
else 
	 DIR="$(dirname "${1}")" 
if [ -d "$DIR" ]; then
	 	touch $1
else 
	mkdir -p $DIR
	touch $1
fi
	
	echo "$2" >> $1
fi