#include "Car/Car.h"
#include "Json/JsonLoader.h"

Car::Car(const char* jsonFilePath)
{
	using json = nlohmann::json;
	json jsonFile = JsonLoader::LoadFile(jsonFilePath);
	fromJson(jsonFile);
}

void Car::fromJson(const nlohmann::json& json)
{
	// TODO: assign attributes.
}
