#pragma once

#include "TaskBase.h"
#include "GameComponent2D.h"

class Enemy : public Task::TaskBase {

public:
	Enemy() {}
	virtual	~Enemy() {};

	GameComponent2D Transform;

	void Start();		//������
	void Do();			//���C������
	void Physics();		//���Z����
	void Draw();		//�`�揈��
	void Release();		//���
};
