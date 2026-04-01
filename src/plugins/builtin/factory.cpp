#include "factory.hpp"

#include <vector>

#include "../stage_plugin.hpp"
#include "stdio/stdio.hpp"

using namespace std;

using TorustiqCli::Plugins::StagePlugin;

vector<StagePlugin> TorustiqCli::Plugins::Builtin::GetBuiltinPlugins() {
    vector<StagePlugin> plugins;

    plugins.push_back(StagePlugin(StagePluginConstructorArgs{.super_args{
        .init_fn_ptr = TorustiqCli::Plugins::Builtin::Stdio::Init,
    }}));

    return plugins;
}