#include "../../Header/Power/PowerupView.h"
#include "../../Header/Power/PowerupController.h"
#include "../../Header/Power/PowerConfig.h"
#include "../../Header/Power/PowerupModel.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"


namespace PowerUp
{
	using namespace Global;
	using namespace UI;
	using namespace UIElement;

	PowerupView::PowerupView()
	{
		createUIElements();

	}

	PowerUp::PowerupView::~PowerupView()
	{
		destroy();
	}

	void PowerUp::PowerupView::initialize(PowerupController* controller)
	{
		power_controller = controller;
		//game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeImage();
		//initialSprite(power_controller->getPowerType());
	}

	void PowerUp::PowerupView::update()
	{
		powerup_image->setPosition(power_controller->getCollectiblePosition());
		powerup_image->update();
	}

	void PowerUp::PowerupView::render()
	{
		powerup_image->render();
	}

	const sf::Sprite& PowerupView::getPowerUpSprite()
	{
		// TODO: insert return statement here
		powerup_image->getSprite();
	}

	/*void PowerupView::initialSprite(PowerType type)
	{
		switch (type)
		{
		case PowerUp::PowerType::SHIELD:
			if (powerup_texture.loadFromFile(Config::shield_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleSprite();
			}
			break;
		case PowerUp::PowerType::RAPID_FIRE:
			if (powerup_texture.loadFromFile(Config::rapid_fire_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleSprite();
			}
			break;
		case PowerUp::PowerType::TRIPPLE_LASER:
			if (powerup_texture.loadFromFile(Config::tripple_laser_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleSprite();
			}
			break;
		case PowerUp::PowerType::OUTSCAL_BOMB:
			if (powerup_texture.loadFromFile(Config::outscal_bomb_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleSprite();
			}
			break;
		}
	}*/

	//void PowerupView::scaleSprite()
	//{
	//	powerup_sprite.setScale(
	//		static_cast<float>(powerup_width) / powerup_sprite.getTexture()->getSize().x,
	//		static_cast<float>(powerup_height) / powerup_sprite.getTexture()->getSize().y
	//	);
	//}

	void PowerupView::createUIElements()
	{
		powerup_image = new UI::UIElement::ImageView();

	}

	void PowerupView::initializeImage()
	{
		powerup_image->initialize(powerup_texture_path(), powerup_height, powerup_width, power_controller->getCollectiblePosition());
	}

	sf::String PowerupView::powerup_texture_path()
	{
		switch (power_controller->getPowerType())
		{
		case PowerUp::PowerType::SHIELD:
			return Config::shield_texture_path;
			break;
		case PowerUp::PowerType::RAPID_FIRE:
			return Config::rapid_fire_texture_path;
			break;
		case PowerUp::PowerType::TRIPPLE_LASER:
			return Config::tripple_laser_texture_path;
			break;
		case PowerUp::PowerType::OUTSCAL_BOMB:
			return Config::outscal_bomb_texture_path;
			break;
		}
	}

	void PowerupView::destroy()
	{
		delete(powerup_image);
	}



}
