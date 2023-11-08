#pragma once

#include "TaskBase.h"
using namespace Task;

class Player : public TaskBase {

public:
	Player() {}
	virtual	~Player() {};

	void Init();		//‰Šú‰»
	void Do();			//ƒƒCƒ“ˆ—
	void Physics();		//‰‰Zˆ—
	void Draw();		//•`‰æˆ—
	void Release();		//‰ğ•ú
};