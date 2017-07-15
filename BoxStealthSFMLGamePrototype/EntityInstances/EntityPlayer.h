// EntityPlayer.h
#include "../Entity/Entity.h"

class EntityPlayer : public Entity
{
public:

	EntityPlayer() {}
	~EntityPlayer() {}

	virtual void EntityInit() override;
	virtual void EntityUpdate(float deltaTInSeconds) override;
	virtual void EntityDestroy() override;
	
};