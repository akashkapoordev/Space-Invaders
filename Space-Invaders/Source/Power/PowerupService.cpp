#include "../../Header/Power/PowerupService.h"
#include "../../Header/Power/PowerConfig.h"
#include "../../Header/Power/Controllers/OutscalBombController.h"
#include "../../Header/Power/Controllers/RapidFireController.h"
#include "../../Header/Power/Controllers/ShieldController.h"
#include "../../Header/Power/Controllers/TripleLaserController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Power/PowerupController.h"



namespace PowerUp
{
	using namespace Controller;
	using namespace Global;
	PowerUp::PowerupService::PowerupService()
	{
	}

	PowerupService::~PowerupService()
	{
		destroy();
	}

	void PowerupService::initialize()
	{
	}

	void PowerupService::update()
	{
		for (int i = 0;i < collectible_list.size();i++)
		{
			collectible_list[i]->update();
			destroyFlaggedList();

		}
	}

	void PowerupService::render()
	{
		for (int i = 0;i < collectible_list.size();i++)
		{
			collectible_list[i]->render();
		}
	}

	PowerupController* PowerupService::spawnPowerUp(sf::Vector2f position, PowerType type)
	{
		PowerupController* controller = createPowerUp(type);
		controller->initialCollectible(position);

		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<Collision::ICollider*>(controller));
		collectible_list.push_back(controller);

		return controller;
	}

	PowerupController* PowerupService::createPowerUp(PowerType powerup_type)
	{
		switch (powerup_type)
		{
		case PowerUp::PowerType::SHIELD:
			return new Controller::ShieldController(PowerType::SHIELD);
			break;
		case PowerUp::PowerType::RAPID_FIRE:
			return new Controller::RapidFireController(PowerType::RAPID_FIRE);
			break;
		case PowerUp::PowerType::TRIPPLE_LASER:
			return new Controller::TripleLaserController(PowerType::TRIPPLE_LASER);
			break;
		case PowerUp::PowerType::OUTSCAL_BOMB:
			return new Controller::OutscalBombController(PowerType::OUTSCAL_BOMB);
			break;
		}
	}

	void PowerupService::destroyFlaggedList()
	{
		for (int i = 0;i < flagged_list.size();i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(flagged_list[i]));
			delete(flagged_list[i]);
		}
		flagged_list.clear();
	}


	void PowerupService::destroyPowerup(PowerupController* powerup_controller)
	{
		collectible_list.erase(std::remove(collectible_list.begin(), collectible_list.end(), powerup_controller), collectible_list.end());
		delete(powerup_controller);
	}

	void PowerupService::destroy()
	{
		for (int i = 0;i < collectible_list.size();i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(collectible_list[i]));
			delete(collectible_list[i]);
		}
		collectible_list.clear();
	}

}
