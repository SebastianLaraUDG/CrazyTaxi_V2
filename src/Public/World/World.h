#pragma once
#include <ode/ode.h>
#include <unordered_map>
#include <string>

/// @brief Please note that this is different from a Scene.
class World
{
public:
	// Gravity is only applied in Z axis.
	World(const dReal& gravity);
	~World();

private:

	// Create bodies in the dynamics world. Reads them from a JSON file.
	void AddBodies();

	// Add bodies to world.
	void AddBodies(const dGeomID* geoms, const std::string* names, int numElements);

	static dWorldID world_;
	static dSpaceID space_;

	// Collection of all geoms.<Name, geomID>
	static std::unordered_map<std::string, dGeomID> geoms_;
};

