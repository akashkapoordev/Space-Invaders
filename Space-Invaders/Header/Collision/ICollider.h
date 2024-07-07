#pragma once
#include <SFML/Graphics.hpp>

namespace Collision
{
	enum CollisionState
	{
		ENABLE,
		DISABLE,
	};
	class ICollider
	{
	public:
		ICollider();
		virtual ~ICollider();
		virtual const sf::Sprite& getCollisionSprite() = 0;
		virtual void onCollision(ICollider* other_collider) = 0;

		void enableCollision();
		void disableCollision();

		CollisionState getCollisionState();

	private:
		CollisionState collision_state;
	};
}