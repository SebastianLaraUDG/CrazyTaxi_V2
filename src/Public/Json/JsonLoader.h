#pragma once
#include <nlohmann/json.hpp>

class JsonLoader
{
public:
    static json LoadFile(const std::string& filePath);
};

