#!/bin/sh
HOST="192.168.1.100"
USER="yunwei"
PASSWD="yunwei"
FILE="update.zip"

ftp -n $HOST <<END_SCRIPT
quote USER $USER
quote PASS $PASSWD
#rename $FILE old-$FILE
cd transfer
put $FILE
quit
END_SCRIPT
exit 0
