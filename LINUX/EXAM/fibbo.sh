read -p "Enter a num:" n


if [ $n -gt 0 ]
then 
	echo 0
fi

if [ $n -gt 1 ]
then
	echo 1
fi

f1=0
f2=1
i=2;
while [ $i -le $n ]
do
	temp=`expr $f1 + $f2`
	echo $temp
	f1=$f2
	f2=$temp
	i=`expr $i + 1`
done
