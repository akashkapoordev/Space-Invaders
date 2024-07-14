#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Power/PowerConfig.h"

namespace Enemy
{
	namespace Controller
	{
		//enum class MovementDirection;
		class UFOController:public EnemyController
		{
		public:
			UFOController(EnemyType type);
			virtual ~UFOController();

			void initialize() override;
			void moveLeft();
			void moveRight();
			void fireBullet() override;

		private:
			float speed = 20.f;
			void move() override;
		

			PowerUp::PowerType getRandomPower();

			
			void onCollision(ICollider* other_collider) override;

		};
	}


}

