#pragma once

#include "TaskBase.h"
using namespace Task;

class Player : public TaskBase {

public:
	Player() {}
	virtual	~Player() {};

	void Init();		//������
	void Do();			//���C������
	void Physics();		//���Z����
	void Draw();		//�`�揈��
	void Release();		//���
};