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

	// Initialize entity physics
	physicsCompPtr->scale = sf::Vector2f(1.0, 1.0);
	physicsCompPtr->linPhys.pos = sf::Vector2f(400, 600);
	physicsCompPtr->linPhys.vel = sf::Vector2f(0, 0);
	physicsCompPtr->linPhys.acc = sf::Vector2f(0, 0);
	physicsCompPtr->rotPhys.angle = 0;
	physicsCompPtr->rotPhys.angVel = 0;
	physicsCompPtr->rotPhys.angAcc = 0;

	// 


	
}


void EntityPlayer::EntityUpdate(float deltaTInSeconds)
{
	LinearPhysics entityLinPhys = physicsCompPtr->linPhys;
	RotationPhysics entityRotPhys = physicsCompPtr->rotPhys;

}


void EntityPlayer::EntityDestroy()
{
	free(physicsCompPtr);	// this will free all entity data

	if (physicsCompPtr != NULL) {
		printf("(EntityPlayer::EntityDestroy()) Error: Failed to free entity component memory\n");
	}

}