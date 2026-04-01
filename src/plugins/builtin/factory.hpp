#ifndef _TORUSTIQ_CLI_PLUGINS_BUILTIN_FACTORY_H_
#define _TORUSTIQ_CLI_PLUGINS_BUILTIN_FACTORY_H_

#include <vector>

#include "../stage_plugin.hpp"

using namespace std;

using TorustiqCli::Plugins::StagePlugin;

namespace TorustiqCli {
namespace Plugins {
namespace Builtin {

vector<StagePlugin> GetBuiltinPlugins();

}  // namespace Builtin
}  // namespace Plugins
}  // namespace TorustiqCli

#endif