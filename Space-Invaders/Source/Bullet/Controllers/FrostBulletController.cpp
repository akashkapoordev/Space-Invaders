#include "../../Header/Bullet/Controllers/FrostBulletController.h"
#include "../../Header/Bullet/BulletModel.h"


namespace Bullet
{
	namespace Controller
	{
		FrostBulletController::FrostBulletController(BulletType type,Entity::EntityType ownertype):BulletController(type,ownertype)
		{

		}
		Bullet::Controller::FrostBulletController::~FrostBulletController()
		{
		}

		void FrostBulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			bullet_model->setMovementSpeed(movement_speed);
		}

	}
}
