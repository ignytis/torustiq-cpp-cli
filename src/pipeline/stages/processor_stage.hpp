#ifndef _TORUSTIQ_CLI_PIPELINE_STAGES_PROCESSOR_STAGE_H_
#define _TORUSTIQ_CLI_PIPELINE_STAGES_PROCESSOR_STAGE_H_

#include "abstract_stage.hpp"

namespace TorustiqCli {
namespace Pipeline {
namespace Stages {

/** A processor stage: accepts data from the previous stage, transforms it, and
 * passes it further */
class ProcessorStage : public AbstractStage {
   public:
    explicit ProcessorStage(
        const TorustiqCli::Typedefs::Pipeline::PipelineStageDefinition& def)
        : AbstractStage(def) {}
};

}  // namespace Stages
}  // namespace Pipeline
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_PIPELINE_STAGES_PROCESSOR_STAGE_H_
