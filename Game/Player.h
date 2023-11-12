#pragma once

#include "TaskBase.h"
#include "GameComponent2D.h"

class Player : public Task::TaskBase {

public:
	Player() {}
	virtual	~Player() {};

	GameComponent2D Transform;

	void Start();		//初期化
	void Do();			//メイン処理
	void Physics();		//演算処理
	void Draw();		//描画処理
	void Release();		//解放
};