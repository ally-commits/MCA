echo "Enter a number"
a1=0
read a2

until [ ! $a1 -lt $a2 ]
do
	if [ `expr $a1 % 2` -eq 0 ]
	then
		echo $a1
	fi

	a1=`expr $a1 + 1`

done


