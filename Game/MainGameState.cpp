
#include "stdafx.h"
#include "MainGameSequence.h"
#include "MainGameState.h"

#include <random>

void MainGameState::Enter()
{
	_player = std::make_shared<Player>();
	_player->Transform.Position = Vector2(120, 350);
	TaskManager::Register(_player);

	//ランダムほかで使うならシステム化する
	std::random_device seed_gen;
	std::mt19937 mt(seed_gen());

	for (int i = 0; i < MAX_ENEMY; ++i)
	{
		_enemy[i] = std::make_shared<Enemy>();
		_enemy[i]->Transform.Position = Vector2(280 + mt()%360, 350 - mt() % 150);
		TaskManager::Register(_enemy[i]);
	}
}

void MainGameState::Loop()
{

}

void MainGameState::Exit()
{

}
