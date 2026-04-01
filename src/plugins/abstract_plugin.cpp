#include "abstract_plugin.hpp"

using namespace TorustiqCli::Plugins;

AbstractPlugin::AbstractPlugin(AbstractPluginConstructorArgs args) {
    InitPtr = args.init_fn_ptr;
    GetInfoPtr = args.get_info_fn_ptr;
}

string AbstractPlugin::GetId() {
    return GetInfoPtr().id;
}

string AbstractPlugin::GetName() {
    return GetInfoPtr().name;
}
