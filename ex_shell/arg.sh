#!/bin/bash

echo "The name is $0."
echo "The name is `basename $0`."

echo

if [ -n "$1" ]
then 
    echo "Param #1 is $1"
else
    echo "please input args."
fi
