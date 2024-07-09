#include "../../Header/Power/Controllers/ShieldController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace PowerUp
{
	namespace Controller
	{
		PowerUp::Controller::ShieldController::ShieldController(PowerType type):PowerupController(type)
		{
		}
		ShieldController::~ShieldController()
		{
		}
		void ShieldController::onCollected()
		{
		}
		void ShieldController::applyPowerUp()
		{
			Global::ServiceLocator::getInstance()->getPlayerService()->enableShield();

		}
	}
}

