#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
	class EventService;

	class PlayerController;
	class PlayerService
	{
	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void enableShield();
		void enableRapidFire();
		void enableTrippleLaser();

		void reset();

		void increaseEnemiesKilled(int val);
		void increasePlayerScore(int score);

		//void moveLeft();
		//void moveRight();
		//int getMoveSpeed();
		//sf::Vector2f getposition();


	private:

		PlayerController* player_controller;
		// int player_score = 3;
		// int health = 10;
		// float movespeed = 350.f;
		// sf::Vector2f player_position =  sf::Vector2f(200,100);

		//const sf::String player_texture_path = "assets/textures/player_ship.png";

		// sf::Texture player_texure;
		// sf::Sprite player_sprite;

		// void initializePlayerSprite();
		// void processPlayerInput();

		// sf::RenderWindow* game_window;
		// EventService* game_event;
	};
}

