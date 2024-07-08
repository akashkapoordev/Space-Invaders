#pragma once
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet
{
	namespace Controller
	{
		class TorpedoeController:public BulletController
		{
		public:
			TorpedoeController(BulletType type,Entity::EntityType ownertype);
			~TorpedoeController();

		private:
			const float movement_speed = 200.f;
			void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;

		};
	}
}

