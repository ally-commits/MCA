read -p "Enter variable value:" ch

case $ch in
	[A-Z]) echo "UPPERCASE";;
	[a-z]) echo "LOWERCASE";;
	[0-9]) echo "DIGIT";;
	*) echo "SPECIAL CHARACTER";;
esac
