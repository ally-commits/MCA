for file in *
do
	if [[ $file == *.sh ]] || [[ $file == one.* ]]
	then
		echo $file
	fi
done
