#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UIService/UIElement/ImageView.h"
#include <vector>
namespace Enemy
{
	class EnemyController;
	enum class EnemyType;
	class EnemyView
	{
	public:
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* enemy_controller);
		void update();
		void render();

		const sf::Sprite& getEnenmySprite();
	/*	void initializeSprite(EnemyType type);
		void scaleSprite();*/

	private:
		const sf::String subzero_texture_path;
		const sf::String zapper_texture_path;
		const float enemy_height = 60.f;
		const float enemy_width = 60.f;
		sf::Texture enemy_texture;
		sf::Sprite enemy_sprite;

		sf::RenderWindow* game_window;
		EnemyController* enemy_controller;

		UI::UIElement::ImageView* enemyimage_view;



		void createUIElement();
		void initilizeImage();
		sf::String getEnemyTexturePath();
		void destroy();



	};
}


