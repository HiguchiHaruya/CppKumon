#pragma once

struct Vector2
{
	union {
		float X;
		float W;
	};
	union {
		float Y;
		float H;
	};
	Vector2()
	{
		X = 0; Y = 0;
	}

	Vector2(float x, float y)
	{
		X = x;
		Y = y;
	}

	Vector2 operator + (Vector2 pos)
	{
		X += pos.X;
		Y += pos.Y;
		return *this;
	}
	Vector2 operator += (Vector2 pos)
	{
		X += pos.X;
		Y += pos.Y;
		return *this;
	}
};

struct Vector3
{
	float X;
	float Y;
	float Z;

	Vector3()
	{
		X = 0; Y = 0; Z = 0;
	}

	Vector3(float x, float y, float z)
	{
		X = x;
		Y = y;
		Z = z;
	}
};