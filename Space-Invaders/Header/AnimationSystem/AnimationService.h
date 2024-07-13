#pragma once
#include <vector>
#include "../../Header/AnimationSystem/AnimationSystem.h"

namespace Animation
{
	enum class AnimationType
	{
		EXPLOSION
	};
	class AnimationService
	{
	public:
		AnimationService();
		virtual ~AnimationService();

		void initialize();
		void update();
		void render();

		void reset();
		void spwanAnimation(sf::Vector2f position,AnimationType type);
		void destroyAnimation(AnimationSystem* animation_system);

	private:
		std::vector<AnimationSystem*> animation_list;
		std::vector<AnimationSystem*> flagged_list;
		AnimationSystemConfig getAnimationSystemConfig(AnimationType type);
		void destroyFlaggedAnimation();
		void destroy();
	};
}