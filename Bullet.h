#pragma once

#include "TaskBase.h"
using namespace Task;

class Bullet : public TaskBase {

public:
	Bullet() {}
	virtual	~Bullet() {};

	void Init();		//������
	void Do();			//���C������
	void Physics();		//���Z����
	void Draw();		//�`�揈��
	void Release();		//���
};