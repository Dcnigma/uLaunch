
#pragma once
#include <q_Include.hpp>

namespace util
{
    ResultWith<JSON> LoadJSONFromFile(std::string path);
    std::string GetCurrentTime();
    u32 GetBatteryLevel();
    bool IsCharging();
}