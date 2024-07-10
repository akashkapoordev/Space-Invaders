#include "../../Header/UIService/Controller/SplashScreenUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Sound/SoundService.h"


namespace UI
{
	namespace SplashScreen
	{
		using namespace Global;
		using namespace Main;
		UI::SplashScreen::SplashScreenUIController::SplashScreenUIController()
		{
			createUIElements();
		}

		SplashScreenUIController::~SplashScreenUIController()
		{
		}

		void SplashScreenUIController::initialize()
		{
			initializeImage();
		}

		void SplashScreenUIController::update()
		{
			updateTimer();
			showMainMenu();
		}

		void SplashScreenUIController::render()
		{
			image_view->render();
		}

		void SplashScreenUIController::show()
		{
		}

		void SplashScreenUIController::createUIElements()
		{
			image_view = new UIElement::ImageView();
		}

		void SplashScreenUIController::initializeImage()
		{

			image_view->initialize(Config::outscal_logo_texture_path, logo_width, logo_height, getLogoPosition());
		}

		void SplashScreenUIController::updateTimer()
		{
			elsacped_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		}

		void SplashScreenUIController::showMainMenu()
		{
			if (elsacped_duration >= splash_screen_duration)
			{
				ServiceLocator::getInstance()->getSoundService()->backgroundSound();
				GameService::setGameState(GameState::MAIN_MENU);
			}
		}

		sf::Vector2f SplashScreenUIController::getLogoPosition()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			float x_position = (game_window->getSize().x - logo_width) / 2.0f;
			float y_position = (game_window->getSize().y - logo_height) / 2.0f;

			return sf::Vector2f(x_position, y_position);
		}

		void SplashScreenUIController::destroy()
		{
			delete(image_view);
		}

	}
}
