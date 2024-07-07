#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet
{
	enum class BulletType;
	enum class MovementDirection;
	class BulletModel
	{
	public:
		BulletModel(BulletType type,Entity::EntityType owner_type);
		~BulletModel();

		void initialize(sf::Vector2f position, Bullet::MovementDirection direction);
		void update();
		void render();

		float getMovementSpeed();
		sf::Vector2f getPosition();
		BulletType getBulletType();
		MovementDirection getMovementDirection();

		void setPosition(sf::Vector2f psoition);
		void setMovementSpeed(float speed);
		void setMovementDirection(MovementDirection direction);
		void setBulletType(BulletType type);

		Entity::EntityType owner_type;
		Entity::EntityType getOwnerEntityType();

	private:
		float movement_speed = 300.f;
		sf::Vector2f bullet_position;

		BulletType bullet_type;
		MovementDirection movement_type;

	
	};
}


