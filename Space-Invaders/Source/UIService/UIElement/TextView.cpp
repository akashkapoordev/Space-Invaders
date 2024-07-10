#include "../../Header/UIService/UIElement/TextView.h"
#include "../../Header/Global/Config.h"
#include <iostream>

namespace UI
{
	namespace UIElement
	{
		using namespace Global;
		sf::Font TextView::font_bubble_bobble;
		sf::Font TextView::font_ds_digib;
		TextView::TextView()
		{
		}
		TextView::~TextView()
		{
		}
		void TextView::initializeTextView()
		{
			loadFont();
		}
		void TextView::initialize(sf::String text_value, sf::Vector2f position, FontType font_type, int font_size, sf::Color color)
		{
			UIView::initialize();
			//initializeTextView();
			setText(text_value);
			setFontPosition(position);
			setFont(font_type);
			setFontSize(font_size);
			setFontColor(color);
		}
		void TextView::update()
		{
			UIView::update();
		}
		void TextView::render()
		{
			UIView::render();
			if (ui_state == UIState::VISIBLE)
			{
				//std::cout << "Draw Text" << "\n";
				game_window->draw(font_text);
			}
		}
		void TextView::setText(sf::String text)
		{
			font_text.setString(text);
		}
		void TextView::alignCenter()
		{
			float x_position = (game_window->getSize().x - font_text.getLocalBounds().width) / 2;
			float y_position = font_text.getGlobalBounds().getPosition().y;

			font_text.setPosition(sf::Vector2f(x_position, y_position));
		}
		void TextView::loadFont()
		{
			font_bubble_bobble.loadFromFile(Config::bubble_bobble_font_path);
			font_ds_digib.loadFromFile(Config::DS_DIGIB_font_path);
		}
		void TextView::setFont(FontType type)
		{
			switch (type)
			{
			case UI::UIElement::FontType::BUBBLE_BOBBLE:
				font_text.setFont(font_bubble_bobble);
				break;
			case UI::UIElement::FontType::DS_DIGIB:
				font_text.setFont(font_ds_digib);
				break;
			}
		}
		void TextView::setFontSize(int size)
		{
			font_text.setCharacterSize(size);
		}
		void TextView::setFontPosition(sf::Vector2f position)
		{
			font_text.setPosition(position);
		}
		void TextView::setFontColor(sf::Color color)
		{
			font_text.setFillColor(color);
		}
	}
}