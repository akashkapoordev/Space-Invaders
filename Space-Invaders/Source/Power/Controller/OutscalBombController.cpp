#include "../../Header/Power/Controllers/OutscalBombController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace PowerUp
{
	namespace Controller
	{
		PowerUp::Controller::OutscalBombController::OutscalBombController(PowerType type) : PowerupController(type) {}

		PowerUp::Controller::OutscalBombController::~OutscalBombController()
		{
		}

		void PowerUp::Controller::OutscalBombController::onCollected()
		{
			applyPowerUp();
		}

		void OutscalBombController::applyPowerUp()
		{
			Global::ServiceLocator::getInstance()->getEnemyService()->reset();
		}
	
	}
}
