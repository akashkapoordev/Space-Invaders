#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UIService/UIElement/ImageView.h"

namespace PowerUp
{
	class PowerupController;
	enum class PowerType;
	class ImageView;
	class PowerupView
	{
	public:
		PowerupView();
		~PowerupView();

		void initialize(PowerupController* controller);
		void update();
		void render();

		//void initialSprite(PowerType type);
		//void scaleSprite();

		const sf::Sprite& getPowerUpSprite();

	private:
		PowerupController* power_controller;
		const float powerup_height = 30.f;
		const float powerup_width = 30.f;

		sf::Texture powerup_texture;
		sf::Sprite powerup_sprite;

		sf::RenderWindow* game_window;

		UI::UIElement::ImageView* powerup_image;

		void createUIElements();
		void initializeImage();
		sf::String powerup_texture_path();
		void destroy();
		
	};

}

