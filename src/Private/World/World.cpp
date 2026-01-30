#include "World/World.h"

dWorldID World::world_ = nullptr;
dSpaceID World::space_ = nullptr;

World::World(const dReal& gravity)
{
	if (world_ == nullptr)
	{
		world_ = dWorldCreate();
		dWorldSetGravity(world_, 0.0, 0.0, gravity);

		// For now we will have a simple space.
		space_ = dSimpleSpaceCreate(0);
	}
}

World::~World()
{
	dWorldDestroy(world_);

}


void World::AddBodies(const dGeomID* geoms, const std::string* names, int numElements)
{
	for (int i = 0; i < numElements; ++i)
	{
		auto [it, inserted] = geoms_.emplace(names[i], geoms[i]);

		if (!inserted)
		{
			// TODO: Mensaje de error.
		}
	}
}