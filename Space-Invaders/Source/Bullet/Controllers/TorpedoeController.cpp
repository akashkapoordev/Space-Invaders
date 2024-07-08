#include "../../Header/Bullet/Controllers/TorpedoeController.h"
#include "../../Header/Bullet/BulletModel.h"
namespace Bullet
{
	namespace Controller
	{
		Bullet::Controller::TorpedoeController::TorpedoeController(BulletType type,Entity::EntityType ownertype):BulletController(type,ownertype)
		{
		}

		TorpedoeController::~TorpedoeController()
		{
		}

		void TorpedoeController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
		{
			
			BulletController::initialize(position, direction);
			bullet_model->setMovementSpeed(movement_speed);
		}

	}
}

