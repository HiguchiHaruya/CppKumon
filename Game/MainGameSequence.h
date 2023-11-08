#pragma once
#include "State.h"

enum MAIN_GAME_SEQUENCE
{
	TITLE,
	INGAME,
	RESULT,
	MAX
};

class MainGameSequence : public StateControl
{

public :
	MainGameSequence();
	~MainGameSequence();

	void NextState(int state);
};