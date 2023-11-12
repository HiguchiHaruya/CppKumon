#include "stdafx.h"
#include "Player.h"

void Player::Start()
{
	Transform.Size = Vector2(50, 80);
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
}

void Player::Physics()
{

}

void Player::Draw()
{
	DrawBox(Transform.Position.X - Transform.Size.W / 2, Transform.Position.Y - Transform.Size.H / 2,
		Transform.Position.X + Transform.Size.W / 2, Transform.Position.Y + Transform.Size.H / 2,
		GetColor(64, 64, 255), TRUE);
}

void Player::Release()
{

}
