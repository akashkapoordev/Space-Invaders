#pragma once
#include "../../Header/Power/PowerupController.h"

namespace PowerUp
{
	namespace Controller
	{
		class ShieldController : public PowerupController
		{
		public:
			ShieldController(PowerType type);
			virtual ~ShieldController();

			void onCollected() override;
			void applyPowerUp() override;


		private:

		};
	}
}



