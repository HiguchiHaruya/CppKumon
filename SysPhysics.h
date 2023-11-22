#pragma once

#include <array>
#include <vector>
#include "GameMath.h"
#include "Singleton.h"

enum COLLIDER_TYPE {
	AABB,
	SPHERE,
	OBB
};

enum COLLIDER_TAG {
	PLAYER,
	ENEMY,
	BULLET,
	MAX_COLLIDER_TAG
};

class SysPhysics;
class Collider2D {
	friend SysPhysics;
	
	COLLIDER_TYPE _type;
	COLLIDER_TAG _tag;
	virtual bool IsHit(Collider2D target) = 0; //target‚É‘Î‚µ‚Ä“–‚½‚Á‚Ä‚¢‚é‚©

public:
	Collider2D() {}
	virtual ~Collider2D() {}
	void UpdateTag(COLLIDER_TAG tag);// { _tag = tag; }
};

//TBD
class AABBCollider : public Collider2D {
	Vector2 _leftTop;
	Vector2 _rightBottom;

	AABBCollider() {}
public:
	AABBCollider(Vector2 lt, Vector2 rb);

	void UpdatePosBox(Vector2 lt, Vector2 rb);
	void UpdatePosCenter(Vector2 center, Vector2 size);
	Vector2& GetPos();
};

//TBD
class OBBCollider : public Collider2D {
};

class SphereCollider : public Collider2D {
	Vector2 _pos;
	float _radius;

	SphereCollider() {}

public:
	SphereCollider(Vector2 p, float r);
	void UpdatePos(Vector2 p) { _pos = p;  }
	void UpdateRadius(float r) { _radius = r; }
	Vector2& GetPos() { return _pos; }
};

class SysPhysics : public Singleton<SysPhysics>
{
	friend class Singleton<SysPhysics>;

	std::array<std::vector<std::shared_ptr<Collider2D>>, MAX_COLLIDER_TAG> _colliders;

	SysPhysics();

	void RegisterCollision(std::shared_ptr<Collider2D> collision);
	void RemoveCollision(std::shared_ptr<Collider2D> collision);
public:
	static void Run();
	static void Sync();
	static void Register(std::shared_ptr<Collider2D> collision, COLLIDER_TAG tag);
	static void Remove(std::shared_ptr<Collider2D> collision, COLLIDER_TAG tag);

	static void Create();
	static void Release();
};
