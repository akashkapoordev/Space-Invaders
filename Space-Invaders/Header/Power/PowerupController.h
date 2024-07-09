#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../Header/Collectible/ICollectible.h"
#include "../../Header/Power/PowerConfig.h"
#include "../../Header/Collision/ICollider.h"
namespace PowerUp
{
	class PowerupModel;
	class PowerupView;
	enum class PowerType;

	class PowerupController:public ICollectible,public Collision::ICollider
	{
	public:
		PowerupController(PowerType type);
		virtual ~PowerupController();
		
		void initialCollectible(sf::Vector2f collectiblePosition)  override;
		void update() override;
		void render() override;

		void onCollected() override;
		sf::Vector2f getCollectiblePosition() override;

		PowerType getPowerType();
		//Entity::EntityType getEntityType();


	protected:
		PowerupModel* powerup_model;
		PowerupView* powerup_view;

		void UpdatePowerPosition();
		void handleOfBounds();

		const sf::Sprite& getCollisionSprite() override;
		void onCollision(ICollider* other_collider) override;
		virtual void applyPowerUp() = 0;
		//Entity::EntityType owner_type;
	};

}
