#ifndef _TORUSTIQ_CLI_CONFIGURATION_H_
#define _TORUSTIQ_CLI_CONFIGURATION_H_

#include <yaml-cpp/yaml.h>

#include <string>

using namespace std;

namespace TorustiqCli {
namespace Config {

/** Main configuration class */
class Configuration {
   public:
    string moduleDir;
};

}  // namespace Config
}  // namespace TorustiqCli

namespace YAML {
using namespace TorustiqCli::Config;

template <>
struct convert<Configuration> {
    // From C++ to YAML
    static Node encode(const Configuration& cfg) {
        Node node;
        node["module_dir"] = cfg.moduleDir;
        return node;
    }

    // From YAML to C++
    static bool decode(const Node& node, Configuration& cfg) {
        if (!node.IsMap()) {
            return false;
        }
        cfg.moduleDir = node["module_dir"].as<std::string>();
        return true;
    }
};
}  // namespace YAML

#endif