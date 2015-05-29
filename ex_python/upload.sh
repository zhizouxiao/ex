package=update.zip
ftp -n<<!
open 192.168.1.100
user yunwei yunwei
cd transfer
put $package
close
bye
!
