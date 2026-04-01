#include "stdio.hpp"

const TorustiqPluginInfo GetPluginInfo() {
    return TorustiqPluginInfo{
        .api_version = 1,
        .id = "stdio",
        .name = "Standard IO Plugin",
    };
}