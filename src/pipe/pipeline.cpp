#include "pipeline.hpp"

#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>

#include "../system/dll.hpp"
#include "stages/processor_stage.hpp"
#include "stages/sink_stage.hpp"
#include "stages/source_stage.hpp"

using namespace TorustiqCli::Pipe;
using namespace TorustiqCli::System;
using namespace TorustiqCli::Typedefs::Pipeline;

Pipeline::Pipeline(const PipelineDefinition& def,
                   const std::string& module_dir) {
    size_t count = def.stages.size();
    if (count < 2) {
        throw std::invalid_argument(
            "Pipeline must have at least a source and a sink stage");
    }
    stages.reserve(count);

    for (size_t i = 0; i < count; ++i) {
        Stages::AbstractStage* stage =
            (i == 0)
                ? static_cast<Stages::AbstractStage*>(new Stages::SourceStage())
            : (i == count - 1)
                ? static_cast<Stages::AbstractStage*>(new Stages::SinkStage())
                : static_cast<Stages::AbstractStage*>(
                      new Stages::ProcessorStage());
        stages.push_back(stage);
    }

    for (const std::filesystem::directory_entry& entry :
         std::filesystem::directory_iterator(module_dir)) {
        if (entry.path().extension() == kLibExt) {
            DynamicLibrary(entry.path().string());
        }
    }
}

void Pipeline::initStages() {}

void Pipeline::start() { std::cout << "Pipeline started" << std::endl; }
