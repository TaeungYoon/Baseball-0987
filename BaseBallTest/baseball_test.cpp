#include "pch.h"
#include "../BaseBallKata/baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(string(guessNumber));
			FAIL();
		}
		catch (exception e) {
			//PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInputLengthIsUnmatched) {
	assertIllegalArgument("12");
}

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidChar) {	
	assertIllegalArgument("12s");
}