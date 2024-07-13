#include <iostream>
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Element/ElementService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Power/PowerupService.h"
#include "../../Header/Collision/CollisionService.h"
#include "../../Header/AnimationSystem/AnimationService.h"

using namespace std;


namespace Global
{
	using namespace Graphic;
	using namespace Time;
	using namespace Event;
	using namespace Player;
	using namespace UI;
	using namespace Main;
	using namespace Sound;
	using namespace Bullet;


	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		time_service = nullptr;
		event_service = nullptr;
		gameplay_service = nullptr;
		player_service = nullptr;
		enemy_service = nullptr;
		element_service = nullptr;
		sound_service = nullptr;
		bullet_service = nullptr;
		powerup_service = nullptr;
		collision_service = nullptr;
		animation_service = nullptr;

		ui_service = nullptr;
		createServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		time_service->initialize();
		event_service->initialize();
		gameplay_service->initialize();
		player_service->initialize();
		enemy_service->initialize();
		element_service->initialize();
		sound_service->initialize();
		bullet_service->initialize();
		powerup_service->initialize();
		collision_service->initilize();
		animation_service->initialize();

		ui_service->initialize();

	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		time_service->update();
		event_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->update();
			player_service->update();
			enemy_service->update();
			element_service->update();
			bullet_service->update();
			powerup_service->update();
			collision_service->update();
			animation_service->update();
		}
		ui_service->update();

	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->render();
			player_service->render();
			enemy_service->render();
			element_service->render();
			bullet_service->render();
			powerup_service->render();
			animation_service->render();



		}
		ui_service->render();

		
	}

	Graphic::GraphicService* ServiceLocator::getGraphicService()
	{
		return graphic_service;
	}

	Event::EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	Player::PlayerService* ServiceLocator::getPlayerService()
	{
		return player_service;
	}

	Time::TimeService* ServiceLocator::getTimeService()
	{
		return time_service;
	}

	Enemy::EnemyService* ServiceLocator::getEnemyService()
	{
		return enemy_service;
	}

	Gameplay::GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplay_service;
	}

	Element::ElementService* ServiceLocator::getElementService()
	{
		return element_service;
	}

	Sound::SoundService* ServiceLocator::getSoundService()
	{
		return sound_service;
	}

	Bullet::BulletService* ServiceLocator::getBulletService()
	{
		return bullet_service;
	}

	PowerUp::PowerupService* ServiceLocator::getPowerupService()
	{
		return powerup_service;
	}

	Collision::CollisionService* ServiceLocator::getCollisionService()
	{
		return collision_service;
	}

	Animation::AnimationService* ServiceLocator::getAnimationService()
	{
		return animation_service;
	}

	UI::UIService* ServiceLocator::uiService()
	{
		return ui_service;
	}


	void ServiceLocator::createServices()
	{
		graphic_service = new Graphic::GraphicService();
		time_service = new Time::TimeService();
		event_service = new Event::EventService();
		player_service = new Player::PlayerService();
		enemy_service = new Enemy::EnemyService();
		gameplay_service = new Gameplay::GameplayService();
		element_service = new Element::ElementService();
		sound_service = new Sound::SoundService();
		bullet_service = new Bullet::BulletService();
		powerup_service = new PowerUp::PowerupService();
		collision_service = new Collision::CollisionService();
		animation_service = new Animation::AnimationService();
		ui_service = new UI::UIService();


	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(time_service);
		delete(event_service);
		delete(player_service);
		delete(enemy_service);
		delete(gameplay_service);
		delete(element_service);
		delete(sound_service);
		delete(bullet_service);
		delete(powerup_service);
		delete(collision_service);
		delete(animation_service);

		delete(ui_service);


		

	}

}
