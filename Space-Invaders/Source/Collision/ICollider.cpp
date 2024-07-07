#include "../../Header/Collision/ICollider.h"

namespace Collision
{
	Collision::ICollider::ICollider()
	{
		collision_state = CollisionState::ENABLE;
	}

	Collision::ICollider::~ICollider()
	{
	}

	void Collision::ICollider::enableCollision()
	{
		collision_state = CollisionState::ENABLE;
	}

	void Collision::ICollider::disableCollision()
	{
		collision_state = CollisionState::DISABLE;

	}

	CollisionState Collision::ICollider::getCollisionState()
	{
		return collision_state;
	}

}
