#include "../../Header/Player/PlayerModel.h"

namespace Player {
	PlayerModel::PlayerModel()
	{
		entity_type = Entity::EntityType::PLAYER;
	}

	PlayerModel::~PlayerModel()
	{
	}

	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return current_position;
	}

	void PlayerModel::setPlayerPosition(sf::Vector2f position)
	{
		current_position = position;
	}

	void PlayerModel::initialize()
	{
		reset();
	}

	void PlayerModel::reset()
	{
		player_state = PlayerState::ALIVE;
		current_position = initial_position;
		playerScore = 0;
		b_shield = false;
		b_rapidfire = false;
		b_shield = false;
	}

	PlayerState PlayerModel::getPlayerState()
	{
		return player_state;
	}

	void PlayerModel::setPlayerState(PlayerState state)
	{
		player_state = state;
	}
	Entity::EntityType PlayerModel::getEntityType()
	{
		return entity_type;
	}
	int PlayerModel::getScore()
	{
		return playerScore;
	}
	void PlayerModel::setScore(int score)
	{
		playerScore = score;
	}
	bool PlayerModel::isShieldEnabled()
	{
		return b_shield;
	}
	bool PlayerModel::isRapidFireEnabled()
	{
		return b_rapidfire;
	}
	bool PlayerModel::isTrippleLaserEnabled()
	{
		return b_triplelaser;
	}
	void PlayerModel::setShieldState(bool value)
	{
		b_shield = value;
	}
	void PlayerModel::setRapidFireState(bool value)
	{
		b_rapidfire = value;
	}
	void PlayerModel::setTrippleFireState(bool value)
	{
		b_triplelaser = value;
	}
}

