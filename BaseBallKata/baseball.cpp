#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	const int MAX_TRIALS = 3;
	explicit Baseball(const string& question) : question(question){

	}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		
		int strikes = getStrike(guessNumber);
		int balls = getBalls(guessNumber);
		bool solved = getSolved(strikes);

		return { solved, strikes, balls };
	}
	
private:
	bool getSolved(int strikes) {
		return strikes == MAX_TRIALS ? true : false;
	}
	int getBalls(const std::string& guessNumber)
	{
		int balls = 0;
		for (int numberIndex = 0; numberIndex < MAX_TRIALS; numberIndex++) {
			if (guessNumber[numberIndex] == question[numberIndex])
				continue;

			for (int questionIndex = 0; questionIndex < MAX_TRIALS; questionIndex++) {
				if (numberIndex == questionIndex)
					continue;
				if (guessNumber[numberIndex] == question[questionIndex])
					balls++;
			}

		}

		return balls;
	}
	int getStrike(const std::string& guessNumber)
	{
		int strikes = 0;
		for (int i = 0; i < MAX_TRIALS; i++) {
			if (guessNumber[i] == question[i]) {
				strikes++;
			}
		}
		return strikes;
	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != MAX_TRIALS) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");

		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	string question;
};