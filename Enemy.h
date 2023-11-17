#pragma once

#include "TaskBase.h"
#include "GameComponent2D.h"

class Enemy : public Task::TaskBase {

public:
	Enemy() {}
	virtual	~Enemy() {};

	GameComponent2D Transform;

	void Start();		//‰Šú‰»
	void Do();			//ƒƒCƒ“ˆ—
	void Physics();		//‰‰Zˆ—
	void Draw();		//•`‰æˆ—
	void Release();		//‰ğ•ú
};
