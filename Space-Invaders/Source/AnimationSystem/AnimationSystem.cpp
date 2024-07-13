#include "../../Header/AnimationSystem/AnimationSystem.h"
#include "../../Header/Global/Config.h"

namespace Animation
{
	using namespace UI::UIElement;
	using namespace Global;
	AnimationSystem::AnimationSystem(AnimationSystemConfig config)
	{
		animation_system_config = config;
		createUIElements();
	}
	AnimationSystem::~AnimationSystem()
	{
		delete(animation_view);
	}
	void AnimationSystem::initialize(sf::Vector2f position)
	{
		animation_position = position;
		current_frame = 0;
		frame_time = sf::seconds(animation_system_config.frame_duration);
		initializeImage();

	}
	void AnimationSystem::update()
	{
		if (clock.getElapsedTime() >= frame_time)
		{
			if (current_frame + 1 >= animation_system_config.number_of_animation_frames)
			{
				destroy();
			}

			current_frame = (current_frame + 1) % animation_system_config.number_of_animation_frames;
			clock.restart();

			animation_view->setTextureRect(sf::IntRect(
				current_frame * animation_system_config.tile_width,
				0,
				animation_system_config.tile_width,
				animation_system_config.tile_height));
		}
		animation_view->update();

	}
	void AnimationSystem::render()
	{
		animation_view->render();
	}
	void AnimationSystem::destroy()
	{
	}
	void AnimationSystem::createUIElements()
	{
		animation_view = new ImageView();
	}
	void AnimationSystem::initializeImage()
	{
		animation_view->initialize(Config::explosion_texture_path, 0, 0, animation_position);
		animation_view->setTextureRect(sf::IntRect(0, 0, animation_system_config.tile_width, animation_system_config.tile_height));
		animation_view->setScale(animation_system_config.sprite_sheet_width, animation_system_config.sprite_sheet_height, animation_system_config.tile_width, animation_system_config.tile_height);
	}
}