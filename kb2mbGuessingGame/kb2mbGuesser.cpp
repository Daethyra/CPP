#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

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

int playGame(int score)
{
	int mb = genMBNumber();
	// get user input and compare it to generated MB value
	std::cout << "About how many kilobytes are in " << mb << " megabytes?" << std::endl;

	int user_input{};
	std::cin >> user_input;

	int kb = genKBValue(mb);

	// if the user's answer is within 10000 of the target value, return true
	if (abs(user_input - kb) <= 10000) {
		std::cout << "Good job! The answer was " << kb << " kilobytes!";
		score++;
		std::cout << "\nYour current score is: " << score << "\n\n";
	}
	else {
		std::cout << "Sorry, the correct answer was " << kb << " kilobytes.\nYour current score is: " << score << "\n\n";
	}
	
	return score;
}

int main()
{
	// generate seed
	srand(time(0));

	// keep track of user's score
	int score{ 0 };

	// keep playing unless user says anything but yes after each turn
	std::string keepPlaying{ "yes" };

	while (keepPlaying == "yes") {
		score = playGame(score);
		std::cout << "Would you like to keep playing? (yes/no)\n";
		std::cin >> keepPlaying;
	}

	std::cout << "Final score: " << score;
	
	return 0;
}