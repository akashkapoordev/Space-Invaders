#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Bullet/Controllers/FrostBulletController.h"
#include "../../Header/Bullet/Controllers/LaserBulletController.h"
#include "../../Header/Bullet/Controllers/TorpedoeController.h"


namespace Bullet
{
	using namespace Controller;
	BulletService::BulletService()
	{
	}
	BulletService::~BulletService()
	{
		destroy();
	}
	void BulletService::initialize()
	{
	}

	void BulletService::update()
	{
		for (int i = 0;i < bullet_list.size();i++)
		{
			bullet_list[i]->update();
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
		bullet_controller->initialize(position, direction);
		bullet_list.push_back(bullet_controller);
		return bullet_controller;
	}

	void BulletService::destroyBullet(BulletController* controller)
	{
		bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), controller), bullet_list.end());
		delete(controller);
	}

	void BulletService::reset()
	{
	}

	BulletController* BulletService::createBullet(BulletType type,Entity::EntityType owner_type)
	{
		switch (type)
		{
		case Bullet::BulletType::LASER:
			return new Controller::LaserBulletController(BulletType::FROST);
			break;
		case Bullet::BulletType::TORPEDO:
			return new Controller::TorpedoeController(BulletType::TORPEDO);
			break;
		case Bullet::BulletType::FROST:
			return new Controller::FrostBulletController(BulletType::FROST);
			break;
		}
	}

	void BulletService::destroy()
	{
		for (int i = 0;i < bullet_list.size();i++)
		{
			delete(bullet_list[i]);
		}
	}

}
