ROOT_UID=0
E_NOTROOT=67

if [ "$UID" -ne "$ROOT_UID" ]
then
    echo "Must be root to run this script."
    exit $E_NOTROOT
else
    echo "This is root run."
fi
