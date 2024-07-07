#pragma once
#include <vector>

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;
	class EnemyService
	{
	public:
		EnemyService();
		~EnemyService();

		void initialize();
		void update();
		void render();

		EnemyController* spawnEnemy();
		
	
		void destroyEnemy(EnemyController* enemy_controller);
		void reset();
	private:
		const float spawn_delay = 3.f;
		float spawn_timer;
		//EnemyController* enemy_controller;
		std::vector<EnemyController*> enemy_list;
		void updateTimer();
		void processSpawnTimer();
		void Destroy();

		EnemyType getRandomEnemyType();
		EnemyController* createEnemy(EnemyType type); 
	};

}

