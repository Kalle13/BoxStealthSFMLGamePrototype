// CollisionComponent.cpp
#include "CollisionComponent.h"

void CollisionComponent::Initialize()
{
	// Collision Bounds Vector Array Initialization
	numCollisionBoundsVertices_ = DEFAULT_NUM_COLLISION_VERTICES;
	collisionBoundsVectorArray_ = (sf::Vector2f*)malloc(numCollisionBoundsVertices_*sizeof(sf::Vector2f));

	if(collisionBoundsVectorArray_ == NULL){
		printf("(CollisionComponent::Initialize) Warning: Failed to allocate collision bounds vector array\n");
	}

	collisionBoundsVectorArray_[0] = DEFAULT_COLLISION_VECTOR_COORD_0;
	collisionBoundsVectorArray_[1] = DEFAULT_COLLISION_VECTOR_COORD_1;
	collisionBoundsVectorArray_[2] = DEFAULT_COLLISION_VECTOR_COORD_2;
	collisionBoundsVectorArray_[3] = DEFAULT_COLLISION_VECTOR_COORD_3;

	collisionBoundsCenterVector_ = Vector2ArrayAverage(&collisionBoundsVectorArray_[0], numCollisionBoundsVertices_);
	minDistanceForCollision_ = DistanceToFarthestVector2FromPoint(&collisionBoundsVectorArray_[0], numCollisionBoundsVertices_, collisionBoundsCenterVector_);

	// Collision Bounds Vertex Array Initialization
	collisionBoundsPrimitiveType_ = DEFAULT_COLLISION_PRIMITIVE_TYPE;
	collisionBoundsVertexArray_.resize(2 * numCollisionBoundsVertices_);
	collisionBoundsVertexArray_.setPrimitiveType(collisionBoundsPrimitiveType_);
	
	collisionBoundsVertexArray_[0].position = DEFAULT_COLLISION_VECTOR_COORD_0;
	collisionBoundsVertexArray_[1].position = DEFAULT_COLLISION_VECTOR_COORD_1;
	collisionBoundsVertexArray_[2].position = DEFAULT_COLLISION_VECTOR_COORD_1;
	collisionBoundsVertexArray_[3].position = DEFAULT_COLLISION_VECTOR_COORD_2;
	collisionBoundsVertexArray_[4].position = DEFAULT_COLLISION_VECTOR_COORD_2;
	collisionBoundsVertexArray_[5].position = DEFAULT_COLLISION_VECTOR_COORD_3;
	collisionBoundsVertexArray_[6].position = DEFAULT_COLLISION_VECTOR_COORD_3;
	collisionBoundsVertexArray_[7].position = DEFAULT_COLLISION_VECTOR_COORD_0;

	collisionBoundsVertexArray_[0].color = sf::Color(0x777777FF);
	collisionBoundsVertexArray_[1].color = sf::Color(0x777777FF);
	collisionBoundsVertexArray_[2].color = sf::Color(0x777777FF);
	collisionBoundsVertexArray_[3].color = sf::Color(0x777777FF);
	collisionBoundsVertexArray_[4].color = sf::Color(0x777777FF);
	collisionBoundsVertexArray_[5].color = sf::Color(0x777777FF);
	collisionBoundsVertexArray_[6].color = sf::Color(0x777777FF);
	collisionBoundsVertexArray_[7].color = sf::Color(0x777777FF);
	
}

void CollisionComponent::Update(float deltaTInSeconds)
{
}

void CollisionComponent::Destroy()
{
	if (collisionBoundsVectorArray_ != NULL) {
		free(collisionBoundsVectorArray_);
		if (collisionBoundsVectorArray_ == NULL) {
			printf("(CollisionComponent::Destroy) Message: collision component memory freed successfully\n");
		}
	}

	printf("(CollisionComponent::Destroy) Message: collision component destroyed\n");
}

void CollisionComponent::Draw(sf::RenderWindow & window)
{
	window.draw(collisionBoundsVertexArray_);
}

void CollisionComponent::UpdateCollisionBoundsPositionAndOrientation(sf::Vector2f displacementVector, float displacementAngle)
{
	sf::Transform transform = sf::Transform::Identity;

	transform.translate(displacementVector);
	collisionBoundsCenterVector_ = transform.transformPoint(collisionBoundsCenterVector_);
	transform.rotate(displacementAngle, collisionBoundsCenterVector_);

	for (unsigned i = 0; i < numCollisionBoundsVertices_; ++i)
	{
		collisionBoundsVectorArray_[i] = transform.transformPoint(collisionBoundsVectorArray_[i]);
	}

	for (unsigned i = 0; i < 2*numCollisionBoundsVertices_; ++i)
	{
		collisionBoundsVertexArray_[i].position = transform.transformPoint(collisionBoundsVertexArray_[i].position);
	}

}