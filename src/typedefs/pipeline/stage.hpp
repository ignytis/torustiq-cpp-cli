#ifndef _TORUSTIQ_CLI_TYPEDEFS_PIPELINE_STAGE_H_
#define _TORUSTIQ_CLI_TYPEDEFS_PIPELINE_STAGE_H_

#include <yaml-cpp/yaml.h>

#include <map>
#include <string>

namespace TorustiqCli {
namespace Typedefs {
namespace Pipeline {

/** Represents a single stage in a pipeline definition */
class PipelineStageDefinition {
   public:
    std::string name;
    std::string handler;
    std::map<std::string, std::string> config;
};

}  // namespace Pipeline
}  // namespace Typedefs
}  // namespace TorustiqCli

namespace YAML {
using namespace TorustiqCli::Typedefs::Pipeline;

template <>
struct convert<PipelineStageDefinition> {
    static Node encode(const PipelineStageDefinition& stage) {
        Node node;
        node["name"] = stage.name;
        node["handler"] = stage.handler;
        for (const std::pair<const std::string, std::string>& kv :
             stage.config) {
            node["config"][kv.first] = kv.second;
        }
        return node;
    }

    static bool decode(const Node& node, PipelineStageDefinition& stage) {
        if (!node.IsMap()) {
            return false;
        }
        stage.name = node["name"].as<std::string>();
        stage.handler = node["handler"].as<std::string>();
        if (node["config"]) {
            for (YAML::const_iterator it = node["config"].begin();
                 it != node["config"].end(); ++it) {
                stage.config[it->first.as<std::string>()] =
                    it->second.as<std::string>();
            }
        }
        return true;
    }
};
}  // namespace YAML

#endif  // _TORUSTIQ_CLI_TYPEDEFS_PIPELINE_STAGE_H_
