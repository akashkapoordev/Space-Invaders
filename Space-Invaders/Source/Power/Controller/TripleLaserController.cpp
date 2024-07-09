#include "../../Header/Power/Controllers/TripleLaserController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace PowerUp
{
	namespace Controller
	{
		PowerUp::Controller::TripleLaserController::TripleLaserController(PowerType type):PowerupController(type)
		{
		}

		TripleLaserController::~TripleLaserController()
		{
		}

		void TripleLaserController::onCollected()
		{
			applyPowerUp();
		}

		void TripleLaserController::applyPowerUp()
		{
			Global::ServiceLocator::getInstance()->getPlayerService()->enableTrippleLaser();

		}

	}
}
