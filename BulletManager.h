#pragma once

#include "TaskBase.h"
using namespace Task;

class BulletManager : public TaskBase {

public:
	BulletManager() {}
	virtual	~BulletManager() {};

	void Shot();

	void Init();		//‰Šú‰»
	void Do();			//ƒƒCƒ“ˆ—
	void Physics();		//‰‰Zˆ—
	void Draw();		//•`‰æˆ—
	void Release();		//‰ğ•ú
};