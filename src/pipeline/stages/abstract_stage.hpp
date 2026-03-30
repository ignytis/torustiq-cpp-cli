#ifndef _TORUSTIQ_CLI_PIPE_STAGES_ABSTRACT_STAGE_H_
#define _TORUSTIQ_CLI_PIPE_STAGES_ABSTRACT_STAGE_H_

#include <string>

#include "../../typedefs/pipeline/stage.hpp"

using namespace std;

namespace TorustiqCli {
namespace Pipeline {
namespace Stages {

/** Abstract base class for all pipeline stages */
class AbstractStage {
   public:
    string name;
    string handlerId;

    explicit AbstractStage(
        const TorustiqCli::Typedefs::Pipeline::PipelineStageDefinition& def)
        : name(def.name), handlerId(def.handler) {}
    virtual ~AbstractStage() = default;
};

}  // namespace Stages
}  // namespace Pipeline
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_PIPE_STAGES_ABSTRACT_STAGE_H_
