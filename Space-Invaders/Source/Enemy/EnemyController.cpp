#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Bullet/BulletController.h"



namespace Enemy
{
	using namespace Global;
	EnemyController::EnemyController(EnemyType type)
	{
		enemy_model = new EnemyModel(type);
		enemy_view = new EnemyView();
	}

	EnemyController::~EnemyController()
	{
		delete(enemy_model);
		delete(enemy_view);
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_model->setEnemyPosition(getRandomInitialPosition());
		enemy_view->initialize(this);
	}

	void EnemyController::update()
	{
		updateFireTime();
		processFireTime();
	
		move();
		enemy_view->update();
		handleOutOfBounds();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}

	void EnemyController::destroy()
	{
		ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
	}



	//void EnemyController::move()
	//{
	//	switch (enemy_model->getMovementDirection())
	//	{
	//	case Enemy::MovementDirection::LEFT:
	//		moveLeft();
	//		break;
	//	case Enemy::MovementDirection::RIGHT:
	//		moveRight();
	//		break;
	//	case Enemy::MovementDirection::DOWN:
	//		moveDown();
	//		break;
	//	}
	//}

	//void EnemyController::moveLeft()
	//{
	//	sf::Vector2f current_position = enemy_model->getEnemyPosition();
	//	current_position.x -= enemy_model->move_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

	//	if (current_position.x <= enemy_model->left_window.x)
	//	{
	//		enemy_model->setMovementDirection(MovementDirection::DOWN);
	//		enemy_model->setRefPosition(current_position);
	//	}
	//	else
	//	{
	//		enemy_model->setEnemyPosition(current_position);
	//	}
	//}

	//void EnemyController::moveRight()
	//{
	//	sf::Vector2f current_position = enemy_model->getEnemyPosition();
	//	current_position.x += enemy_model->move_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

	//	if (current_position.x >= enemy_model->right_window.x)
	//	{
	//		enemy_model->setMovementDirection(MovementDirection::DOWN);
	//		enemy_model->setRefPosition(current_position);
	//	}
	//	else
	//	{
	//		enemy_model->setEnemyPosition(current_position);
	//	}
	//}

	//void EnemyController::moveDown()
	//{
	//	sf::Vector2f current_position = enemy_model->getEnemyPosition();
	//	current_position.y += enemy_model->move_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

	//	if (current_position.y >= enemy_model->getRefPosition().y + enemy_model->down_distance)
	//	{
	//		if (enemy_model->getRefPosition().x <= enemy_model->left_window.x)
	//		{
	//			enemy_model->setMovementDirection(MovementDirection::RIGHT);
	//			
	//		}
	//		else
	//		{
	//			enemy_model->setMovementDirection(MovementDirection::LEFT);

	sf::Vector2f EnemyController::getRandomInitialPosition()
	{
		float x_offset_distance = (std::rand() % static_cast<int>(enemy_model->right_window.x - enemy_model->left_window.x));
		float x_position = enemy_model->left_window.x + x_offset_distance;
		float y_position = enemy_model->left_window.y;

		return sf::Vector2f(x_position, enemy_model->Y_axis);
		//return static_cast<
	}

	void EnemyController::handleOutOfBounds()
	{
		sf::Vector2f enemy_position = enemy_model->getEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();


		if (enemy_position.x < 0 || enemy_position.x > windowSize.x || enemy_position.y < 0 || enemy_position.y > windowSize.y) {
			ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
		}
	}
	void EnemyController::updateFireTime()
	{
		elapsed_fire_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}
	void EnemyController::processFireTime()
	{
		if (elapsed_fire_duration>= rate_of_fire)
		{
			fireBullet(); 
			elapsed_fire_duration = 0;

		}
	
	}
	const sf::Sprite& EnemyController::getCollisionSprite()
	{
		// TODO: insert return statement here
		return enemy_view->getEnenmySprite();
	}

	void EnemyController::onCollision(ICollider* other_collider)
	{
		Bullet::BulletController* bullet_controller = dynamic_cast<Bullet::BulletController*>(other_collider);
		if (bullet_controller && bullet_controller->getOwnerEntityType() != Entity::EntityType::ENEMY)
		{
			destroy();
			return;
		}
	}

	EnemyType EnemyController::getEnemyType()
	{
		return enemy_model->getEnemyType();
	}
	EnemyState EnemyController::getEnemyState()
	{
		return enemy_model->getEnemyState();
	}

	
}
