#pragma once
#include <vector>
#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Element/Bunker/BunkerModel.h"
namespace Element
{
	class BunkerController;
	class ElementService
	{
	public:
		ElementService();
		~ElementService();

		void initialize();
		void update();
		void render();
		void reset();
	private:
		const std::vector<Bunker::BunkerData>bunker_data_list = {
			Bunker::BunkerData(sf::Vector2f(130.f, 800.f)),
			Bunker::BunkerData(sf::Vector2f(430.0f, 800.f)),
			Bunker::BunkerData(sf::Vector2f(730.0f, 800.f)),
			Bunker::BunkerData(sf::Vector2f(1130.0f, 800.f)),
			Bunker::BunkerData(sf::Vector2f(1430.0f, 800.f)),
			Bunker::BunkerData(sf::Vector2f(1730.0f, 800.f))
		};

		std::vector<Bunker::BunkerController*> bunker_list;

		void destroy();
	};

}
