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
	If 2 nodes, swap
	else if 3 nodes, sort 3 algo
	// else if 4 > 4 algo
	// else if 5 > 5 algo
	else turk algo
		b-> pb
		-> pb
		-> while (a.len < 3>) calculate cost and push cheapest element while rotating
			->still dont know
			-> if a is a minimum or maximum of b, then rotate in a way where u place it there // idk yet
		-> sort last 2 elements
		-> while (b) push to a and rotate as needed
		-> rotate till minimum is at top
to do:
	fix sorting logic please
	->int max int min
	->string
	->check for large input

## 🔷 Write pseudo code

//Declare pointers to two data structures/linked lists, one for stack `a` and another for `b`
	//Set both pointers to NULL to avoid undefined behaviour and indicate we're starting with empty stacks

//Handle input count errors. Argument count must be 2 or more, and the second input must not be empty
	//If input errors, return error

//Handle both cases of input, whether a variable number of command line arguments, or as a string
	//If the input of numbers is as a string, call split() to split the substrings

//Initialize stack `a` by appending each input number as a node to stack `a`
	//Handle integer overflow, duplicates, and syntax errors, e.g. input must only contain digits, or `-` `+` signs
		//If errors found, free stack `a` and return error
	//Check for each input, if it is a long integer
		//If the input is a string, convert it to a long integer 
	//Append the nodes to stack `a`

//Check if stack `a` is sorted
	//If not sorted, implement our sorting algorithm
		//Check for 2 numbers
			//If so, simply swap the numbers
		//Check for 3 numbers
			//If so, implement our simple `sort three` algorithim
		//Check if the stack has more than 3 numbers
			//If so, implent our Turk Algorithm

//Clean up the stack