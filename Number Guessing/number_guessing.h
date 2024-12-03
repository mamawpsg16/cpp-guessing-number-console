#pragma once
#include <utility> // For std::pair
#include <map>
#include <string>  // For std::string

using std::pair;
using std::map;
using std::string;

class NumberGuessing {
private:
	int answer = 0;
	int difficultyLevel = 0;
	map<int, string> difficultyLabel = { {1, "Easy"}, {2, "Medium"}, {3, "Hard"}};
	int maxNumber = 0;
	int attempts = 0;
	int guessNumber = 0;
	char playAgain = 'n';
	void difficultyOption();

public:
	NumberGuessing();
	int generatedRandomNumber(int maxNumber);
	pair<int, int> getDifficultySettings(int difficultyLevel);
	bool isGuessWithinDifficultyRange(int guessNumber);
	void isAnswerHighOrLow();
	void play();
};