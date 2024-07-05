#include "../../Header/Gameplay/GameplayView .h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header//Graphic/GraphicService.h"
#include "../../Header/Global/Config.h"


namespace Gameplay
{
	using namespace Global;
	using namespace Graphic;
	Gameplay::GameplayView::GameplayView()
	{
		//game_window = nullptr;
		createUIElement();
	}

	Gameplay::GameplayView::~GameplayView()
	{
		destroy();
	}

	void Gameplay::GameplayView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		//initializeBackgroundImage();
		initilizeImage();
	}

	void Gameplay::GameplayView::update()
	{
		//gameplayimage_view->setPosition(background_position);
		gameplayimage_view->update();
	}

	void Gameplay::GameplayView::render()
	{
		gameplayimage_view->render();
		//game_window->draw(background_sprite);
	}

	void GameplayView::createUIElement()
	{
		gameplayimage_view = new UI::UIElement::ImageView();
	}

	sf::String GameplayView::getGameplayTexturePath()
	{
		return Config::background_texture_path;
	}

	void GameplayView::initilizeImage()
	{
		gameplayimage_view->initialize(getGameplayTexturePath(), game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0,0));
	}

	void GameplayView::destroy()
	{
		delete(gameplayimage_view);

	}
	//void GameplayView::initializeBackgroundImage()
	//{
	//	if (background_texture.loadFromFile(Config::background_texture_path))
	//	{
	//		background_sprite.setTexture(background_texture);
	//		setBackgroundScale();
	//	}
	//}

	//void GameplayView::setBackgroundScale()
	//{
	//	background_sprite.setScale(
	//		static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
	//		static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
	//	);
	//}

}
