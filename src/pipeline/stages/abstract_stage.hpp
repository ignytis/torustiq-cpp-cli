#ifndef _TORUSTIQ_CLI_PIPELINE_STAGES_ABSTRACT_STAGE_H_
#define _TORUSTIQ_CLI_PIPELINE_STAGES_ABSTRACT_STAGE_H_

#include <string>

#include "../../plugins/stage_plugin.hpp"
#include "../../typedefs/pipeline/stage.hpp"

using TorustiqCli::Plugins::StagePlugin;

namespace TorustiqCli {
namespace Pipeline {
namespace Stages {

/** Abstract base class for all pipeline stages */
class AbstractStage {
   public:
    string name;
    string handlerId;

    StagePlugin* plugin = nullptr;
    ConfigKV config;

    explicit AbstractStage(
        const TorustiqCli::Typedefs::Pipeline::PipelineStageDefinition& def);
    virtual ~AbstractStage() = default;

    /** Initializes a stage */
    virtual void init() {}
};

}  // namespace Stages
}  // namespace Pipeline
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_PIPELINE_STAGES_ABSTRACT_STAGE_H_
