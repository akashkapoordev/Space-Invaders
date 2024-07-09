#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletController.h"

namespace Enemy
{
	using namespace Global;
	using namespace Controller;
	namespace Controller
	{
		Enemy::Controller::UFOController::UFOController(EnemyType type):EnemyController(type)
		{
		}

		Enemy::Controller::UFOController::~UFOController()
		{
		}

		void Enemy::Controller::UFOController::initialize()
		{
			EnemyController::initialize();
		}

		void Enemy::Controller::UFOController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case MovementDirection::LEFT:
				moveLeft();
			case MovementDirection::RIGHT:
				moveRight();
			}
		}

		void Enemy::Controller::UFOController::moveLeft()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x -= enemy_model->move_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			enemy_model->setEnemyPosition(currentPosition);
			
		}

		void Enemy::Controller::UFOController::moveRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x += enemy_model->move_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			enemy_model->setEnemyPosition(currentPosition);
		}

		void Enemy::Controller::UFOController::fireBullet()
		{
		}

		PowerUp::PowerType Enemy::Controller::UFOController::getRandomPower()
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			//We add '1'  to OutscalBomb below because enum has a 0 index, making the bomb number 3, we need to add 1 to make it 4 

			int random_value = std::rand() % (static_cast<int>(PowerUp::PowerType::OUTSCAL_BOMB) + 1);
			return static_cast<PowerUp::PowerType>(random_value);
		}

		void UFOController::onCollision(ICollider* other_collider)
		{
			Enemy::EnemyController::onCollision(other_collider);
			Bullet::BulletController* bullet_controller = dynamic_cast<Bullet::BulletController*>(bullet_controller);
			if (bullet_controller && bullet_controller->getOwnerEntityType() != Entity::EntityType::ENEMY)
			{
				ServiceLocator::getInstance()->getPowerupService()->spawnPowerUp(enemy_model->getEnemyPosition(), getRandomPower());
				return;
			}

		}

	}
}

