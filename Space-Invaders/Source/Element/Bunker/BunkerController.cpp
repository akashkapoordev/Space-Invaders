#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Element
{

	namespace Bunker
	{
		using namespace Bullet;
		using namespace Global;
		Element::Bunker::BunkerController::BunkerController()
		{
			bunker_view = new BunkerView();
		}

		BunkerController::~BunkerController()
		{
			delete(bunker_view);
		}

		void BunkerController::initialize(Bunker::BunkerData data)
		{
			bunker_data = data;
			bunker_view->initialize(this);
		}

		void BunkerController::update()
		{
			bunker_view->update();
		}

		void BunkerController::render()
		{
			bunker_view->render();
		}

		sf::Vector2f BunkerController::getBunkerPosition()
		{
			return bunker_data.position;
		}

		const sf::Sprite& BunkerController::getCollisionSprite()
		{
			// TODO: insert return statement here
			return bunker_view->getsprite();
		}

		void BunkerController::onCollision(ICollider* other_collider)
		{
			BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);
			if (bullet_controller && bullet_controller->getBulletType() == BulletType::TORPEDO)
			{
				ServiceLocator::getInstance()->getElementService()->destroyBunker(this);
			}
		}


		

	}
}
