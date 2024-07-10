#include "../../Header/Element/ElementService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Element
{
	using namespace Global;
	ElementService::ElementService()
	{
	}
	ElementService::~ElementService()
	{
		destroy();
	}
	void ElementService::initialize()
	{
		spwanBunker();
	}
	void ElementService::update()
	{
		for (int i = 0;i < bunker_list.size();i++)
		{
			bunker_list[i]->update();
			destroyFlaggedBunker();
		}
	}
	void ElementService::render()
	{
		for (int i = 0;i < bunker_list.size();i++)
		{
			bunker_list[i]->render();
		}
	}
	void ElementService::reset()
	{
		destroy();
		spwanBunker();
		
	}
	void ElementService::spwanBunker()
	{
		for (int i = 0;i < bunker_data_list.size();i++)
		{
			Bunker::BunkerController* bunker_controller = new Bunker::BunkerController();
			bunker_controller->initialize(bunker_data_list[i]);
			bunker_list.push_back(bunker_controller);
			ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<Collision::ICollider*>(bunker_controller));
		}
	}
	void ElementService::destroyFlaggedBunker()
	{
		for (int i = 0;i < flagged_list.size();i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(flagged_list[i]));
			delete(flagged_list[i]);

		}
		flagged_list.clear();
	}
	void ElementService::destroyBunker(Bunker::BunkerController* bunker_controller)
	{
		flagged_list.push_back(bunker_controller);
		bunker_list.erase(std::remove(bunker_list.begin(), bunker_list.end(), bunker_controller), bunker_list.end());
	}
	void ElementService::destroy()
	{
		for (int i = 0;i < bunker_list.size();i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(bunker_list[i]));
			delete(bunker_list[i]);
		}
		bunker_list.clear();
	}
}