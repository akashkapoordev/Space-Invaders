#pragma once
#include "../../Header/UIService/UIElement/UIView.h"

namespace UI
{
	namespace UIElement
	{
		enum class FontType
		{
			BUBBLE_BOBBLE,
			DS_DIGIB,
		};
		class TextView:public UIView
		{
		public:
			TextView();
			virtual ~TextView();

			static void initializeTextView();
			virtual void initialize(sf::String text_value, sf::Vector2f position, FontType font_type = FontType::BUBBLE_BOBBLE, int font_size = font_size, sf::Color color = sf::Color::White);
			virtual void update() override;
			virtual void render() override;

			void setText(sf::String text);
			void alignCenter();

		private:
			static const int font_size = 55;
			static sf::Font font_bubble_bobble;
			static sf::Font font_ds_digib;

			static void loadFont();
			void setFont(FontType type);
			void setFontSize(int size);
			void setFontPosition(sf::Vector2f position);
			void setFontColor(sf::Color color);

			sf::Text font_text;

			
		};

	}
}

