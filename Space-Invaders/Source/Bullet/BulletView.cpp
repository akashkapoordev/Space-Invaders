#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletController.h"


namespace Bullet
{
	using namespace Global;
	Bullet::BulletView::BulletView()
	{
		createUIElement();
	}

	BulletView::~BulletView()
	{
		destroy();
	}

	void BulletView::initialize(BulletController* controller)
	{
		bullet_controller = controller;
		//game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		//initializingSprite(bullet_controller->getBulletType());
		initilizeImage();
	}

	void BulletView::update()
	{
		bulletimage_view->setPosition(bullet_controller->getProjectilePosition());
		bulletimage_view->update();
		// bullet_sprite.setPosition(bullet_controller->getProjectilePosition());
	}

	void BulletView::render()
	{
		bulletimage_view->render();
		//game_window->draw(bullet_sprite);
	}

	void BulletView::createUIElement()
	{
		bulletimage_view = new UI::UIElement::ImageView();
	}

	void BulletView::initilizeImage()
	{
		bulletimage_view->initialize(getBulletTexturePath(), bullet_height, bullet_width, bullet_controller->getProjectilePosition());
	}

	sf::String BulletView::getBulletTexturePath()
	{
		switch (bullet_controller->getBulletType())
		{
		case Bullet::BulletType::LASER:
			return Global::Config::laser_bullet_texture_path;
			break;
		case Bullet::BulletType::TORPEDO:
			return Global::Config::torpedoe_texture_path;
			
			break;
		case Bullet::BulletType::FROST:
			return Global::Config::frost_beam_texture_path;
			break;
		}
	}

	sf::Sprite& BulletView::getSprite()
	{
		// TODO: insert return statement here
		bulletimage_view->getSprite();
	}

	void BulletView::destroy()
	{
		delete(bulletimage_view);
	}

	/*void BulletView::initializingSprite(BulletType type)
	{
		switch (type)
		{
		case Bullet::BulletType::LASER:
			if (bullet_texture.loadFromFile(Global::Config::laser_bullet_texture_path))
			{
				bullet_sprite.setTexture(bullet_texture);
				scalingSprite();
			}
			break;
		case Bullet::BulletType::TORPEDO:
			if (bullet_texture.loadFromFile(Global::Config::torpedoe_texture_path))
			{
				bullet_sprite.setTexture(bullet_texture);
				scalingSprite();
			}
			break;
		case Bullet::BulletType::FROST:
			if (bullet_texture.loadFromFile(Global::Config::frost_beam_texture_path))
			{
				bullet_sprite.setTexture(bullet_texture);
				scalingSprite();
			}
			break;
		}
	}*/

	//void BulletView::scalingSprite()
	//{
	//	bullet_sprite.setScale(
	//		static_cast<float>(bullet_width) / bullet_sprite.getTexture()->getSize().x,
	//		static_cast<float>(bullet_height) / bullet_sprite.getTexture()->getSize().y
	//	);
	//}

}
