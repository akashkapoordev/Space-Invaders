#include "../../Header/Bullet/BulletModel.h"


namespace Bullet
{
	using namespace Entity;
	Bullet::BulletModel::BulletModel(BulletType type,Entity::EntityType owner_type)
	{
		bullet_type = type;
	}

	BulletModel::~BulletModel()
	{
	}

	void BulletModel::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
	{
		bullet_position = position;
		movement_type = direction;
	}

	void BulletModel::update()
	{
	}

	void BulletModel::render()
	{
	}

	float BulletModel::getMovementSpeed()
	{
		return movement_speed;
	}

	void BulletModel::setMovementSpeed(float speed)
	{
		movement_speed = speed;
	}

	sf::Vector2f BulletModel::getPosition()
	{
		return bullet_position;
	}

	void BulletModel::setPosition(sf::Vector2f position)
	{
		bullet_position = position;
	}

	BulletType BulletModel::getBulletType()
	{
		return bullet_type;
	}

	void BulletModel::setBulletType(BulletType type)
	{
		bullet_type = type;
	}

	Entity::EntityType BulletModel::getOwnerEntityType()
	{
		return Entity::EntityType();
	}

	MovementDirection BulletModel::getMovementDirection()
	{
		return movement_type;
	}

	void BulletModel::setMovementDirection(MovementDirection direction)
	{
		movement_type = direction;
	}

}

