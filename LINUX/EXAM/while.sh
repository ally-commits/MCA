read -p "Enter First Number:" num1
read -p "Enter Second Number:" num2


while [ $num1 -le $num2 ]
do
	num1=`expr $num1 + 1`
	echo $num1;
done



