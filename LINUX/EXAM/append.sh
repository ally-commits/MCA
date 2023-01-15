read -p "Enter a filename" file

if [ -w $file ]
then
	echo "NEW CONTENT" | cat >> $file
	echo "FILE CONTENTS:"
	cat $file
else
	echo "No write access"
fi
