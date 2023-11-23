
#include "stdafx.h"

Collider2D::~Collider2D()
{

}

Collider2D::Collider2D(COLLIDER_TYPE type, std::weak_ptr<IGameObject> link)
{
	_target = link;

	_type = type;
	_tag = COLLIDER_TAG::INVALID_TAG;
}

void Collider2D::UpdateTag(COLLIDER_TAG tag)
{
	_tag = tag;
	if (_tag > COLLIDER_TAG::INVALID_TAG)
	{
		SysPhysics::CalcStack(GetPtr());
	}
}

void Collider2D::SetCallback(std::function<bool(std::shared_ptr<Collider2D>)> callback)
{
	_hitCallback = callback;
}

bool AABBCollider::IsHit(std::shared_ptr<Collider2D> target)
{
	//“–‚½‚è•û
	switch (target->GetType())
	{
	//AABB‘ÎAABB
	case COLLIDER_TYPE::AABB:
	{
		auto link = target->GetGameObject();
		auto tgt = link.lock();
		auto self = _target.lock();

		float xa1 = (tgt->Transform.Position.X - tgt->Transform.Size.X/2);
		float xb1 = (self->Transform.Position.X - self->Transform.Size.X/2);
		float ya1 = (tgt->Transform.Position.Y - tgt->Transform.Size.Y/2);
		float yb1 = (self->Transform.Position.Y - self->Transform.Size.Y/2);
		float xa2 = (tgt->Transform.Position.X + tgt->Transform.Size.X/2);
		float xb2 = (self->Transform.Position.X + self->Transform.Size.X/2);
		float ya2 = (tgt->Transform.Position.Y + tgt->Transform.Size.Y/2);
		float yb2 = (self->Transform.Position.Y + self->Transform.Size.Y/2);

		return xa1 <= xb2 && xa2 >= xb1 && ya1 <= yb2 && ya2 >= yb1;
	}
	break;
	}

	return false;
}
