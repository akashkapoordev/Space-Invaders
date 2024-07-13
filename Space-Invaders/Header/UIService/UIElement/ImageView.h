#pragma once
#include "../../Header/UIService/UIElement/UIView.h"
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace UIElement
	{
		class ImageView : public UIView
		{
		protected:
			sf::Texture image_texture;
			sf::Sprite image_sprite;

		public:
			ImageView();
			virtual ~ImageView();

			virtual void initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position);
			virtual void update() override;
			virtual void render() override;

			virtual void setTextureRect(sf::IntRect texture_rect);
			virtual void setTexture(sf::String texture_path);
			virtual void setScale(float width, float height);
			virtual void setScale(float width, float height, float tile_width, float tile_height);
			virtual void setPosition(sf::Vector2f position);
			virtual void setRotation(float rotation_angle);
			virtual void setOriginAtCentre();
			virtual void setImageAlpha(float alpha);
			virtual void setCentreAlinged();
			virtual const sf::Sprite& getSprite();
		};
	}
}
