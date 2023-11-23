
#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

Player::Player()
{
	_hp = 0;
	_interval = 0;
}

Player::~Player()
{

}

void Player::Start()
{
	_objectType = (int)GameObjectType::Player;
	_hp = 0xEFBE;
	_interval = 0;
	Transform.Size = Vector2(50, 80);
	SetupAABB(Collider2D::PLAYER);
}

void Player::Do()
{
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		Transform.Position.X--;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		Transform.Position.X++;
	}

	if(_interval > 0)
		_interval--;

	if (_interval == 0 && CheckHitKey(KEY_INPUT_SPACE))
	{
		auto bullet = Bullet::CreateBullet(Vector2(6,0), this->Transform, Collider2D::COLLIDER_TAG::PLAYER);
		_interval = 60;
	}

	if (_hp <= 0)
	{
		Destroy();
	}
}

void Player::Physics()
{

}

bool Player::HitCallback(std::shared_ptr<Collider2D> target)
{
	auto go = target->GetGameObject().lock();
	if (go->GetObjectType<GameObjectType>() != GameObjectType::Bullet) return false;

	Bullet* ptr = static_cast<Bullet*>(go.get());
	if (ptr->GetBulletForce() == GameObjectType::Player) return false;

	_hp--;
	return true;
}

void Player::Draw()
{
	DrawString(50, 30, "Player", GetColor(64, 64, 255));
	DrawFormatString(50, 50, GetColor(64, 64, 255), "HP: %X", _hp);

	DrawBox(
		(int)(Transform.Position.X - Transform.Size.W / 2), (int)(Transform.Position.Y - Transform.Size.H / 2),
		(int)(Transform.Position.X + Transform.Size.W / 2), (int)(Transform.Position.Y + Transform.Size.H / 2),
		GetColor(64, 64, 255), TRUE);
}

void Player::Release()
{

}
