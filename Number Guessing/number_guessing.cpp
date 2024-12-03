#include <iostream>
#include "number_guessing.h"
#include <utility> // For std::pair
#include <map>
#include <limits>

using std::cout;
using std::cin;
using std::srand;
using std::rand;
using std::pair;

void NumberGuessing::difficultyOption() {
	cout << "Choose Difficulty Level:  \n\n";
	cout << "1. Easy (1-50, 10 Attemps) \n";
	cout << "2. Medium (1-100, 7 Attemps) \n";
	cout << "3. Hard (1-200, 5 Attemps) \n\n";
	cout << "Enter difficulty level (1-3): ";
}

NumberGuessing::NumberGuessing() {
	srand(static_cast<unsigned int>(time(0))); // Initialize random seed
}


int NumberGuessing::generatedRandomNumber(int maxNumber) {
	return rand() % maxNumber + 1; // Generate random number between 1 and maxNumber
}

pair<int, int> NumberGuessing::getDifficultySettings(int difficultyLevel) {
	std::map<int, std::pair<int, int>> difficultySettings = {
		{1, {50, 10}},  // Easy: maxNumber = 50, attempts = 10
		{2, {100, 7}},  // Medium: maxNumber = 100, attempts = 7
		{3, {200, 5}}   // Hard: maxNumber = 200, attempts = 5
	};

	return difficultySettings[difficultyLevel];
};

bool NumberGuessing::isGuessWithinDifficultyRange(int inputNumber) {
	return inputNumber >= 1 && inputNumber <= maxNumber;
}

void NumberGuessing::isAnswerHighOrLow() {
	if (guessNumber > answer) {
		cout << "Too high.\n";
	}
	else {
		cout << "Too low.\n";
	}
}

void NumberGuessing::play() {

	do
	{
		difficultyOption();

		int numberOfAttempts;

		while (!(cin >> difficultyLevel) || difficultyLevel < 1 || difficultyLevel > 3)
		{
			cout << "\nInvalid, Enter a valid difficulty level (1-3): ";
		}

		pair<int, int> settings = getDifficultySettings(difficultyLevel);

		maxNumber = settings.first;
		attempts = settings.second;
		numberOfAttempts = settings.second;

		answer = generatedRandomNumber(maxNumber);

		string mode = difficultyLabel.at(difficultyLevel);

		cout << "\nYou Selected " << mode << " Difficulty, (1-" << maxNumber << ")\n";

		cout << "\nIve now selected a number between (1-" << maxNumber << ").\n";

		do
		{
			cout << "\nEnter your guess: ";

			if (!(cin >> guessNumber) || !isGuessWithinDifficultyRange(guessNumber)) {
				cout << "Invalid Guess Number, Try again number between (1-" << maxNumber << "). \n";
				// Clear the error flag and ignore the invalid input
				cin.clear();
				cin.ignore(std::numeric_limits<int>::max(), '\n');
			}

			if (guessNumber == answer) {
				break;
			}

			--attempts;
			if (attempts > 0) {
				isAnswerHighOrLow();
				cout << "Incorrect guess. Attempts left: " << attempts << '\n';
			}

		} while (attempts > 0);

		if (attempts > 0) {
			cout << "\nAwesome you guess it right, with " << numberOfAttempts -  attempts <<" attempt(s)\n";
		}
		else {
			cout << "\nYou failed with " << numberOfAttempts << " attempt(s), the correct number is " << answer << "\n";
		}

		// Ask if the user wants to play again
		cout << "\nDo you want to play again? (y/n): ";
		if (!(cin >> playAgain)) {
			cout << "Invalid Answer, Try y or n. \n";
			// Clear the error flag and ignore the invalid input
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
		}

	} while (playAgain == 'Y' || playAgain == 'y');

};
