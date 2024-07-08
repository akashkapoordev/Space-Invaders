#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Entity/EntityConfig.h"



namespace Bullet
{
	class BulletController;
	enum class ButtonType;
	enum class MovementDirection;
	class BulletService
	{
	public:
		BulletService();
		virtual ~BulletService();

		void initialize();
		void update();
		void render();

		BulletController* spawnBullet(sf::Vector2f psoition, MovementDirection direction, BulletType type, Entity::EntityType owner_type);
		void destroyBullet(BulletController* controller);
		void reset();

	private:
		std::vector<IProjectile*> bullet_list;
		std::vector<IProjectile*> flagged_bullets;
		BulletController* createBullet(BulletType type,Entity::EntityType owner_type);
		bool isBulletVaild(int index_i, std::vector<IProjectile*>& bullet_list);
		void destroyFlaggedBullet();
		void destroy();
	};
}


