#Zero arguments error
if [ $# -eq 0 ]
	then
	echo "Can't have zero arguments!"
	exit
#While parameters don't become zero, get the input and shift it
else
	while [ $# -gt 0 ]
	do
	  rev="$1 $rev"
	  shift
	done
	echo $rev
fi