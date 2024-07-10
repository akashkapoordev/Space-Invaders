#include "../../Header/UIService/Controller/GameplayUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"

namespace UI
{
	namespace GamePlay
	{
		using namespace Global;
		using namespace UI::UIElement;
		UI::GamePlay::GameplayUIController::GameplayUIController()
		{
			createUI();
		}
		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}
		void GameplayUIController::initialize()
		{
			cout << "GameplayController Initilize" << "\n";
			initializeImage();
			initializeText();
		}
		void GameplayUIController::update()
		{
			updateEnemyKilledUI();
		}
		void GameplayUIController::render()
		{
			enemy_killed_text->render();
			drawPlayerLives();
		}
		void GameplayUIController::show()
		{
		}
		void GameplayUIController::destroy()
		{
			delete(player_image);
			delete(enemy_killed_text);
		}
		void GameplayUIController::updateEnemyKilledUI()
		{
			sf::String enemies_killed_string = "Enemy Killed : " + std::to_string(Player::PlayerModel::enemies_killed);
			enemy_killed_text->setText(enemies_killed_string);
		}
		void GameplayUIController::drawPlayerLives()
		{
			for (int i = 0;i < Player::PlayerModel::player_lives;i++)
			{
				player_image->setPosition(sf::Vector2f(player_lives_x_offset - (i * player_lives_spacing), player_lives_y_offset));
				player_image->render();
				//cout << "player_image render" << "\n";

			}
		}
		void GameplayUIController::createUI()
		{
			player_image = new ImageView();
			enemy_killed_text = new TextView();
		}
		void GameplayUIController::initializeImage()
		{
			player_image->initialize(Config::player_texture_path, player_width, player_height, sf::Vector2f(0, 0));
			cout << "player_image initilize" << "\n";
		}
		void GameplayUIController::initializeText()
		{
			enemy_killed_text->initializeTextView();
			sf::String enemies_killed_string = "Enemy Killed : 0";
			enemy_killed_text->initialize(enemies_killed_string, sf::Vector2f(enemies_killed_text_x_position, text_y_position), UI::UIElement::FontType::BUBBLE_BOBBLE, enemy_killed_font_size, text_color);
			cout << "Initialize Text" << "\n";
		}
	}
}


