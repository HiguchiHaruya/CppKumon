#pragma once

class Enemy : public IGameObject {
	char _name[8];
	int _hp;
	int _counter;

public:
	Enemy();
	virtual	~Enemy();

	bool HitCallback(std::shared_ptr<Collider2D> target);

	void Start();		//初期化
	void Do();			//メイン処理
	void Physics();		//演算処理
	void Draw();		//描画処理
	void Release();		//解放
};
