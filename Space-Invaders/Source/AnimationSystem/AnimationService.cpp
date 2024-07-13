#include "../../Header/AnimationSystem/AnimationService.h"
#include "../../Header/Global/Config.h"
#include "../../Header/AnimationSystem/AnimationSystemConfigData.h"

namespace Animation
{
	AnimationService::AnimationService()
	{
	}
	AnimationService::~AnimationService()
	{
		destroy();
	}
	void AnimationService::initialize()
	{

	}
	void AnimationService::update()
	{
		for (AnimationSystem* animation_system : animation_list)
			animation_system->update();
		destroyFlaggedAnimation();
	}
	void AnimationService::render()
	{
		for (AnimationSystem* animation_system : animation_list)
			animation_system->render();
	}
	void AnimationService::reset()
	{
		destroy();
	}
	void AnimationService::spwanAnimation(sf::Vector2f position, AnimationType type)
	{
		AnimationSystem* animation_system = new AnimationSystem(getAnimationSystemConfig(type));
		animation_system->initialize(position);
		animation_list.push_back(animation_system);
	}
	void AnimationService::destroyAnimation(AnimationSystem* animation_system)
	{
		flagged_list.push_back(animation_system);
		animation_list.erase(std::remove(animation_list.begin(), animation_list.end(), animation_system), animation_list.end());
	}
	AnimationSystemConfig AnimationService::getAnimationSystemConfig(AnimationType type)
	{
		switch (type)
		{
		case Animation::AnimationType::EXPLOSION:
			return explosion_animation_config;
			break;
		default:
			break;
		}
	}
	void AnimationService::destroyFlaggedAnimation()
	{
		for (AnimationSystem* particle_system : flagged_list)
			delete (particle_system);

		flagged_list.clear();
	}
	void AnimationService::destroy()
	{
		for (AnimationSystem* animation_system : animation_list)
			delete(animation_system);

		
	}
}