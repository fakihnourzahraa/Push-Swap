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