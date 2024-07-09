#pragma once
#include "../../Header/Power/PowerupController.h"

namespace PowerUp
{
	namespace Controller
	{
		class OutscalBombController: public PowerupController
		{
		public:
			OutscalBombController(PowerType type);
			virtual ~OutscalBombController();

			void onCollected() override;
			void applyPowerUp() override;

		private:

		};
	}
}

