// main.cpp

#include "Game/GameLoop.h"

LevelManager *gLevelManagerPtr;
EntityManager *gEntityManagerPtr;
GameInput *gGameInputPtr;
GameConsole *gGameConsolePtr;

class RenderComponentExample : public RenderComponent
{
public:
	RenderComponentExample() {}
	~RenderComponentExample() {}

	void Initialize()
	{
		numVertices = 5;
		primitiveType = sf::Quads;
		mesh.resize(numVertices);
		mesh.setPrimitiveType(primitiveType);
	}
	void Update(float deltaTInSeconds) {}
	void Destroy() {}
};

int main()
{
	PhysicsComponent *physCompPtr;
	RenderComponentExample initializedRenderComponent;

	printf("Sizeof PhysicsComponent: %d\nSizeof dereferences PhysicsComponent pointer: %d\n", sizeof(PhysicsComponent), sizeof(*physCompPtr));
	printf("Sizeof(sf::Vector2f): %d\n", sizeof(sf::Vector2f));
	printf("Sizeof(LinearPhysics): %d\n,Sizeof(RotationPhysics): %d\n", sizeof(LinearPhysics), sizeof(RotationPhysics));
	
	
	
	printf("Sizeof uninitialized render component: %d\nSizeof initialized render component: %d\n", sizeof(RenderComponent), sizeof(initializedRenderComponent));

	unsigned meshOffset = offsetof(RenderComponent, mesh);
	unsigned initMeshOffset = offsetof(RenderComponentExample, mesh);

	printf("RenderComponent.mesh offset: %d\ninitialized RenderComponent.mesh offset: %d\n", meshOffset, initMeshOffset);

	printf("Initialized Render Component Ptr: 0x%x\n", &initializedRenderComponent);
	printf("Initialized Render Component mesh Ptr: 0x%x\n", &(initializedRenderComponent.mesh));
	unsigned memDiff = (unsigned)(&(initializedRenderComponent.mesh)) - (unsigned)(&initializedRenderComponent);
	printf("Mesh ptr - RenderComponent ptr = %d\n", memDiff);

	/*
	GameLoop game;
	game.GameLoopInit();
	*/
	return 0;
}
