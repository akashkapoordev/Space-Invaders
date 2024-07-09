#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header//Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h";
#include "../../Header/Enemy/Controllers/UFOController.h";


namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;

	
	EnemyService::EnemyService()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService()
	{
		Destroy();
	}

	void EnemyService::initialize()
	{
		spawn_timer = spawn_delay;

	}

	void EnemyService::update()
	{
		updateTimer();
		processSpawnTimer();

		for (int i = 0;i < enemy_list.size();i++)
		{
			enemy_list[i]->update();
			destroyFlaggedEnemies();
		}
		
	}

	void EnemyService::render()
	{
		for (int i = 0;i < enemy_list.size();i++)
		{
			enemy_list[i]->render();
		}
		//enemy_controller->render();
	}
	EnemyController* EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
		enemy_controller->initialize();
		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<Collision::ICollider*>(enemy_controller));
		enemy_list.push_back(enemy_controller);
		return enemy_controller;
	}

	void seedValue()
	{
		 std::srand(static_cast<unsigned>(std::time(nullptr)));

	}
	//void EnemyService::spawnEnemy()
	//{
	//	//EnemyController* enemy_controller; /*= new EnemyController();*/
	//	//enemy_controller->initialize();
	//	//enemy_list.push_back(enemy_controller);

	//}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		dynamic_cast<Collision::ICollider*>(enemy_controller)->disableCollision();
		flagged_enemy_list.push_back(enemy_controller);
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
		//delete(enemy_controller);
	}

	void EnemyService::reset()
	{
		Destroy();
		spawn_timer = 0;
	}

	void EnemyService::updateTimer()
	{
		spawn_timer = spawn_timer + ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyService::processSpawnTimer()
	{
		if (spawn_timer >= spawn_delay)
		{
			spawnEnemy();
			spawn_timer = 0;
		}
	}

	void EnemyService::Destroy()
	{
		for (int i = 0;i < enemy_list.size();i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(enemy_list[i]));
			delete(enemy_list[i]);
		}
		enemy_list.clear();
		//delete(enemy_controller);
	}
	EnemyType EnemyService::getRandomEnemyType()
	{
		int random_enemy = std::rand() % 3;
		return static_cast<Enemy::EnemyType>(random_enemy);
	}
	EnemyController* EnemyService::createEnemy(EnemyType type)
	{
		switch (type)
		{
		case Enemy::EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER);
			break;
		case Enemy::EnemyType::SUBZERO:
			return new SubZeroController(Enemy::EnemyType::SUBZERO);
			break;
		case Enemy::EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO);
			break;
		case Enemy::EnemyType::THUNDER_SNAKE:
			break;
		default:
			break;
		}
	}
	void EnemyService::destroyFlaggedEnemies()
	{
		for (int i = 0;i < flagged_enemy_list.size();i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(flagged_enemy_list[i]));
			delete(flagged_enemy_list[i]);
		}
		flagged_enemy_list.clear();
	}
}


