#pragma once

#include "TaskBase.h"
using namespace Task;

class Bullet : public TaskBase {

public:
	Bullet() {}
	virtual	~Bullet() {};

	void Init();		//初期化
	void Do();			//メイン処理
	void Physics();		//演算処理
	void Draw();		//描画処理
	void Release();		//解放
};