echo "Enter first number:"
read a1

echo "Enter second number:"
read a2

echo Numbers between $a1 and $a2 are:
product=1
a1val=`expr $a1 + 1`
a1=$a1val

until [ ! $a1 -lt $a2 ]
do
        echo $a1
        a1=`expr $a1 + 1`
done


while [ $a1val -lt $a2 ]
do
        product=`expr $product \* $a1val`
        a1val=`expr $a1val + 1`
done

echo "Product:" $product

num=$product
rev=0
while [ $num -gt 0 ]
do
    s=`expr $num % 10`  
      
    num=`expr $num / 10`  
      
    rev=`expr $rev \* 10 + $s` 
done

if [ $product -eq $rev ]
then
	echo "Palindrome"
else
	echo "Not Palindrome"
fi
