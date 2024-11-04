echo "Start!"
$var1=ls -l
for p in ($var1)
do
    echo "LINE: ${p}"
done
