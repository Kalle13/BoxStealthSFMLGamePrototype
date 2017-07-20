#include "CollisionSystem.h"

void CollisionSystem::Initialize()
{
	collisionComponentIndex = 0;

	collisionComponentPtrArray = (CollisionComponent**)malloc(MAX_NUM_COLLISION_COMPONENTS * sizeof(CollisionComponent*));
}

void CollisionSystem::Destroy()
{
	if (collisionComponentPtrArray != NULL) {
		free(collisionComponentPtrArray);
	}
}

void CollisionSystem::RunCollisionDetection()
{
	for (unsigned i = 0; i < collisionComponentIndex; ++i) {

	}
}

void CollisionSystem::RegisterCollisionComponent(CollisionComponent *collisionComponentPtr)
{
	bool emptyCollisionComponentPtrArraySlot = false;

	for (unsigned i = 0; i < collisionComponentIndex; ++i) {
		if (collisionComponentPtrArray[i] == NULL) {
			collisionComponentPtrArray[i] = collisionComponentPtr;
			emptyCollisionComponentPtrArraySlot = true;
		}
	}
	if (collisionComponentIndex < MAX_NUM_COLLISION_COMPONENTS && !emptyCollisionComponentPtrArraySlot) {
		collisionComponentPtrArray[collisionComponentIndex] = collisionComponentPtr;
		collisionComponentIndex++;
	}
	else if((collisionComponentIndex == MAX_NUM_COLLISION_COMPONENTS) && !emptyCollisionComponentPtrArraySlot) {
		printf("(CollisionSystem::RegisterCollisionComponent) Error: Failed to register collision component; no more memory for storing collision components\n");
	}
}

void CollisionSystem::UnregisterCollisionComponent(CollisionComponent *collisionComponentPtr)
{
	bool collisionComponentPtrInArray = false;

	for (unsigned i = 0; i < collisionComponentIndex; ++i) {
		if (collisionComponentPtrArray[i] == collisionComponentPtr) {
			collisionComponentPtrArray[i] == NULL;
			collisionComponentPtrInArray = true;
		}
	}

	if (!collisionComponentPtrInArray) {
		printf("(CollisionSystem::UnregisterCollisionComponent) Error: Collision pointer not registered\n");
	}
}
