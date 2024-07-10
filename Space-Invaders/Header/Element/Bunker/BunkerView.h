#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/UIService/UIElement/ImageView.h"


namespace Element
{
	namespace Bunker
	{
		class BunkerView
		{
		public:
			BunkerView();
			~BunkerView();

			void initialize(BunkerController* controller);
			void update();
			void render();
			const sf::Sprite& getsprite();


		private:
			const float bunker_height = 50.f;
			const float bunker_width = 50.f;

			sf::String bunker_texture_path;
			sf::Texture bunker_texture;
			sf::Sprite bunker_sprite;

			BunkerController* bunker_controller;
			sf::RenderWindow* game_window;


			UI::UIElement::ImageView* bunkerimage_view;

			void createUIElement();
			void initilizeImage();
			sf::String getBunkerTexturePath();
			void destroy();
		};

	}
}

