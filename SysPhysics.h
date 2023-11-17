#pragma once

#include <vector>
#include "Singleton.h"

class Collider {

};

class AABBCollider : public Collider {

};

class OBBCollider : public Collider {

};

class SphereCollider : public Collider{

};

class SysPhysics : public Singleton<SysPhysics>
{
	friend class Singleton<SysPhysics>;

	std::vector<std::shared_ptr<Collider>> _colliders;

	SysPhysics();

	void RegisterCollision(std::shared_ptr<Collider> collision);
	void RemoveCollision(std::shared_ptr<Collider> collision);
public:
	static void Run();
	static void Register(std::shared_ptr<Collider> collision);
	static void Remove(std::shared_ptr<Collider> collision);

	static void Create();
	static void Release();
};
