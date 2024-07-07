#include "../../Header/Player/PlayerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/Config.h"


namespace Player
{
	using namespace Global;
	PlayerView::PlayerView()
	{
		createUIElement();
	}

	PlayerView::~PlayerView() {
		destroy();
	};

	void PlayerView::initialize(PlayerController* controller)
	{
		player_controller = controller;
		//game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		//initializePlayerSprite();
		initilizeImage();
		
	}

	void PlayerView::update()
	{
		player_image->setPosition(player_controller->getPosition());
		player_image->update();
	}

	void PlayerView::render()
	{
		player_image->render();
	}

	//void PlayerView::initializePlayerSprite()
	//{
	//	if (player_texture.loadFromFile(Config::player_texture_path))
	//	{
	//		player_sprite.setTexture(player_texture);
	//		scaleSprite();
	//	}
	//}

	//void PlayerView::scaleSprite()
	//{
	//	player_sprite.setScale(
	//		static_cast<float>(sprite_width) / player_sprite.getTexture()->getSize().x,
	//		static_cast<float>(sprite_height) / player_sprite.getTexture()->getSize().y
	//	);
	//}

	void PlayerView::createUIElement()
	{
		player_image = new UI::UIElement::ImageView();
	}


	void PlayerView::initilizeImage()
	{
		player_image->initialize(getPlayerTexturePath(), sprite_height, sprite_width, player_controller->getPosition());
	}

	sf::String PlayerView::getPlayerTexturePath()
	{
		return Config::player_texture_path;
	}

	void PlayerView::destroy()
	{
		delete(player_image);
	}

	const sf::Sprite& PlayerView::getPlayerSprite()
	{
		return player_image->getSprite();
	}
}
