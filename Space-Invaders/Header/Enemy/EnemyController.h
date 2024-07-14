#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Collision/ICollider.h"

namespace Enemy
{
	class EnemyModel;
	class EnemyView;
	enum class EnemyType;
	enum class EnemyState;
	class EnemyController:public Collision::ICollider
	{
	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();

		

		 virtual void move() = 0;

		

		EnemyType getEnemyType();
		EnemyState getEnemyState();
		sf::Vector2f getEnemyPosition();

		void destroy();

	protected:
		EnemyModel* enemy_model;
		EnemyView* enemy_view;
		EnemyType type;
		sf::Vector2f getRandomInitialPosition();
		void handleOutOfBounds();

		float rate_of_fire = 3.f;
		float elapsed_fire_duration;
		void updateFireTime();
		void processFireTime();
		virtual void fireBullet() = 0;
		const sf::Sprite& getCollisionSprite() override;
		void onCollision(ICollider* other_collider) override;
	};
}


