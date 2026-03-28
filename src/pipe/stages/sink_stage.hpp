#ifndef _TORUSTIQ_CLI_PIPE_STAGES_SINK_STAGE_H_
#define _TORUSTIQ_CLI_PIPE_STAGES_SINK_STAGE_H_

#include "abstract_stage.hpp"

namespace TorustiqCli {
namespace Pipe {
namespace Stages {

/** A sink stage: accepts input from the previous stage and outputs data without
 * passing it further */
class SinkStage : public AbstractStage {};

}  // namespace Stages
}  // namespace Pipe
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_PIPE_STAGES_SINK_STAGE_H_
