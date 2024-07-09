#pragma once
#include "../../Header/Power/PowerupController.h"

namespace PowerUp
{
	namespace Controller
	{
		class RapidFireController: public PowerupController
		{
		public:
			RapidFireController(PowerType type);
			virtual ~RapidFireController();

			void onCollected() override;
			void applyPowerUp() override;


		private:

		};
	}
}



