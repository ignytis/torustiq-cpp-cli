#include "stdio.hpp"

const TorustiqPluginInfo TorustiqCli::Plugins::Builtin::Stdio::GetPluginInfo() {
    return TorustiqPluginInfo{
        .id = "stdio",
        .name = "Standard IO Plugin",
    };
}

// no action needed on initialization
void TorustiqCli::Plugins::Builtin::Stdio::Init() {}