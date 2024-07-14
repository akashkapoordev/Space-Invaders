#pragma once
#include "../../Header/Enemy/EnemyController.h"
namespace Enemy
{
	namespace Controller
	{
		class ThunderSnakeController:public EnemyController
		{
		public:
			ThunderSnakeController(EnemyType type);
			~ThunderSnakeController();

			void initialize() override;
			void move() override;
			void moveLeft();
			void moveRight();
			void moveLeftDiagonal();
			void moveRightDiagonal();
			void fireBullet() override;
		private:
			const float horizontal_movement_speed = 190.f;
			const float vertical_movement_speed = 20.f;

		};

	}
}

