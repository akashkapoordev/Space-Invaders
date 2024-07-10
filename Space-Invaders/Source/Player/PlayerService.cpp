#include "../../Header/Player/PlayerService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Collision/ICollider.h"

using namespace std;


namespace Player
{
	using namespace Global;
	using namespace Collision;
	PlayerService::PlayerService()
	{
		player_controller = new PlayerController();
	}

	PlayerService::~PlayerService()
	{
		delete(player_controller);
		ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(player_controller));
		//Global::ServiceLocator::getInstance().getCollisionService().removeCollider(dynamic_cast<ICollider*>(player_controller));

	}

	void PlayerService::initialize()
	{
		player_controller->initialize();
		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(player_controller));

	}

	void PlayerService::update()
	{
		player_controller->update();
	}

	void PlayerService::render()
	{
		player_controller->render();
	}

	void PlayerService::enableShield()
	{
		player_controller->enableShield();
	}

	void PlayerService::enableRapidFire()
	{
		player_controller->enableRapidFire();
	}

	void PlayerService::enableTrippleLaser()
	{
		player_controller->enableTrippleLaser();
	}

	void PlayerService::reset()
	{
		player_controller->reset();
	}

	void PlayerService::increaseEnemiesKilled(int val)
	{
		player_controller->increaseEnemiesKilled(val);
	}

}
