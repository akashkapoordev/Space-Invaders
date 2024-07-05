#pragma once

#include "../../Header/UIService/MainMenuUIController/MainMenuUIController.h"
#include "../../Header/UIService/interface/IUIController.h"

	namespace UI
	{
		
			class UIService
			{
			public:
				UIService();
				~UIService();

				void initialize();
				void update();
				void render();


				void showScreen();
				UI::Interface::IUIController* getCurrentUIController();

			private:
				UI::MainMenu::MainMenuUIController* main_menu_controller;

				void createControllers();
				void initializeControllers();
				void destroy();




			};
		


	}



