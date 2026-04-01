#ifndef _TORUSTIQ_CLI_PLUGINS_ABSTRACT_PLUGIN_H_
#define _TORUSTIQ_CLI_PLUGINS_ABSTRACT_PLUGIN_H_

#include <string>

#include <torustiq_sdk/typedefs.h>

using namespace std;

namespace TorustiqCli {
namespace Plugins {

struct AbstractPluginConstructorArgs {
    TorustiqPluginInitFnPtr init_fn_ptr;
    TorustiqPluginGetInfoFnPtr get_info_fn_ptr;
};

/** Abstract base class for plugins */
class AbstractPlugin {
   public:
    AbstractPlugin(AbstractPluginConstructorArgs args);

    string GetId();
    string GetName();

   private:
    TorustiqPluginInitFnPtr InitPtr;
    TorustiqPluginGetInfoFnPtr GetInfoPtr;
};

}  // namespace Plugins
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_PLUGINS_ABSTRACT_PLUGIN_H_
