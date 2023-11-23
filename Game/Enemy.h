#pragma once

class Enemy : public IGameObject {
	char _name[8];
	int _hp;
	int _counter;

public:
	Enemy();
	virtual	~Enemy();

	bool HitCallback(std::shared_ptr<Collider2D> target);

	void Start();		//‰Šú‰»
	void Do();			//ƒƒCƒ“ˆ—
	void Physics();		//‰‰Zˆ—
	void Draw();		//•`‰æˆ—
	void Release();		//‰ğ•ú
};
