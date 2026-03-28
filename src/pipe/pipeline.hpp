#ifndef _TORUSTIQ_CLI_PIPE_PIPELINE_H_
#define _TORUSTIQ_CLI_PIPE_PIPELINE_H_

#include <vector>

#include "stages/abstract_stage.hpp"

namespace TorustiqCli {
namespace Pipe {

/** A pipeline containing a linear sequence of stages: one source, zero or more processors, one sink */
class Pipeline {
 private:
  std::vector<Stages::AbstractStage*> stages_;
};

}  // namespace Pipe
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_PIPE_PIPELINE_H_
