
#include "stdafx.h"
#include "MainGameSequence.h"
#include "MainGameState.h"

#include <random>

void MainGameState::Enter()
{
	_player = std::make_shared<Player>();
	_player->Transform.Position = Vector2(120, 350);
	TaskManager::Register(_player);

	//サンプル用に敵を1体だけに
	_enemy[0] = std::make_shared<Enemy>();
	_enemy[0]->Transform.Position = Vector2(520, 350);
	TaskManager::Register(_enemy[0]);

	//ここでおわり
	return;

	//NOTE:ランダムをほかで使うならシステム化する
	//	   その場合はXORSHIFTも作っておく。
	
	//メルセンヌツイスタを使った乱数。mt()で次の乱数を取得する。
	std::random_device seed_gen;
	std::mt19937 mt(seed_gen());

	for (int i = 0; i < MAX_ENEMY; ++i)
	{
		_enemy[i] = std::make_shared<Enemy>();
		_enemy[i]->Transform.Position = Vector2((float)(280 + mt()%360), (float)(350 - (int)mt() % 150));
		TaskManager::Register(_enemy[i]);
	}
}

void MainGameState::Loop()
{

}

void MainGameState::Exit()
{

}
