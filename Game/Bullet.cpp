
#include "stdafx.h"
#include "Bullet.h"

std::shared_ptr<Bullet> Bullet::CreateBullet(Vector2 force, GameComponent2D parent, Collider2D::COLLIDER_TAG tag)
{
	std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>();
	bullet->_objectType = (int)GameObjectType::Bullet;
	bullet->_force = force;
	bullet->Transform = parent;
	bullet->_tag = tag;
	bullet->_self = bullet;
	TaskManager::Register(bullet);
	return bullet;
}

Bullet::Bullet()
{
	_force = Vector2(0,0);
	_tag = Collider2D::INVALID_TAG;
}

Bullet::~Bullet()
{

}

void Bullet::Start()
{
	Transform.Size = Vector2(70, 40);
	SetupAABB(Collider2D::BULLET);
}

void Bullet::Do()
{
	Transform.Position += _force;
	SysPhysics::CalcStack(_collider);
}

void Bullet::Physics()
{

}

GameObjectType  Bullet::GetBulletForce()
{
	if (_force.X < 0) return GameObjectType::Enemy;
	if (_force.X > 0) return GameObjectType::Player;
	return  GameObjectType::Invalid;
}

bool Bullet::HitCallback(std::shared_ptr<Collider2D> target)
{
	auto go = target->GetGameObject().lock();
	if (_force.X < 0) {
		if (go->GetObjectType<GameObjectType>() == GameObjectType::Enemy) return false;
	}
	if (_force.X > 0) {
		if (go->GetObjectType<GameObjectType>() == GameObjectType::Player) return false;
	}

	SysPhysics::Remove(_collider, Collider2D::BULLET);
	TaskManager::Destroy(_self);
	return true;
}

void Bullet::Draw()
{
	DrawBox(
		(int)(Transform.Position.X - Transform.Size.W / 2), (int)(Transform.Position.Y - Transform.Size.H / 2),
		(int)(Transform.Position.X + Transform.Size.W / 2), (int)(Transform.Position.Y + Transform.Size.H / 2),
		GetColor(64, 64, 64), TRUE);
}

void Bullet::Release()
{

}