#pragma once
#include "../../Header/Collision/ICollider.h"
#include <vector>

namespace Collision
{
	class CollisionService
	{
	public:
		CollisionService();
		~CollisionService();

		void initilize();
		void update();

		void addCollider(ICollider* collider);
		void removeCollider(ICollider* collider);

	private:
		std::vector<ICollider*> collider_list;
		void processCollision();
		void doCollision(int index_i, int index_j);
		bool hasCollisionOccurred(int index_i, int index_j);
		bool areActiveCollision(int index_i, int index_j);
	};

}