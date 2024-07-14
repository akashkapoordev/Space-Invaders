#include "../../Header/UIService/UIElement/ButtonView.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Sound/SoundService.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Event;
		using namespace Global;

		void ButtonView::printButtonClicked()
		{
			printf("Clicked %s\n", button_title.toAnsiString().c_str());
		}
		void ButtonView::handleButtonInteraction()
		{
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));
			if (clickedButton(&image_sprite, mouse_position))
			{
				if (callback_function)
				{
					callback_function();
					//printf("HI");
				}
			}
		}
		bool ButtonView::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
		{
			Event::EventService* event_service = ServiceLocator::getInstance()->getEventService();
			return event_service->pressedLeftMouseButton() && button_sprite->getGlobalBounds().contains(mouse_position);
		}
		ButtonView::ButtonView()
		{
		}
		ButtonView::~ButtonView()
		{
		}
		void ButtonView::initialize(sf::String title, sf::String texture_path, float button_width, float button_height, sf::Vector2f position)
		{
			ImageView::initialize(texture_path, button_width, button_height, position);
			button_title = title;

		}
		void ButtonView::update()
		{
			ImageView::update();
			if (ui_state == UIState::VISIBLE)
			{
				handleButtonInteraction();
			}
		}
		void ButtonView::render()
		{
			ImageView::render();
		}
		void ButtonView::registerCallbackFuntion(CallbackFunction button_callback)
		{
			callback_function = button_callback;
		}
	}
}