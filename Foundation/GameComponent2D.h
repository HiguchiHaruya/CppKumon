#pragma once
#include "GameMath.h"
#include "TaskBase.h"

struct GameComponent2D
{
	Vector2 Position;
	Vector2 Rotation;
	Vector2 Size;

	GameComponent2D()
		:Position(0, 0)
		,Rotation(0, 0)
		,Size(0,0)
	{}
	virtual	~GameComponent2D() {};

	void SetPosition(Vector2 pos) { Position = pos; }
	void SetRotation(Vector2 rot) { Rotation = rot; }
};