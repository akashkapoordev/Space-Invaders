#pragma once

//#include "../../Header/Graphic/GraphicService.h"
//#include "../Player/PlayerView.h"
//#include "../Player/PlayerModel.h"
#include "../../Header/Collision/ICollider.h"

namespace Player
{
	class GraphicService;
	enum class PlayerState;
	class PlayerModel;
	class PlayerView;

	class PlayerController:public Collision::ICollider
	{
	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		sf::Vector2f getPosition();

		const sf::Sprite& getCollisionSprite() override;
		void onCollision(ICollider* other_collider) override;

		void reset();

		void enableShield();
		void enableRapidFire();
		void enableTrippleLaser();

	

	private:

		PlayerModel* player_model;
		PlayerView* player_view;

		void processInput();
		void moveLeft();
		void moveRight();
		//void fireBullet();


		bool bulletCollision(ICollider* other_collider);
		bool enmeyCollision(ICollider* other_collider);
		bool powerupCollision(ICollider* other_collider);

		void updateFreezeDuration();
		void freezPlayer();

		void updateFireDuration();
		void processBulletFire();
		void fireBullet(bool b_tripple_laser = false);
		void fireBullet(sf::Vector2f position);

		void updatePowerDuration();

		void disableShield();
		void disableRapidFire();
		void disableTrippleLaser();
	};

}

