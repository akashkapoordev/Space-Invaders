#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Element/Bunker/BunkerModel.h"
#include "../../Header/Collision/ICollider.h"


namespace Element
{
	namespace Bunker
	{
		class BunkerView;
		class BunkerController:public Collision::ICollider
		{
		public:
			BunkerController();
			~BunkerController();

			void initialize(Bunker::BunkerData data);
			void update();
			void render();

			sf::Vector2f getBunkerPosition();

		private:
			BunkerView* bunker_view;
			BunkerData bunker_data;
			const sf::Sprite& getCollisionSprite() override;
			void onCollision(ICollider* other_collider) override;
		};
	}
}


