#pragma once

#include "TaskBase.h"
using namespace Task;

class BulletManager : public TaskBase {

public:
	BulletManager() {}
	virtual	~BulletManager() {};

	void Shot();

	void Init();		//������
	void Do();			//���C������
	void Physics();		//���Z����
	void Draw();		//�`�揈��
	void Release();		//���
};