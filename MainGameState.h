#pragma once
#include "State.h"

#include "Player.h"


class MainGameState : public State
{
	std::shared_ptr<Player> _player;

public:
	explicit MainGameState(std::weak_ptr<StateControl> ctrl)
		: State(ctrl)
	{}
	virtual ~MainGameState() {};

	void Enter();
	void Loop();
	void Exit();
};
