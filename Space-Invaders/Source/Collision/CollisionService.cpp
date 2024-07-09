#include "../../Header/Collision/CollisionService.h"
#include "../../Header/Collision/ICollider.h";

namespace Collision
{
	CollisionService::CollisionService()
	{
	}
	CollisionService::~CollisionService()
	{
	}
	void CollisionService::initilize()
	{
	}
	void CollisionService::update()
	{
		processCollision();
	}
	void CollisionService::addCollider(ICollider* collider)
	{
		collider_list.push_back(collider);
	}
	void CollisionService::removeCollider(ICollider* collider)
	{
		collider_list.erase(std::remove(collider_list.begin(), collider_list.end(), collider), collider_list.end());
	}
	void CollisionService::processCollision()
	{
		for (int i = 0;i < collider_list.size(); i++)
		{
			for (int j = 0;j < collider_list.size();j++)
			{
				doCollision(i, j);
			}
		}
	}
	void CollisionService::doCollision(int index_i, int index_j)
	{
		if (collider_list[index_i]->getCollisionState() == CollisionState::DISABLE ||
			collider_list[index_j]->getCollisionState() == CollisionState::DISABLE) return;

		if (hasCollisionOccurred(index_i, index_j))
		{
			if (areActiveCollision(index_i, index_j))
			{
				collider_list[index_i]->onCollision(collider_list[index_j]);
			}
			if (areActiveCollision(index_i, index_j))
			{
				collider_list[index_j]->onCollision(collider_list[index_i]);
			}
		}
	}
	bool CollisionService::hasCollisionOccurred(int index_i, int index_j)
	{
		const sf::Sprite& collider_first_sprite = collider_list[index_i]->getCollisionSprite();
		const sf::Sprite& collider_secondd_sprite = collider_list[index_j]->getCollisionSprite();

		return collider_first_sprite.getGlobalBounds().intersects(collider_secondd_sprite.getGlobalBounds());

	}
	bool CollisionService::areActiveCollision(int index_i, int index_j)
	{
		return (index_i < collider_list.size() && index_j < collider_list.size() && collider_list[index_i] != nullptr && collider_list[index_j] != nullptr);
	}
}