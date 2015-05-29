list=`ps aux| grep ga | awk '{print $2}'`
echo ${list[*]}
for i in ${list[*]}
do
    echo $i
done
