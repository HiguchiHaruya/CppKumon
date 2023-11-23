
#include "stdafx.h"
#include "MainGameSequence.h"
#include "MainGameState.h"

#include <random>

void MainGameState::Enter()
{
	_player = std::make_shared<Player>();
	_player->Transform.Position = Vector2(120, 350);
	TaskManager::Register(_player);

	//サンプル用に
	_enemy[0] = std::make_shared<Enemy>();
	_enemy[0]->Transform.Position = Vector2(520, 350);
	TaskManager::Register(_enemy[0]);

	//以下は別sample
	return;

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
