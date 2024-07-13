#include "../../Header/UIService/Controller/SplashScreenUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/ServiceLocator.h"


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
		/*	updateTimer();
			showMainMenu();*/
			image_view->update();
			animation_view->update();
		}

		void SplashScreenUIController::render()
		{
			image_view->render();
			animation_view->render();
		}

		void SplashScreenUIController::show()
		{
			animation_view->playAnimation(UI::UIElement::AnimationType::FADE_IN, splash_screen_duration, std::bind(&SplashScreenUIController::fadeInAnimationCallback, this));

		}

		void SplashScreenUIController::createUIElements()
		{
			animation_view = new UIElement::AnimatedImageView();
			image_view = new UIElement::ImageView();
		}

		void SplashScreenUIController::initializeImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			image_view->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			sf::Vector2f position = getLogoPosition();
			animation_view->initialize(Config::outscal_logo_texture_path, logo_width, logo_height, position);
		}

		void SplashScreenUIController::fadeInAnimationCallback()
		{
			animation_view->playAnimation(UI::UIElement::AnimationType::FADE_OUT, splash_screen_duration, std::bind(&SplashScreenUIController::fadeOutAnimationCallback, this));
		}

		void SplashScreenUIController::fadeOutAnimationCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->backgroundSound();
			GameService::setGameState(GameState::MAIN_MENU);

		}

		//void SplashScreenUIController::updateTimer()
		//{
		//	elsacped_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		//}

		//void SplashScreenUIController::showMainMenu()
		//{
		//	if (elsacped_duration >= splash_screen_duration)
		//	{
		//		ServiceLocator::getInstance()->getSoundService()->backgroundSound();
		//		GameService::setGameState(GameState::MAIN_MENU);
		//	}
		//}

		sf::Vector2f SplashScreenUIController::getLogoPosition()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			float x_position = (game_window->getSize().x - logo_width) / 2.0f;
			float y_position = (game_window->getSize().y - logo_height) / 2.0f;

			return sf::Vector2f(x_position, y_position);
		}

		void SplashScreenUIController::destroy()
		{
			delete(animation_view);
		}

	}
}
