#include "EntityPlayer.h"

void EntityPlayer::EntityInit()
{
	unsigned physCompSize = sizeof(PhysicsComponent);
	unsigned renderCompSize = sizeof(RenderComponent);
	unsigned collisionCompSize = sizeof(CollisionComponent);
	unsigned inputCompSize = sizeof(InputComponent);

	unsigned dataMallocSize = physCompSize + renderCompSize + collisionCompSize + inputCompSize;
	physicsCompPtr = (PhysicsComponent*)malloc(dataMallocSize);
	collisionCompPtr = (CollisionComponent*)(physicsCompPtr + physCompSize);
	renderCompPtr = (RenderComponent*)(physicsCompPtr + physCompSize + collisionCompSize);
	inputCompPtr = (InputComponent*)(physicsCompPtr + physCompSize + collisionCompSize + renderCompSize);

}


void EntityPlayer::EntityUpdate(float deltaTInSeconds)
{


}


void EntityPlayer::EntityDestroy()
{
	free(physicsCompPtr);

	if (physicsCompPtr != NULL) {
		printf("(EntityPlayer::EntityDestroy()) Error: Failed to free memory\n");
	}
}