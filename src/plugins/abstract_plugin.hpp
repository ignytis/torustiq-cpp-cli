#ifndef _TORUSTIQ_CLI_PLUGINS_ABSTRACT_PLUGIN_H_
#define _TORUSTIQ_CLI_PLUGINS_ABSTRACT_PLUGIN_H_

#include <torustiq_sdk/typedefs.h>

namespace TorustiqCli {
namespace Plugins {

struct AbstractPluginConstructorArgs {
    TorustiqPluginInitFnPtr init_fn_ptr;
};

/** Abstract base class for plugins */
class AbstractPlugin {
   public:
    AbstractPlugin(AbstractPluginConstructorArgs args);

   private:
    TorustiqPluginInitFnPtr InitPtr;
};

}  // namespace Plugins
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_PLUGINS_ABSTRACT_PLUGIN_H_
