#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"

#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/Config.h"


namespace Enemy
{
	using namespace Global;
	Enemy::EnemyView::EnemyView()
	{
		//game_window = nullptr;
		createUIElement();
	}

	Enemy::EnemyView::~EnemyView()
	{
		destroy();
	}

	void Enemy::EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		//game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		//initializeSprite(enemy_controller->getEnemyType());
		initilizeImage();
	}

	void Enemy::EnemyView::update()
	{
		enemyimage_view->setPosition(enemy_controller->getEnemyPosition());
		enemyimage_view->update();
		//enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
	}

	void Enemy::EnemyView::render()
	{
		enemyimage_view->render();
		// game_window->draw(enemy_sprite);
	}
	const sf::Sprite& EnemyView::getEnenmySprite()
	{
		// TODO: insert return statement here
		return enemyimage_view->getSprite();
	}
	/*void EnemyView::initializeSprite(EnemyType type)
	{
		switch (type)
		{
		case Enemy::EnemyType::ZAPPER:
			if (enemy_texture.loadFromFile(Config::zapper_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);
				scaleSprite();
			}
			break;
		case Enemy::EnemyType::SUBZERO:
			if (enemy_texture.loadFromFile(Config::subzero_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);
				scaleSprite();
			}
			break;
		case Enemy::EnemyType::UFO:
			if (enemy_texture.loadFromFile(Config::ufo_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);
				scaleSprite();
			}
			break;
		case Enemy::EnemyType::THUNDER_SNAKE:
			break;
		default:
			break;
		}
	}*/
	//void EnemyView::scaleSprite()
	//{
	//	enemy_sprite.setScale(
	//		static_cast<float>(enemy_width) / enemy_sprite.getTexture()->getSize().x,
	//		static_cast<float>(enemy_height) / enemy_sprite.getTexture()->getSize().y
	//	);
	//}
	void EnemyView::createUIElement()
	{
		enemyimage_view = new UI::UIElement::ImageView();
	}
	void EnemyView::initilizeImage()
	{
		enemyimage_view->initialize(getEnemyTexturePath(), enemy_height, enemy_width, enemy_controller->getEnemyPosition());
	}


	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemy_controller->getEnemyType())
		{
		case Enemy::EnemyType::ZAPPER:
			return Config::zapper_texture_path;
			break;
		case Enemy::EnemyType::SUBZERO:
			return Config::subzero_texture_path;
			break;
		case Enemy::EnemyType::UFO:
			return Config::ufo_texture_path;
			break;
		}
	}
	void EnemyView::destroy()
	{
		delete(enemyimage_view);
	}
}

