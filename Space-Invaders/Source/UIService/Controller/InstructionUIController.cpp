#include "../../Header/UIService/Controller/InstructionUIController.h"
#include "../../Header/UIService/UIElement/TextView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Main/GameService.h";
namespace UI
{
	namespace Instruction
	{
		using namespace Global;
		using namespace Sound;
		using namespace Main;
		UI::Instruction::InstructionUIController::InstructionUIController()
		{
			createUIElement();
		}

		UI::Instruction::InstructionUIController::~InstructionUIController()
		{
			destroy();
		}

		void UI::Instruction::InstructionUIController::initialize()
		{
			initializeUI();
			registerCallBack();
		}

		void UI::Instruction::InstructionUIController::update()
		{
			//text_view->update();
			button_view->update();
		}

		void UI::Instruction::InstructionUIController::render()
		{
			image_view->render();
			text_view->render();
			button_view->render();
		}

		void UI::Instruction::InstructionUIController::show()
		{
			button_view->show();
		}

		void UI::Instruction::InstructionUIController::createUIElement()
		{
			image_view = new UIElement::ImageView();
			button_view = new UI::UIElement::ButtonView();
			text_view = new UI::UIElement::TextView();
		}

		void UI::Instruction::InstructionUIController::initializeUI()
		{
			sf::String instruction_string =
				sf::String("USE THE ARROW KEY TO MOVE YOUR SPACE SHIP\n") +
				"DESTROY THE SPACE SHIP USING THE BULLET BY\nPRESSING LEFT MOUSE BUTTON\n" +
				"     \n    COLLECT POWER UPS AND ENJOY THE GAME";
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			image_view->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			text_view->initialize(instruction_string, sf::Vector2f(300.f,250.f), UI::UIElement::FontType::BUBBLE_BOBBLE, font_size, font_color);
			button_view->initialize("Main Menu", Config::menu_button_texture_path, 400.f, 140.f, sf::Vector2f(800, 800));
		}

		void InstructionUIController::registerCallBack()
		{
			button_view->registerCallbackFuntion(std::bind(&InstructionUIController::mainMenuCallBack, this));
		}

		void InstructionUIController::mainMenuCallBack()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::MAIN_MENU);

		}

		

		void UI::Instruction::InstructionUIController::destroy()
		{
			delete(image_view);
			delete(text_view);
		}

	}
}

