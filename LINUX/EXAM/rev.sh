read -p "Enter 4 digit number:" n

len=${#n}
rev=""
temp=$n

if [ $len -eq 4 ]
then
	while [ $n -gt 0 ]
	do
		rem=`expr $n % 10`
		n=`expr $n / 10`
		
		rev=$( echo ${rev}${rem} )

	done

	echo Reverse: $rev
	if [ $rev -eq $temp ]
	then
		echo "Palindrome"
	else
		echo "Not Palindrome"
	fi
else
	echo "Enter 4 digit number"
fi
