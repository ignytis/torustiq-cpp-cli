#ifndef _TORUSTIQ_CLI_TYPEDEFS_PIPELINE_PIPELINE_H_
#define _TORUSTIQ_CLI_TYPEDEFS_PIPELINE_PIPELINE_H_

#include <yaml-cpp/yaml.h>

#include <string>
#include <vector>

#include "stage.hpp"

namespace TorustiqCli {
namespace Typedefs {
namespace Pipeline {

/** Represents a pipeline definition loaded from a YAML file */
class PipelineDefinition {
   public:
    std::string name;
    std::vector<PipelineStage> stages;
};

}  // namespace Pipeline
}  // namespace Typedefs
}  // namespace TorustiqCli

namespace YAML {
using namespace TorustiqCli::Typedefs::Pipeline;

template <>
struct convert<PipelineDefinition> {
    static Node encode(const PipelineDefinition& pipeline) {
        Node node;
        node["name"] = pipeline.name;
        for (const PipelineStage& stage : pipeline.stages) {
            node["stages"].push_back(stage);
        }
        return node;
    }

    static bool decode(const Node& node, PipelineDefinition& pipeline) {
        if (!node.IsMap()) {
            return false;
        }
        pipeline.name = node["name"].as<std::string>();
        if (node["stages"]) {
            pipeline.stages = node["stages"].as<std::vector<PipelineStage>>();
        }
        return true;
    }
};
}  // namespace YAML

#endif  // _TORUSTIQ_CLI_TYPEDEFS_PIPELINE_PIPELINE_H_
