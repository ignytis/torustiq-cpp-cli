#ifndef _TORUSTIQ_CLI_PIPELINE_PIPELINE_H_
#define _TORUSTIQ_CLI_PIPELINE_PIPELINE_H_

#include <string>
#include <unordered_set>
#include <vector>

#include "../typedefs/pipeline/pipeline.hpp"
#include "stages/abstract_stage.hpp"

using namespace std;

namespace TorustiqCli {
namespace Pipeline {

/** A pipeline containing a linear sequence of stages: one source, zero or more
 * processors, one sink */
class Pipeline {
   public:
    /** Constructs a pipeline from a pipeline definition, instantiating stages
     * by position: first = source, last = sink, middle = processors.
     * @param module_dir Path to directory containing plugin libraries to load
     */
    Pipeline(const Typedefs::Pipeline::PipelineDefinition& def);

    /** Returns a set of handlers which are in use by pipeline */
    unordered_set<string> getHandlersInUse();

    /**
     * Initializes stages by calling the initialization method in for each stage
     */
    void initStages();

    /**
     * Starts a pipeline
     */
    void start();

   private:
    vector<Stages::AbstractStage*> stages;
};

}  // namespace Pipeline
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_PIPELINE_PIPELINE_H_
