#include "../../Header/Power/Controllers/RapidFireController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace PowerUp
{
	namespace Controller
	{
		PowerUp::Controller::RapidFireController::RapidFireController(PowerType type):PowerupController(type)
		{
		}

		RapidFireController::~RapidFireController()
		{
		}

		void RapidFireController::onCollected()
		{
			applyPowerUp();
		}

		void RapidFireController::applyPowerUp()
		{
			Global::ServiceLocator::getInstance()->getPlayerService()->enableRapidFire();
		}

	}
}
