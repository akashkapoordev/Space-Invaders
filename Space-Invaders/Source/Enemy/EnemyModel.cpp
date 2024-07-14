#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"


namespace Enemy
{
	Enemy::EnemyModel::EnemyModel(EnemyType type)
	{
		enemy_type = type;
	}

	Enemy::EnemyModel::~EnemyModel()
	{
	}

	void EnemyModel::initialize()
	{
		enemy_state = EnemyState::PATROLLING;
		movement_direction = MovementDirection::RIGHT;
		current_position = initial_position;

	}

	sf::Vector2f EnemyModel::getRefPosition()
	{
		return initial_position;;
	}

	void EnemyModel::setRefPosition(sf::Vector2f set_position)
	{
		initial_position = set_position;
	}

	MovementDirection EnemyModel::getMovementDirection()
	{
		return movement_direction;
	}

	void EnemyModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}

	EnemyType EnemyModel::getEnemyType()
	{
		return enemy_type;
	}

	void EnemyModel::setEnemyType(EnemyType type)
	{
		enemy_type = type;
	}

	EnemyState EnemyModel::getEnemyState()
	{
		return enemy_state;
	}

	void EnemyModel::setEnemyState(EnemyState state)
	{
		enemy_state = state;
	}

	/*MovementDirection EnemyModel::getRandomEnemyType()
	{
		int random_direction = std::rand() % 3;
		return static_cast<MovementDirection>(random_direction);
	}*/

	//EnemyType EnemyService::getRandomEnemyType()
	//{
	//	int random_enemy = std::rand() % 4;
	//	return static_cast<Enemy::EnemyType>(random_enemy);
	//}



	sf::Vector2f Enemy::EnemyModel::getEnemyPosition()
	{
		return current_position;
	}

	void EnemyModel::setEnemyPosition(sf::Vector2f set_position)
	{
		current_position = set_position;
	}
}

