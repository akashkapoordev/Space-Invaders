#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UIService/UIElement/ImageView.h"


namespace Player
{
	class PlayerController;


	class PlayerView
	{
	public:
		PlayerView();
		~PlayerView();

		void initialize(PlayerController* player_controller);
		void update();
		void render();

	private:

		const sf::String player_texture_path;
		sf::Texture player_texture;
		sf::Sprite player_sprite;
		int sprite_height = 60;
		int sprite_width = 60;

		sf::RenderWindow* game_window;
		PlayerController* player_controller;
		UI::UIElement::ImageView* player_image;

		void createUIElement();
		void initilizeImage();
		sf::String getPlayerTexturePath();
		void destroy();
		const sf::Sprite& getPlayerSprite();
		/*void initializePlayerSprite();
		void scaleSprite();*/
	};

}

