#pragma once

#include "TaskBase.h"
using namespace Task;

class Bullet : public TaskBase {

public:
	Bullet() {}
	virtual	~Bullet() {};

	void Init();		//‰Šú‰»
	void Do();			//ƒƒCƒ“ˆ—
	void Physics();		//‰‰Zˆ—
	void Draw();		//•`‰æˆ—
	void Release();		//‰ğ•ú
};