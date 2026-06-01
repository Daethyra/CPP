#include <iostream>
#include <cstdlib>
#include <ctime>

/* future functionality:
		- keep track of score in dictionary 
		  - record every result
		  - congratulate or encourage the user based on result
		  - succeed 5 times and win the "game" */

// randomly generate a megabyte value
int genMBNumber()
{
	/* rand() will read the seed from main() later on because
	srand() sets a global/hidden state that rand() reads from */
	return rand() % 2001;
}

// calculate the KB value of the generated MB value
int genKBValue(int mb)
{
	/* A Megabyte equals 1,048,576 bytes, and a Kilobyte equals 1024 bytes,
	because computers follow the binary number system. */
	int kbValue = mb * 1024;
	return kbValue;
}

int main()
{
	// generate seed
	srand(time(0));
	int mb = genMBNumber();

	// get user input and compare it to generated MB value
	std::cout << "How many kilobytes does " << mb << " megabytes equal?" << std::endl;

	int user_input;
	std::cin >> user_input;

	int kb = genKBValue(mb);

	// if the user's answer is within 1000 of the target value, return true
	if (abs(user_input - kb) <= 10000) {
		std::cout << "Good job! The answer was " << kb << " kilobytes!";
	}
	else {
		std::cout << "Sorry, the correct answer was " << kb << " kilobytes.";
	}

	return 0;
}
