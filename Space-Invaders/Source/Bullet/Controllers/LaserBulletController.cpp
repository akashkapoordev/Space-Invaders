#include "../../Header/Bullet/Controllers/LaserBulletController.h"


namespace Bullet
{
	namespace Controller
	{
		Bullet::Controller::LaserBulletController::LaserBulletController(BulletType type,Entity::EntityType ownertype):BulletController(type,ownertype)
		{

		}
		LaserBulletController::~LaserBulletController()
		{
		}
		void LaserBulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
		{
			printf("Initialize Bullet");
			BulletController::initialize(position,direction);
		}
	}
}

