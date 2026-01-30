#pragma once
#include "Json/JsonSerializable.h"


class Car : public JsonSerializable
{
public:
	Car(const char* jsonFilePath);
	~Car();
private:
	void fromJson(const nlohmann::json& json);
};

