#include "Json/JsonLoader.h"
#include <fstream>

using json = nlohmann::json;

json JsonLoader::LoadFile(const std::string& filePath)
{
	std::ifstream input_file(filePath);
	
	if (!input_file.is_open())
	{
		throw std::runtime_error("Could not open json file");
	}
	
	json loaded_json;
	input_file >> loaded_json;

	
	return loaded_json;
}
