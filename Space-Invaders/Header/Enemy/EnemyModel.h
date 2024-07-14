#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
	enum class EnemyType;
	enum class MovementDirection;
	enum class EnemyState;
	class EnemyModel
	{
	public:
		EnemyModel(EnemyType enemy_type);
		~EnemyModel();

		float move_speed = 250.f;
		const sf::Vector2f left_window = sf::Vector2f(50.f, 950.f);
		const float Y_axis = 50.f;
		const sf::Vector2f right_window = sf::Vector2f(1800.f, 950.f);
		const float down_distance = 100.f;

		void initialize();

		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f set_position);

		sf::Vector2f getRefPosition();
		void setRefPosition(sf::Vector2f set_position);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		EnemyType getEnemyType();
		void setEnemyType(EnemyType type);

		EnemyState getEnemyState();
		void setEnemyState(EnemyState state);

		const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 50.f); 
		MovementDirection getRandomEnemyType();


	private:
		sf::Vector2f initial_position = sf::Vector2f(50.f, 50.f);
		sf::Vector2f current_position;
		EnemyType enemy_type;
		EnemyState enemy_state;
		MovementDirection movement_direction;

	

		
	};
}