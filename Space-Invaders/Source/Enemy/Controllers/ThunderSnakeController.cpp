#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	namespace Controller
	{
		using namespace Global;
		ThunderSnakeController::ThunderSnakeController(EnemyType type):EnemyController(type)
		{
		}
		ThunderSnakeController::~ThunderSnakeController()
		{
		}
		void ThunderSnakeController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::LEFT);

		}
		void ThunderSnakeController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case MovementDirection::LEFT:
				moveLeft();
				break;
			case MovementDirection::RIGHT:
				moveRight();
				break;
			case MovementDirection::LEFT_DOWN:
				moveLeftDiagonal();
				break;
			case MovementDirection::RIGHT_DOWN:
				moveRightDiagonal();
				break;
			default:
				break;
			}
		}
		void ThunderSnakeController::moveLeft()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x -= horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			if (currentPosition.x <= enemy_model->left_window.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT_DOWN);
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);

			}
		}
		void ThunderSnakeController::moveRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x += horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			if (currentPosition.x >= enemy_model->right_window.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT_DOWN);
				printf("Move Left");
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);

			}
		}
		void ThunderSnakeController::moveLeftDiagonal()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x -= horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= enemy_model->left_window.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}

		}
		void ThunderSnakeController::moveRightDiagonal()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x += horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= enemy_model->right_window.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
		}
		void ThunderSnakeController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,Bullet::MovementDirection::DOWM, Bullet::BulletType::TORPEDO, Entity::EntityType::ENEMY);
		}
	}
}