#ifndef _TORUSTIQ_CLI_PIPE_PIPELINE_H_
#define _TORUSTIQ_CLI_PIPE_PIPELINE_H_

#include <string>
#include <vector>

#include "../typedefs/pipeline/pipeline.hpp"
#include "stages/abstract_stage.hpp"

namespace TorustiqCli {
namespace Pipe {

/** A pipeline containing a linear sequence of stages: one source, zero or more
 * processors, one sink */
class Pipeline {
   public:
    /** Constructs a pipeline from a pipeline definition, instantiating stages
     * by position: first = source, last = sink, middle = processors.
     * @param module_dir Path to directory containing plugin libraries to load
     */
    Pipeline(const Typedefs::Pipeline::PipelineDefinition& def,
             const std::string& module_dir);

    /**
     * Initializes stages by calling the initialization method in for each stage
     */
    void initStages();

    /**
     * Starts a pipeline
     */
    void start();

   private:
    std::vector<Stages::AbstractStage*> stages;
};

}  // namespace Pipe
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_PIPE_PIPELINE_H_
