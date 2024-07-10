#pragma once
#include "../../Header/UIService/interface/IUIController.h"
#include "../../Header/UIService/UIElement/ImageView.h"
#include "../../Header/UIService/UIElement/TextView.h"

namespace UI
{
	namespace GamePlay
	{
		class GameplayUIController:public Interface::IUIController
		{
		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

			void updateEnemyKilledUI();

			void drawPlayerLives();


		private:

			const sf::Color text_color = sf::Color::White;
			const float enemy_killed_font_size =40.f;
			const float text_y_position = 15.f;
			const float enemies_killed_text_x_position = 60.f;

			const float player_lives_y_offset = 25.f;
			const float player_lives_x_offset = 1850.f;
			const float player_lives_spacing = 60.f;

			const float player_height = 30.f;
			const float player_width = 30.f;
			const sf::Vector2f player_health_position;

			UI::UIElement::ImageView* player_image;
			UI::UIElement::TextView* enemy_killed_text;
			void createUI();
			void initializeImage();
			void initializeText();
			void destroy();
		};

	}
}