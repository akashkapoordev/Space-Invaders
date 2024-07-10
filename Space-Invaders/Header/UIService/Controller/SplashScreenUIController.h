#pragma once
#include "../../Header/UIService/interface/IUIController.h"
#include "../../Header/UIService/UIElement/ImageView.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController:public Interface::IUIController
		{
		public:
			SplashScreenUIController();
			~SplashScreenUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		private:
			const float splash_screen_duration = 2.0f;
			float elsacped_duration = 0.0f;
			const float logo_width = 600.f;
			const float logo_height = 130.f;;
			UIElement::ImageView* image_view;
			void createUIElements();
			void initializeImage();
			void updateTimer();
			void showMainMenu();
			sf::Vector2f getLogoPosition();
			void destroy();
		};


	}
}