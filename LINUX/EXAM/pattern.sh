read -p "ENTER A NUMBER:" n

i=0;
while [ $i -le $n ]
do
	str=""
	j=`expr $n - $i`
	while [ $j -le $n ]
	do
		temp="#"
		str=$( echo ${str} ${temp} )
		j=`expr $j + 1`	
	done
	i=`expr $i + 1`
	echo $str;
done 
