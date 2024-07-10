#include "../../Header/UIService/UIService.h"
#include "../../Header//Main/GameService.h"

#include <iostream>
using namespace std;

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace Interface;
	using namespace GamePlay;
	using namespace SplashScreen;

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		gameplay_controller = nullptr;
		splash_screen_controller = nullptr;

		createControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
		gameplay_controller = new GameplayUIController();
		splash_screen_controller = new SplashScreenUIController();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::initialize()
	{
		initializeControllers();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->update();
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->render();
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->show();
	}

	void UIService::initializeControllers()
	{
		splash_screen_controller->initialize();
		main_menu_controller->initialize();
		gameplay_controller->initialize();
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splash_screen_controller;
		case GameState::MAIN_MENU:
			return main_menu_controller;
		case GameState::GAMEPLAY:
			return gameplay_controller;

		default:
			return nullptr;
		}
	}

	void UIService::destroy()
	{
		delete(main_menu_controller);
		delete(gameplay_controller);
		delete(splash_screen_controller);
	}
}






