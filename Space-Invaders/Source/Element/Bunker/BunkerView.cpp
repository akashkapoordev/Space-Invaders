#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h";


namespace Element
{
	namespace Bunker
	{
		using namespace Global;

		Element::Bunker::BunkerView::BunkerView()
		{
			//bunker_controller = nullptr;
			createUIElement();
		}
		BunkerView::~BunkerView()
		{
			//delete(bunker_controller);
			destroy();
		}

		void BunkerView::initialize(BunkerController* controller)
		{
			bunker_controller = controller;
			//game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			//initializeSprite();
			initilizeImage();
		}
		void BunkerView::update()
		{
			bunkerimage_view->setPosition(bunker_controller->getBunkerPosition());
			bunkerimage_view->update();
			// bunker_sprite.setPosition(bunker_controller->getBunkerPosition());
		}
		void BunkerView::render()
		{
			bunkerimage_view->render();
			// game_window->draw(bunker_sprite);
		}
		const sf::Sprite& BunkerView::getsprite()
		{
			// TODO: insert return statement here
			return bunkerimage_view->getSprite();
		}
	/*	void BunkerView::initializeSprite()
		{
			if (bunker_texture.loadFromFile(Config::bunker_texture_path))
			{
				bunker_sprite.setTexture(bunker_texture);
				scaleSprite();
			}
		}*/
	/*	void BunkerView::scaleSprite()
		{
			bunker_sprite.setScale(
				static_cast<float>(bunker_width) / bunker_sprite.getTexture()->getSize().x,
				static_cast<float>(bunker_height) / bunker_sprite.getTexture()->getSize().y
			);
		}*/
		void BunkerView::createUIElement()
		{
			bunkerimage_view = new UI::UIElement::ImageView();
		}

		void BunkerView::initilizeImage()
		{
			bunkerimage_view->initialize(getBunkerTexturePath(), bunker_height, bunker_width, bunker_controller->getBunkerPosition());
		}

		sf::String BunkerView::getBunkerTexturePath()
		{
			return Config::bunker_texture_path;
		}

		void BunkerView::destroy()
		{
			delete(bunkerimage_view);
		}
	}
}


