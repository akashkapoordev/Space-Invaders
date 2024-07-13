#pragma once
#include "../../Header/UIService/UIElement/ImageView.h"
#include "../../Header/AnimationSystem/AnimationSystemConfig.h"

namespace Animation
{
	class AnimationSystem:public UI::UIElement::ImageView
	{
	public:
		AnimationSystem(AnimationSystemConfig config);
		~AnimationSystem();

		void initialize(sf::Vector2f position);
		void update();
		void render();

		void destroy();

	private:
		AnimationSystemConfig animation_system_config;
		UI::UIElement::ImageView* animation_view;
		sf::Vector2f animation_position;
		int current_frame;
		void createUIElements();
		void initializeImage();
		sf::Clock clock;
		sf::Time frame_time;
	};

}