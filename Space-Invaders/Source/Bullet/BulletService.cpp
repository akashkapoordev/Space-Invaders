#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Bullet/Controllers/FrostBulletController.h"
#include "../../Header/Bullet/Controllers/LaserBulletController.h"
#include "../../Header/Bullet/Controllers/TorpedoeController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Collision/ICollider.h"


namespace Bullet
{
	using namespace Controller;
	using namespace Global;
	BulletService::BulletService()
	{
	}
	BulletService::~BulletService()
	{
		destroy();
	}
	void BulletService::initialize()
	{
		bullet_list.clear();
		flagged_bullets.clear();
	}

	void BulletService::update()
	{
		for (int i = 0;i < bullet_list.size();i++)
		{
			bullet_list[i]->update();
			destroyFlaggedBullet();
		}
	
	}

	void BulletService::render()
	{
		for (int i = 0;i < bullet_list.size();i++)
		{
			bullet_list[i]->render();
		}
	}

	BulletController* BulletService::spawnBullet(sf::Vector2f position, MovementDirection direction, BulletType type, Entity::EntityType owner_type)
	{
		BulletController* bullet_controller = createBullet(type,owner_type);
		//printf(owner_type);
		
		bullet_controller->initialize(position, direction);

		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<Collision::ICollider*>(bullet_controller));
		//printf("Spwan Bullet");
		bullet_list.push_back(bullet_controller);
		return bullet_controller;
	}

	void BulletService::destroyBullet(BulletController* controller)
	{
		if (std::find(flagged_bullets.begin(), flagged_bullets.end(), controller) == flagged_bullets.end())
		{
			flagged_bullets.push_back(controller);
			bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(),controller), bullet_list.end());
		}
	}

	void BulletService::reset()
	{
		destroy();
	}

	BulletController* BulletService::createBullet(BulletType type,Entity::EntityType owner_type)
	{
		switch (type)
		{
		case Bullet::BulletType::LASER:
			//printf("Laser Bullet");
			return new Controller::LaserBulletController(BulletType::LASER,owner_type);
			break;
		case Bullet::BulletType::TORPEDO:
			//printf("TORPEDO Bullet");

			return new Controller::TorpedoeController(BulletType::TORPEDO, owner_type);
			break;
		case Bullet::BulletType::FROST:
			return new Controller::FrostBulletController(BulletType::FROST, owner_type);
			break;
		}
	}

	bool BulletService::isBulletVaild(int index_i, std::vector<IProjectile*>& bullet_list)
	{
		return index_i >= 0 && index_i<bullet_list.size() && bullet_list[index_i] != nullptr;
	}

	void BulletService::destroyFlaggedBullet()
	{
		for (int i = 0;i < flagged_bullets.size();i++)
		{
			if (!isBulletVaild(i, flagged_bullets))continue;
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(flagged_bullets[i]));
			delete(flagged_bullets[i]);
		}
		flagged_bullets.clear();
	}

	void BulletService::destroy()
	{
		for (int i = 0;i < bullet_list.size();i++)
		{
			if (!isBulletVaild(i, bullet_list))continue;
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(bullet_list[i]));
			delete (bullet_list[i]);
		}
		bullet_list.clear();
	}

}
