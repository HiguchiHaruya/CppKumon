
#include "stdafx.h"
#include "MainGameSequence.h"
#include "MainGameState.h"


void MainGameState::Enter()
{
	_player = std::make_shared<Player>();
	_player->Transform.Position = Vector2(120, 350);
	TaskManager::Register(_player);
}

void MainGameState::Loop()
{

}

void MainGameState::Exit()
{

}
