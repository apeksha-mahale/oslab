read -p "enter a string" string
length=${#string}
for (( i = $length; i >= 0; i-- ))
do
	reverse=$reverse$(echo $string | cut -c $i)
done
echo "$reverse" 
