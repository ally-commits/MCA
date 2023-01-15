echo "Enter a num:"

read a
read b

if [[ $a == $b ]]
then
	echo "Equal"
elif [[ $a > $b ]]
then
	echo A is greator $a
else
	echo B is greator $b
fi
