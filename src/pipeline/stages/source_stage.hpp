#ifndef _TORUSTIQ_CLI_PIPE_STAGES_SOURCE_STAGE_H_
#define _TORUSTIQ_CLI_PIPE_STAGES_SOURCE_STAGE_H_

#include "abstract_stage.hpp"

namespace TorustiqCli {
namespace Pipeline {
namespace Stages {

/** A source stage: accepts an incoming payload and forwards it to the next
 * stage */
class SourceStage : public AbstractStage {
   public:
    explicit SourceStage(
        const TorustiqCli::Typedefs::Pipeline::PipelineStageDefinition& def)
        : AbstractStage(def) {}
};

}  // namespace Stages
}  // namespace Pipeline
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_PIPE_STAGES_SOURCE_STAGE_H_
