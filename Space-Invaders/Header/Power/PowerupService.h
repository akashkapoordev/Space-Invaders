#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../Header/Collectible/ICollectible.h"
namespace PowerUp
{
	class PowerupController;
	enum class PowerType;
	class PowerupService
	{
	
	public:
		PowerupService();
		virtual ~PowerupService();

		void initialize();
		void update();
		void render();
		PowerupController* spawnPowerUp(sf::Vector2f position, PowerType type);
		void destroyPowerup(PowerupController* powerup_controller);

	private:
		std::vector <ICollectible*> collectible_list;
		std::vector <ICollectible*> flagged_list;
		PowerupController* createPowerUp(PowerType type);
		void destroyFlaggedList();
		void destroy();
	};


}
