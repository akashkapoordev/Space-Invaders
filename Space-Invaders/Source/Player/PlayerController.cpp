#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Power/PowerupController.h"
#include <algorithm>

namespace Player
{
	using namespace Global;
	using namespace Bullet;

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView();
	}

	PlayerController::~PlayerController()
	{
		delete(player_model);
		delete(player_view);
	}

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize(this);
	}

	void PlayerController::update()
	{
		switch (player_model->getPlayerState())
		{
		case::Player::PlayerState::ALIVE:
			processInput();
			break;
		case::Player::PlayerState::FROZEN:
			updateFreezeDuration();
			break;
		}

		updatePowerDuration();
		updateFireDuration();
		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	void PlayerController::processInput()
	{
		Event::EventService* eventService = ServiceLocator::getInstance()->getEventService();
	/*	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			moveRight();
		}*/
		if (eventService->pressLeftKey() || eventService->pressAKey())
		{
			moveLeft();
		}

		if (eventService->pressRightKey() || eventService->pressDKey())
		{
			moveRight();
		}
		if (eventService->pressedRightMouseButton())
		{
			//fireBullet();
			processBulletFire();
		}
	}

	void PlayerController::moveLeft()
	{
		sf::Vector2f current_position = player_model->getPlayerPosition();

		current_position.x -= player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		current_position.x = std::max(current_position.x, player_model->left_window.x);
		player_model->setPlayerPosition(current_position);
	}

	void PlayerController::moveRight()
	{
		sf::Vector2f current_position = player_model->getPlayerPosition();

		current_position.x += player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		current_position.x = std::min(current_position.x, player_model->right_window.x);
		//cout << "current : " << current_position.x << endl;
		player_model->setPlayerPosition(current_position);
	}

	/*
		void PlayerController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(
				player_model->getPlayerPosition() + player_model->barrel_position_offset,
				Bullet::MovementDirection::UP, Bullet::BulletType::LASER,player_model->getEntityType);
		}*/

		bool PlayerController::bulletCollision(ICollider* other_collider)
		{
			if (player_model->isShieldEnabled())
			{
				return false;
			}

			BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);
			if(bullet_controller && bullet_controller->getOwnerEntityType() != Entity::EntityType::PLAYER)
				if (bullet_controller->getBulletType() == BulletType::FROST)
				{
					player_model->setPlayerState(PlayerState::FROZEN);
					player_model->elapsed_fire_duration = player_model->freeze_duration;
				}
				else
				{
					//ServiceLocator::getInstance()->getGameplayService()->reset();
					decreasePlayerLives();
					return true;
				}
			return false;
			
		}

		bool PlayerController::enmeyCollision(ICollider* other_collider)
		{
			if (player_model->isShieldEnabled())
			{
				return false;
			}
			Enemy::EnemyController* enmey_controller = dynamic_cast<Enemy::EnemyController*>(other_collider);
			if (enmey_controller)
			{
				//cout << "Enemy Collided" << "\n";
				ServiceLocator::getInstance()->getGameplayService()->reset();
				decreasePlayerLives();
				return true;
			}
			return false;
		}

		bool PlayerController::powerupCollision(ICollider* other_collider)
		{
			PowerUp::PowerupController* powerup_controller = dynamic_cast<PowerUp::PowerupController*>(other_collider);
			if (powerup_controller)
			{
				return true;
			}
			return false;
		}

		void PlayerController::updateFreezeDuration()
		{
			if (player_model->elapsed_freeze_duration > 0)
			{
				player_model->elapsed_freeze_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			}

			if (player_model->elapsed_freeze_duration <= 0)
			{
				player_model->setPlayerState(PlayerState::ALIVE);
			}
		}

		void PlayerController::freezPlayer()
		{
		
		}

		void PlayerController::updateFireDuration()
		{
			if (player_model->elapsed_fire_duration >= 0)
			{
				player_model->elapsed_fire_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			}
		}

		void PlayerController::processBulletFire()
		{
			if (player_model->elapsed_fire_duration > 0) return;

			if (player_model->isTrippleLaserEnabled())
			{
				fireBullet(true);
			}
			else
			{
				fireBullet();
			}

			if (player_model->isRapidFireEnabled())
			{
				player_model->elapsed_fire_duration = player_model->rapid_fire_cooldown_duration;

			}
			else
			{
				player_model->elapsed_fire_duration = player_model->fire_cooldown_duration;
			}
		}
		

		void PlayerController::fireBullet(bool b_tripple_laser)
		{
			sf::Vector2f bullet_position = player_model->getPlayerPosition() + player_model->barrel_position_offset;
			fireBullet(bullet_position);

			if (b_tripple_laser)
			{
				fireBullet(bullet_position + player_model->second_weapon_position_offset);
				fireBullet(bullet_position + player_model->third_weapon_position_offset);

			}
		}

		void PlayerController::fireBullet(sf::Vector2f position)
		{
			//std::cout << "Spwan Bullet" << '\n';
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(position,Bullet::MovementDirection::UP,Bullet::BulletType::LASER,player_model->getEntityType());
		}

		void PlayerController::updatePowerDuration()
		{
			if (player_model->elapsed_shield_duration > 0)
			{
				player_model->elapsed_shield_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			}
			if (player_model->elapsed_shield_duration <= 0)
			{
				disableShield();
			}
			if (player_model->elapsed_rapid_fire_duration > 0)
			{
				player_model->elapsed_rapid_fire_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

				if (player_model->elapsed_rapid_fire_duration <= 0)
					disableRapidFire();
			}

			if (player_model->elapsed_tripple_laser_duration > 0)
			{
				player_model->elapsed_tripple_laser_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

				if (player_model->elapsed_tripple_laser_duration <= 0)
					disableTrippleLaser();
			}
		}

	

	sf::Vector2f PlayerController::getPosition()
	{
		return player_model->getPlayerPosition();
	}

	const sf::Sprite& PlayerController::getCollisionSprite()
	{
		// TODO: insert return statement here
		return player_view->getPlayerSprite();
	}

	void PlayerController::onCollision(ICollider* other_collider)
	{
		if (powerupCollision(other_collider))
		{
			return;
		}
		if (bulletCollision(other_collider))
		{
			return;
		}
		enmeyCollision(other_collider);
		
	}



	void PlayerController::enableShield()
	{
		player_model->elapsed_shield_duration = player_model->shiled_powerup_duration;
		player_model->setShieldState(true);
	}
	void PlayerController::disableShield()
	{
		player_model->setShieldState(false);
	}

	void PlayerController::enableRapidFire()
	{
		player_model->elapsed_rapid_fire_duration = player_model->rapid_fire_powerup_duration;
		player_model->setRapidFireState(true);
	}

	void PlayerController::disableRapidFire()
	{
		player_model->setRapidFireState(false);
	}

	

	void PlayerController::enableTrippleLaser()
	{
		player_model->elapsed_tripple_laser_duration = player_model->tripple_laser_powerup_duration;
		player_model->setTrippleFireState(true);
	}
	void PlayerController::decreasePlayerLives()
	{
		cout << "Player Lives before : " << PlayerModel::player_lives << "\n";

		PlayerModel::player_lives -= 1;
		cout << "Player Lives : " << PlayerModel::player_lives << "\n";
		if (PlayerModel::player_lives <= 0)
		{
			reset();
		}
	}
	void PlayerController::disableTrippleLaser()
	{
		player_model->setTrippleFireState(false);
	}

	void PlayerController::reset()
	{
		player_model->reset();
	}
	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}
	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}
	
}
