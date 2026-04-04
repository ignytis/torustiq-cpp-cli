#ifndef _TORUSTIQ_CLI_TYPEDEFS_CONFIGURATION_H_
#define _TORUSTIQ_CLI_TYPEDEFS_CONFIGURATION_H_

#include <yaml-cpp/yaml.h>

#include <string>

using namespace std;

namespace TorustiqCli {
namespace Typedefs {
namespace Configuration {

/** Main configuration class */
class Configuration {
   public:
    string moduleDir;
};

}  // namespace Configuration
}  // namespace Typedefs
}  // namespace TorustiqCli

namespace YAML {
using namespace TorustiqCli::Typedefs::Configuration;

template <>
struct convert<Configuration> {
    static Node encode(const Configuration& cfg) {
        Node node;
        node["module_dir"] = cfg.moduleDir;
        return node;
    }

    static bool decode(const Node& node, Configuration& cfg) {
        if (!node.IsMap()) {
            return false;
        }
        cfg.moduleDir = node["module_dir"].as<string>();
        return true;
    }
};
}  // namespace YAML

#endif  // _TORUSTIQ_CLI_TYPEDEFS_CONFIGURATION_H_
