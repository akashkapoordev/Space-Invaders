#pragma once
#include "../../Header/UIService/interface/IUIController.h"
#include "../../Header/UIService/UIElement/TextView.h"
#include "../../Header/UIService/UIElement/ImageView.h"
#include "../../Header/UIService/UIElement/ButtonView.h"

namespace UI
{
	namespace Instruction
	{
		class InstructionUIController:public Interface::IUIController
		{
		public:
			InstructionUIController();
			~InstructionUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		private:
			UI::UIElement::TextView* text_view;
			UI::UIElement::ImageView* image_view;
			UI::UIElement::ButtonView* button_view;
			sf::Font font;
			float font_size = 80.f;
			sf::Color font_color = sf::Color::White;

			void createUIElement();
			void initializeUI();
			void registerCallBack();
			void mainMenuCallBack();
			void destroy();
		};

	
	}
}