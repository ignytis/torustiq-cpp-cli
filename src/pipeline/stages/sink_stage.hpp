#ifndef _TORUSTIQ_CLI_PIPE_STAGES_SINK_STAGE_H_
#define _TORUSTIQ_CLI_PIPE_STAGES_SINK_STAGE_H_

#include "abstract_stage.hpp"

namespace TorustiqCli {
namespace Pipeline {
namespace Stages {

/** A sink stage: accepts input from the previous stage and outputs data without
 * passing it further */
class SinkStage : public AbstractStage {
   public:
    explicit SinkStage(
        const TorustiqCli::Typedefs::Pipeline::PipelineStageDefinition& def)
        : AbstractStage(def) {}
};

}  // namespace Stages
}  // namespace Pipeline
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_PIPE_STAGES_SINK_STAGE_H_
