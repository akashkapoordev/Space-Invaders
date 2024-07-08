#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UIService/UIElement/ImageView.h"

namespace Bullet 
{
	enum class BulletType;
	class BulletController;

	class  BulletView
	{
	public:
		BulletView();
		~BulletView();

		void initialize(BulletController* controller);
		void update();
		void render();
		sf::Sprite& getSprite();


	private:
		const float bullet_height = 18.f;
		const float bullet_width = 18.f;

		sf::Texture bullet_texture;
		sf::Sprite bullet_sprite;

		sf::RenderWindow* game_window;

		BulletController* bullet_controller;

		UI::UIElement::ImageView* bulletimage_view;

		void createUIElement();
		void initilizeImage();
		sf::String getBulletTexturePath();

		void destroy();
	};

}

