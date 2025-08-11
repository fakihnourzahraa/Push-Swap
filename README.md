# Push-Swap
Main
    Check for erros in arg
	Intialize
		-> this is gonna take an array either way, from split or stdin
		-> check for errors
		-> if string (argc == 2) then take the string and convert it to an array of ints
		-> check for duplicates
		-> append to stack
	Check if sorted
		if (!sorted) -> sort
to do:
	->int max int min
	->string
	->check for large input
	->hard code base cases
errors:
	->  % ./push_swap "8619 4 4058 3 2384 2 -3495 1 8763 5" | wc -l  
		13
	->  % ./push_swap "190 4 -5445 3 282 5 -8094 2  -9703 1" | wc -l
	14

rm -rf test_check.txt

./push_swap "" > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}4.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}4.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	pr

ARG="99999999999999999999999999"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}27.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}27.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}27.[KO] ${DEF_COLOR}\n";
fi

ARG="-99999999999999999999999999"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}28.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}28.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}28.[KO] ${DEF_COLOR}\n";
fi


ARG="-"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}32.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}32.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}32.[KO] ${DEF_COLOR}\n";
fi

ARG="+"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}33.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}33.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}33.[KO] ${DEF_COLOR}\n";
fi