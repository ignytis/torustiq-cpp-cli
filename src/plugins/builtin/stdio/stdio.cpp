#include "stdio.hpp"

const TorustiqPluginInfo TorustiqCli::Plugins::Builtin::Stdio::GetPluginInfo() {
    return TorustiqPluginInfo{
        .id = "stdio",
        .name = "Standard IO Plugin",
    };
}

void TorustiqCli::Plugins::Builtin::Stdio::Init() {}