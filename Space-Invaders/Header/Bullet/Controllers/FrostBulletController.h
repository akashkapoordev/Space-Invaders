#pragma once
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Entity/EntityConfig.h"


namespace Bullet
{
	namespace Controller
	{
		class FrostBulletController:public BulletController
		{
		public:
			FrostBulletController(BulletType type,Entity::EntityType ownertype);
			~FrostBulletController();

		private:
			const float movement_speed = 500.f;
			void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;

		};
	}
}


