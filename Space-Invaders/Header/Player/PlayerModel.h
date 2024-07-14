#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/UIService/Controller/GameplayUIController.h"

namespace Player
{
	enum class PlayerState {
		ALIVE,
		DEAD,
		FROZEN
	};
	class PlayerModel
	{
	public:
		PlayerModel();
		~PlayerModel();

		const float player_movement_speed = 350.0f;
		//int player_score = 0;
		const sf::Vector2f left_window = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f right_window = sf::Vector2f(1800.f, 950.f);

		PlayerState player_state;
		sf::Vector2f getPlayerPosition();
		void setPlayerPosition(sf::Vector2f position);

		void initialize();
		void reset();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);
		//const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 5.f);

		//position offset of weapon
		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);
		const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 5.f);
		const sf::Vector2f second_weapon_position_offset = sf::Vector2f(45.f, 0.f);
		const sf::Vector2f third_weapon_position_offset = sf::Vector2f(-45.f, 0.f);

		//powerup duration
		const float shiled_powerup_duration = 10.f;
		const float rapid_fire_powerup_duration = 10.f;
		const float tripple_laser_powerup_duration = 10.f;

		const float freeze_duration = 2.f;

		//cooldown DDuration
		const float fire_cooldown_duration = 0.2f;
		const float rapid_fire_cooldown_duration = 0.03f;
		const float tripple_laser_position_offset = 30.f;

		//elasped duration
		float elapsed_shield_duration;
		float elapsed_rapid_fire_duration;
		float elapsed_tripple_laser_duration;

		float elapsed_fire_duration;
		float elapsed_freeze_duration;

		Entity::EntityType getEntityType();
		int getScore();
		void setScore(int score);

		bool isShieldEnabled();
		bool isRapidFireEnabled();
		bool isTrippleLaserEnabled();

		void setShieldState(bool value);
		void setRapidFireState(bool value);
		void setTrippleFireState(bool value);



	private:
		friend class PlayerController;

		const sf::Vector2f initial_position = sf::Vector2f(950.f, 950.f);
		sf::Vector2f current_position;


		Entity::EntityType entity_type;
		static int playerScore;
		//PlayerState player_state;

		bool b_shield;
		bool b_rapidfire;
		bool b_triplelaser;

		friend void UI::GamePlay::GameplayUIController::updateEnemyKilledUI();
		friend void UI::GamePlay::GameplayUIController::drawPlayerLives();

		const int max_player_lives = 3;
		static int player_lives;
		static int enemies_killed;

	};

}
