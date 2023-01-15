read -p "Enter first number" num1
read -p "Enter second number" num2

echo "LENGHT" ${#num2}
until [ ! $num1 -le $num2 ]
do
	echo $num1
	num1=`expr $num1 + 1`
done
