read lower
read upper


val=$lower

while [ $val -le $upper ]
do
	echo $val
	val=`expr $val + 1`
done
