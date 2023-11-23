#include "stdafx.h"
#include "Enemy.h"
#include "Bullet.h"

#include <fstream>
#include <iostream>

Enemy::Enemy()
{
	_counter = 0;
	_hp = 0;
	memset(_name, 0x00, sizeof(char) * 8);
}

Enemy::~Enemy()
{
}

bool Enemy::HitCallback(std::shared_ptr<Collider2D> target)
{
	auto go = target->GetGameObject().lock();
	if (go->GetObjectType<GameObjectType>() != GameObjectType::Bullet) return false;

	Bullet* ptr = static_cast<Bullet*>(go.get());
	if (ptr->GetBulletForce() == GameObjectType::Enemy) return false;

	_hp--;
	return true;
}

void Enemy::Start()
{
	_objectType = (int)GameObjectType::Enemy;
	_hp = 0xBEEF;

	std::ifstream ifs("en_name.txt");
	if (ifs)
	{
		//読込サイズを調べる。
		ifs.seekg(0, std::ios::end);
		long long int size = ifs.tellg();
		ifs.seekg(0);

		char* buff = new char[size+1] {0};
		ifs.read(buff, size);
		memcpy(_name, buff, size); //warning
		delete[] buff;

		ifs.close();
	}

	Transform.Size = Vector2(40, 70);
	SetupAABB(Collider2D::ENEMY);
}

void Enemy::Do()
{
	_counter++;
	if (_counter > 20)
	{
		auto bullet = Bullet::CreateBullet(Vector2(-5, 0), this->Transform, Collider2D::COLLIDER_TAG::ENEMY);
		_counter = 0;
	}

	if (_hp <= 0)
	{
		Destroy();
	}
}

void Enemy::Physics()
{

}

void Enemy::Draw()
{
	DrawString(520, 30, _name, GetColor(255, 64, 64));
	DrawFormatString(520, 50, GetColor(255, 64, 64), "HP: %d", _hp);

	DrawBox(Transform.Position.X - Transform.Size.W / 2, Transform.Position.Y - Transform.Size.H / 2,
		Transform.Position.X + Transform.Size.W / 2, Transform.Position.Y + Transform.Size.H / 2,
		GetColor(255, 64, 64), TRUE);
}

void Enemy::Release()
{

}
