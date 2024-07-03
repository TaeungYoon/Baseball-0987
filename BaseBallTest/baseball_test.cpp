#include "pch.h"
#include "../BaseBallKata/baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		//game.guess() 수행 후, exception이 발생해야 PASS 이다
	}
};

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar) {
	Baseball game;
	try {
		game.guess(string("12s"));
		FAIL();
	}
	catch (exception e) {
		//PASS
	}
}