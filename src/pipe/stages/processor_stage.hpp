#ifndef _TORUSTIQ_CLI_PIPE_STAGES_PROCESSOR_STAGE_H_
#define _TORUSTIQ_CLI_PIPE_STAGES_PROCESSOR_STAGE_H_

#include "abstract_stage.hpp"

namespace TorustiqCli {
namespace Pipe {
namespace Stages {

/** A processor stage: accepts data from the previous stage, transforms it, and passes it further */
class ProcessorStage : public AbstractStage {};

}  // namespace Stages
}  // namespace Pipe
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_PIPE_STAGES_PROCESSOR_STAGE_H_
