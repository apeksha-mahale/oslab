echo "Enter three numbers: "
read a b c
L=$a
if [ $b -gt $a ] && [ $b -gt $c ]; then
	L=$b
fi
if [ $c -gt $a ] && [ $c -gt $b ]; then
	L=$c
fi
echo "The largest of $a, $b and $c is : $L"