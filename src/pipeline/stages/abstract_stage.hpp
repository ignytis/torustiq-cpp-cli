#ifndef _TORUSTIQ_CLI_PIPE_STAGES_ABSTRACT_STAGE_H_
#define _TORUSTIQ_CLI_PIPE_STAGES_ABSTRACT_STAGE_H_

namespace TorustiqCli {
namespace Pipeline {
namespace Stages {

/** Abstract base class for all pipeline stages */
class AbstractStage {
   public:
    virtual ~AbstractStage() = default;
};

}  // namespace Stages
}  // namespace Pipe
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_PIPE_STAGES_ABSTRACT_STAGE_H_
