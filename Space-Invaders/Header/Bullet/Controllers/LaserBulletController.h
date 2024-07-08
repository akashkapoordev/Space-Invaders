#pragma once
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet
{
	namespace Controller
	{
		class  LaserBulletController :public BulletController
		{
		public:
			LaserBulletController(BulletType type,Entity::EntityType ownertype);
			~LaserBulletController();

		private:
			void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;

		};
	}

}


