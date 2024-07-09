#pragma once
#include <SFML/Graphics.hpp>
namespace Bullet
{
	enum class MovementDirection {

		UP,
		DOWM
	};

	enum class BulletType {
		LASER,
		TORPEDO,
		FROST
	};

	class BulletConfig
	{
	public:
		static const sf::String laser_bullet_texture_path;
		static const sf::String torpedoe_texture_path;
		static const sf::String frost_beam_texture_path;

		static sf::String getBulletPath(BulletType bullet);
	};


}
