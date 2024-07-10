#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletModel.h";
#include "../../Header/Bullet/BulletView.h";
#include "../../Header/Global/Config.h";
#include "../../Header/Global/ServiceLocator.h";
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Element/Bunker/BunkerController.h"



namespace Bullet
{
	using namespace Global;
	using namespace Entity;
	void Bullet::BulletController::updateProjectilePosition()
	{
		switch (bullet_model->getMovementDirection())
		{
		case Bullet::MovementDirection::UP:
			moveUp();
			break;
		case Bullet::MovementDirection::DOWM:
			moveDown();
			break;
		}
	}

	void BulletController::moveUp()
	{
		sf::Vector2f currentPosition = bullet_model->getPosition();
		currentPosition.y -= bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setPosition(currentPosition);
	}

	void BulletController::moveDown()
	{
		sf::Vector2f currentPosition = bullet_model->getPosition();

		currentPosition.y += bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setPosition(currentPosition);
	}

	void BulletController::handleOutOfBounds()
	{
		sf::Vector2f bulletPosition = getProjectilePosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (bulletPosition.x < 0 || bulletPosition.x > windowSize.x ||
			bulletPosition.y < 0 || bulletPosition.y > windowSize.y)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	
	}

	void BulletController::processBulletCollision(ICollider* other_collider)
	{
		BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);
		if (bullet_controller)
		{
			cout << "Destroying bullet" << '\n';
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	void BulletController::processEnemyCollision(ICollider* other_collider)
	{
		Enemy::EnemyController* enemy_controller = dynamic_cast<Enemy::EnemyController*>(other_collider);
		if (enemy_controller && getOwnerEntityType() != EntityType::ENEMY)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	void BulletController::processPlayerCollision(ICollider* other_collider)
	{
		Player::PlayerController* player_controller = dynamic_cast<Player::PlayerController*>(other_collider);
		if (player_controller && getOwnerEntityType() != EntityType::PLAYER)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	void BulletController::processBunkerCollision(ICollider* other_collider)
	{
		Element::Bunker::BunkerController* bunker_controller = dynamic_cast<Element::Bunker::BunkerController*>(other_collider);
		if (bunker_controller)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	BulletController::BulletController(BulletType type,Entity::EntityType owner_type)
	{
		bullet_model = new BulletModel(type,owner_type);
		bullet_view = new BulletView();
	}

	BulletController::~BulletController()
	{
		delete(bullet_model);
		delete(bullet_view);
	}

	void BulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
	{
		bullet_model->initialize(position, direction);
		bullet_view->initialize(this);
	}

	void BulletController::update()
	{
		updateProjectilePosition();
		bullet_view->update();
		//bullet_model->update();
		handleOutOfBounds();
	}

	void BulletController::render()
	{
		//bullet_model->render();
		bullet_view->render();
	}

	sf::Vector2f BulletController::getProjectilePosition()
	{
		return bullet_model->getPosition();
	}

	BulletType BulletController::getBulletType()
	{
		return bullet_model->getBulletType();
	}

	Entity::EntityType BulletController::getOwnerEntityType()
	{
		return bullet_model->getOwnerEntityType();
	}

	const sf::Sprite& BulletController::getCollisionSprite()
	{
		// TODO: insert return statement here
		return bullet_view->getSprite();
	}

	void BulletController::onCollision(ICollider* other_collider)
	{
		processPlayerCollision(other_collider);
		processEnemyCollision(other_collider);
		processBunkerCollision(other_collider);
		processBulletCollision(other_collider);
	}

}
