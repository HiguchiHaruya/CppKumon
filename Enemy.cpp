#include "stdafx.h"
#include "Enemy.h"

void Enemy::Start()
{
	Transform.Size = Vector2(40, 70);
}

void Enemy::Do()
{

}

void Enemy::Physics()
{

}

void Enemy::Draw()
{
	DrawBox(Transform.Position.X - Transform.Size.W / 2, Transform.Position.Y - Transform.Size.H / 2,
		Transform.Position.X + Transform.Size.W / 2, Transform.Position.Y + Transform.Size.H / 2,
		GetColor(255, 64, 64), TRUE);
}

void Enemy::Release()
{

}
