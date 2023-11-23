
#include "stdafx.h"
#include "SysPhysics.h"

static std::unique_ptr<SysPhysics> _instance;
SysPhysics* GetSysPhysicsInstance()
{
	return _instance.get();
}

SysPhysics::SysPhysics()
{
	//_worker;
	_colliders[(int)Collider2D::COLLIDER_TAG::BULLET].reserve(100);
}

void SysPhysics::CalcStack(std::shared_ptr<Collider2D> collision)
{
	GetSysPhysicsInstance()->_calcStack.push_back(collision);
}

void SysPhysics::HitToAll(std::shared_ptr<Collider2D> collision, Collider2D::COLLIDER_TAG tag)
{
	for (auto itr = _colliders[(int)tag].begin(); itr != _colliders[(int)tag].end(); ++itr) {
		if (collision->IsHit((*itr)))
		{
			collision->_hitCallback((*itr));
			(*itr)->_hitCallback(collision);
		}
	}
}

void SysPhysics::Run()
{
	auto& removes = GetSysPhysicsInstance()->_removeList;
	for (auto itr = removes.begin(); itr != removes.end(); ++itr) {

		auto& lists = GetSysPhysicsInstance()->_colliders[(int)itr->second];

		for (auto itr2 = lists.begin(); itr2 != lists.end(); ++itr2) {
			if (*itr2 == itr->first)
			{
				lists.erase(itr2);
				break;
			}
		}
	}

	auto& calcStacks = GetSysPhysicsInstance()->_calcStack;
	for (auto itr = calcStacks.begin(); itr != calcStacks.end(); ++itr) {

		auto tag = (*itr)->GetTag();
		//Matrix‚Í–{—ˆ‚ÍŽ©“®‰»‚·‚é‚Ì‚ª‚æ‚¢1
		switch (tag)
		{
		case Collider2D::COLLIDER_TAG::BULLET:
			GetSysPhysicsInstance()->HitToAll((*itr), Collider2D::COLLIDER_TAG::ENEMY);
			GetSysPhysicsInstance()->HitToAll((*itr), Collider2D::COLLIDER_TAG::PLAYER);
			break;

		case Collider2D::COLLIDER_TAG::PLAYER:
			break;

		case Collider2D::COLLIDER_TAG::ENEMY:
			break;
		}
	}

	calcStacks.clear();
}

void SysPhysics::Sync()
{

}

void SysPhysics::Register(std::shared_ptr<Collider2D> collision, Collider2D::COLLIDER_TAG tag)
{
	GetSysPhysicsInstance()->_colliders[(int)tag].push_back(collision);
}

void SysPhysics::Remove(std::shared_ptr<Collider2D> collision, Collider2D::COLLIDER_TAG tag)
{
	GetSysPhysicsInstance()->_removeList.push_back(std::pair<std::shared_ptr<Collider2D>, Collider2D::COLLIDER_TAG>(collision, tag));
}

void SysPhysics::Create()
{
	if (_instance == nullptr)
	{
		_instance = std::unique_ptr<SysPhysics>(new SysPhysics());
	}
}

void SysPhysics::Release()
{
	_instance.release();
}
