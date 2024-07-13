#include "../../Header/Power/PowerupController.h"
#include "../../Header/Power/PowerupModel.h"
#include "../../Header/Power/PowerupView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"

namespace PowerUp
{
	using namespace Global;
	using namespace Player;
	PowerUp::PowerupController::PowerupController(PowerType type)
	{
		powerup_model = new PowerupModel(type);
		powerup_view = new PowerupView();
	}

	PowerupController::~PowerupController()
	{
		delete(powerup_model);
		delete(powerup_view);
	}
	
	void PowerupController::initialCollectible(sf::Vector2f collectiblePosition)
	{
		powerup_model->initialize(collectiblePosition);
		powerup_view->initialize(this);
	}

	void PowerupController::update()
	{
		UpdatePowerPosition();
		powerup_view->update();
		handleOfBounds();

	}

	void PowerupController::render()
	{
		powerup_view->render();
	}

	void PowerupController::onCollected()
	{
	}

	sf::Vector2f PowerupController::getCollectiblePosition()
	{
		return powerup_model->getCollectiblePosition();
	}

	PowerType PowerupController::getPowerType()
	{
		return powerup_model->getPowerType();
	}

	void PowerupController::UpdatePowerPosition()
	{
		sf::Vector2f currentPosition = powerup_model->getCollectiblePosition();
		currentPosition.y += powerup_model->getMovementSpeed()* ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		powerup_model->setCollectiblePosition(currentPosition);
	}

	void PowerupController::handleOfBounds()
	{
		sf::Vector2f collectiblePosition = getCollectiblePosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (collectiblePosition.x < 0 || collectiblePosition.x > windowSize.x ||
			collectiblePosition.y < 0 || collectiblePosition.y > windowSize.y)
		{
			//ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
			ServiceLocator::getInstance()->getPowerupService()->destroyPowerup(this);
		}
	}
	const sf::Sprite& PowerupController::getCollisionSprite()
	{
		// TODO: insert return statement here
		return powerup_view->getPowerUpSprite();
	}
	void PowerupController::onCollision(ICollider* other_collider)
	{
		PlayerController* player_controller = dynamic_cast<PlayerController*>(other_collider);
		if (player_controller)
		{
			onCollected();
			ServiceLocator::getInstance()->getPowerupService()->destroyPowerup(this);
		}
	}
}


