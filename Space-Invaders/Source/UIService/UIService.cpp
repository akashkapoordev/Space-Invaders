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

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		gameplay_controller = nullptr;

		createControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
		gameplay_controller = new GameplayUIController();
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
		main_menu_controller->initialize();
		gameplay_controller->initialize();
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
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
	}
}






