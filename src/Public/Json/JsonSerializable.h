#pragma once
#include <nlohmann/json_fwd.hpp>

// Interface for classes that read json.
class JsonSerializable
{
public:
	virtual ~JsonSerializable() = default;

	// Implement to assign values in your class. Call preferably only on constructors.
	virtual void fromJson(const nlohmann::json& j) = 0;
};

