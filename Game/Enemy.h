#pragma once

class Enemy : public IGameObject {
	char _name[8];
	int _hp;
	int _counter;

public:
	Enemy();
	virtual	~Enemy();

	bool HitCallback(std::shared_ptr<Collider2D> target);

	void Start();		//������
	void Do();			//���C������
	void Physics();		//���Z����
	void Draw();		//�`�揈��
	void Release();		//���
};
