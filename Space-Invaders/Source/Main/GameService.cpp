#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace Main
{
	using namespace Global;

	GameState GameService::currentState = GameState::BOOT;
	GameService::GameService()
	{
		service_locator = nullptr;
		game_window = nullptr;
	}
	GameService::~GameService()
	{
		destroyGameService();
	}

	void GameService::createGameService()
	{
		service_locator->initialize();
		initializeVariables();
		showSplashScreen();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
	}


	void GameService::ignite()
	{
		service_locator = Global::ServiceLocator::getInstance();
		createGameService();
	}

	void GameService::update()
	{
		service_locator->update();
		service_locator->getEventService()->processEvent();
	}

	void GameService::render()
	{
		game_window->clear(service_locator->getGraphicService()->gameWindowColor());
		service_locator->render();
		game_window->display();
	}

	bool GameService::isRunning()
	{
		return service_locator->getGraphicService()->isGameWindowOpen();
	}

	GameState GameService::getGameState()
	{
		return currentState;
	}

	void GameService::setGameState(GameState state)
	{
		currentState = state;
	}

	void GameService::showSplashScreen()
	{
		setGameState(GameState::SPLASH_SCREEN);
		ServiceLocator::getInstance()->uiService()->showScreen();
	}

	//void GameService::showMainMenu()
	//{
	//	setGameState(GameState::MAIN_MENU);
	//}




	void GameService::destroyGameService()
	{
		delete(service_locator);
		delete(game_window);
		service_locator = nullptr;
		game_window = nullptr;
	}
}

