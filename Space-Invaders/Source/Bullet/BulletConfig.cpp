#include "../../Header/Bullet/BulletConfig.h"

namespace Bullet
{
	const sf::String BulletConfig::laser_bullet_texture_path = "assets/textures/laser_bullet.png";

	const sf::String BulletConfig::torpedoe_texture_path = "assets/textures/torpedoe.png";

	const sf::String BulletConfig::frost_beam_texture_path = "assets/textures/frost_beam.png";

	sf::String BulletConfig::getBulletPath(BulletType bullet)
	{
		switch (bullet)
		{
		case Bullet::BulletType::LASER:
			return laser_bullet_texture_path;
		case Bullet::BulletType::TORPEDO:
			return torpedoe_texture_path;
		case Bullet::BulletType::FROST:
			return frost_beam_texture_path;
		}
	}
}