#pragma once
#include "State.h"

#include "Player.h"
#include "Enemy.h"


class MainGameState : public State
{
#define MAX_ENEMY 1 //test

	std::shared_ptr<Player> _player;
	std::shared_ptr<Enemy> _enemy[MAX_ENEMY];

public:
	explicit MainGameState(std::weak_ptr<StateControl> ctrl)
		: State(ctrl)
	{}
	virtual ~MainGameState() {};

	void Enter();
	void Loop();
	void Exit();
};
