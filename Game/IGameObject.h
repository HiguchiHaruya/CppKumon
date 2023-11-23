#pragma once

class Collider2D;
class IGameObject : public TaskBase, public std::enable_shared_from_this<IGameObject> {

protected:
	int _objectType;
	std::string _name;
	std::shared_ptr<Collider2D> _collider;

	std::shared_ptr<IGameObject> GetPtr() { return shared_from_this(); }

	virtual bool HitCallback(std::shared_ptr<Collider2D> target)
	{
		return true;
	}

	void Destroy()
	{
		SysPhysics::Remove(_collider, _collider->GetTag());
		TaskManager::Destroy(GetPtr());
	}

public:
	IGameObject() : _objectType(0) {}

	GameComponent2D Transform;

	template<typename T>
	T GetObjectType() { return (T)_objectType; }

	void SetupAABB(Collider2D::COLLIDER_TAG tag)
	{
		_collider = std::make_shared<AABBCollider>(std::weak_ptr<IGameObject>(GetPtr()));
		_collider->UpdateTag(tag);
		_collider->SetCallback(std::bind(&IGameObject::HitCallback, &(*this), std::placeholders::_1));
		SysPhysics::Register(_collider, tag);
	}
};