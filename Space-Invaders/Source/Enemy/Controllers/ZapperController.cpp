#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy
{
	using namespace Global;
	using namespace Controller;
	namespace Controller
	{
		Enemy::ZapperController::ZapperController(EnemyType type):EnemyController(type)
		{
		}

		Enemy::ZapperController::~ZapperController()
		{
		}

		void Enemy::ZapperController::initialize()
		{
			EnemyController::initialize();
			//enemy_model->setMovementDirection(MovementDirection::DOWN);
			rate_of_fire = 2.f;
		}

		void ZapperController::fireBullet()
		{
			//printf("Fire Enemy");
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset, Bullet::MovementDirection::DOWM, Bullet::BulletType::LASER,Entity::EntityType::ENEMY);
		}

		void Enemy::ZapperController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case MovementDirection::LEFT:
				moveLeft();
				break;
			case MovementDirection::RIGHT:
				moveRight();
				break;
			case MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void Enemy::ZapperController::moveLeft()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x -= enemy_model->move_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			if (currentPosition.x <= enemy_model->left_window.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setRefPosition(currentPosition);
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
		}

		void Enemy::ZapperController::moveRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x += enemy_model->move_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			if (currentPosition.x >= enemy_model->right_window.x)
			{
				//std::cout << "Move Down" << endl;
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setRefPosition(currentPosition);
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
		}

		void Enemy::ZapperController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += enemy_model->move_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			if (currentPosition.y >= enemy_model->getRefPosition().y + enemy_model->down_distance)
			{
				if (enemy_model->getRefPosition().x<=enemy_model->left_window.x)
				{
					enemy_model->setMovementDirection(MovementDirection::RIGHT);
				}
				else
				{
					enemy_model->setMovementDirection(MovementDirection::LEFT);
				}
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
		}
	}


}
