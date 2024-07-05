#pragma once

#include "../../Header/UIService/MainMenuUIController/MainMenuUIController.h"
#include "../../Header/UIService/interface/IUIController.h"

#include <SFML/Graphics.hpp>

namespace UI
{
	namespace UIElement
	{
		enum class UIState
		{
			VISIBLE,
			HIDDEN,
		};

		class UIView
		{
		protected:
			sf::RenderWindow* game_window;
			UIState ui_state;

		public:
			UIView();
			virtual ~UIView();

			virtual void initialize();
			virtual void update();
			virtual void render();

			virtual void show();
			virtual void hide();
		};
	}


	//class UIController;
	using namespace Interface;
	using namespace UIElement;
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


