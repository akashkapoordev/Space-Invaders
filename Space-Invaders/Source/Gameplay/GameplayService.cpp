#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Gameplay
{
	using namespace Global;
	Gameplay::GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}

	Gameplay::GameplayService::~GameplayService()
	{
		delete(gameplay_controller);
	}

	void Gameplay::GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}

	void Gameplay::GameplayService::update()
	{
		gameplay_controller->update();
	}

	void Gameplay::GameplayService::render()
	{
		gameplay_controller->render();
	}

	void GameplayService::reset()
	{
		{
			ServiceLocator::getInstance()->getPlayerService()->reset();
			ServiceLocator::getInstance()->getEnemyService()->reset();
			ServiceLocator::getInstance()->getBulletService()->reset();
			ServiceLocator::getInstance()->getElementService()->reset();
		}

	}

}
