
#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/UIService/UIService.h"
#include "../../Header/Enemy/EnemyService.h";
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Element/ElementService.h";
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Power/PowerupService.h"
#include "../../Header/Collision/CollisionService.h"


namespace Global
{
	class GraphicService;
	class EventService;
	class PlayerService;
	class TimeService;
	class UIService;
	class EnemyService;
	class GameplayService;
	class ElementService;
	class SoundService;
	class BulletService;
	class PowerupService;
	class CollisionService;


	class ServiceLocator
	{
	public:
		ServiceLocator();
		~ServiceLocator();

		static ServiceLocator* getInstance();


		void initialize();
		void update();
		void render();

		Graphic::GraphicService* getGraphicService();
		Event::EventService* getEventService();
		UI::UIService* uiService();
		Player::PlayerService* getPlayerService();
		Time::TimeService* getTimeService();
		Enemy::EnemyService* getEnemyService();
		Gameplay::GameplayService* getGameplayService();
		Element::ElementService* getElementService();
		Sound::SoundService* getSoundService();
		Bullet::BulletService* getBulletService();
		PowerUp::PowerupService* getPowerupService();
		Collision::CollisionService* getCollisionService();

	private:
		Graphic::GraphicService* graphic_service;
		Event::EventService* event_service;
		UI::UIService* ui_service;
		Player::PlayerService* player_service;
		Enemy::EnemyService* enemy_service;
		Gameplay::GameplayService* gameplay_service;
		Element::ElementService* element_service;
		Time::TimeService* time_service;
		Sound::SoundService* sound_service;
		Bullet::BulletService* bullet_service;
		PowerUp::PowerupService* powerup_service;
		Collision::CollisionService* collision_service;
		void createServices();
		void clearAllServices();

	};

}
