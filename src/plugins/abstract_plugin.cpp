#include "abstract_plugin.hpp"

using namespace TorustiqCli::Plugins;

AbstractPlugin::AbstractPlugin(AbstractPluginConstructorArgs args) {}


string AbstractPlugin::GetId() {
    return GetInfoPtr().id;
}