#pragma once

#include "../../Header/UIService/Controller/MainMenuUIController.h"
#include "../../Header/UIService/Controller/GameplayUIController.h"
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
				UI::GamePlay::GameplayUIController* gameplay_controller;

				void createControllers();
				void initializeControllers();
				void destroy();




			};
		


	}



