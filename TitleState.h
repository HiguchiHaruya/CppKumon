#pragma once
#include "State.h"

class TitleState : public State
{
protected:

	TitleState() {}
public:
	explicit TitleState(std::weak_ptr<StateControl> ctrl)
		: State(ctrl)
	{
	}
	virtual ~TitleState() {};

	void Enter();
	void Loop();
	void Exit();
};
