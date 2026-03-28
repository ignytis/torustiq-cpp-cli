#include "pipeline.hpp"

#include <stdexcept>

#include "stages/processor_stage.hpp"
#include "stages/sink_stage.hpp"
#include "stages/source_stage.hpp"

using namespace TorustiqCli::Pipe;
using namespace TorustiqCli::Typedefs::Pipeline;

Pipeline::Pipeline(const PipelineDefinition& def) {
    size_t count = def.stages.size();
    if (count < 2) {
        throw std::invalid_argument(
            "Pipeline must have at least a source and a sink stage");
    }
    for (size_t i = 0; i < count; ++i) {
        Stages::AbstractStage* stage =
            (i == 0)
                ? static_cast<Stages::AbstractStage*>(new Stages::SourceStage())
            : (i == count - 1)
                ? static_cast<Stages::AbstractStage*>(new Stages::SinkStage())
                : static_cast<Stages::AbstractStage*>(
                      new Stages::ProcessorStage());
        stages_.push_back(stage);
    }
}

#include <iostream>
void Pipeline::start() { std::cout << "Pipeline started" << std::endl; }