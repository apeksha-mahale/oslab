#Zero arguments error
if [ $# -eq 0 ]
	then
	echo "Can't have zero arguments!"
else
	for login in $*
	do
		if grep $login /etc/passwd >/dev/null
		then
			echo "Login login: $login"
			dir=`grep $login /etc/passwd | cut -d ":" -f 6`
			echo "Home Directory: $dir"
		else
			echo "$login is not a valid login id!"
		fi
	done
fi