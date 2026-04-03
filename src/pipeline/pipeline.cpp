#include "pipeline.hpp"

#include <iostream>
#include <ranges>
#include <stdexcept>
#include <string>
#include <unordered_set>

#include "stages/processor_stage.hpp"
#include "stages/sink_stage.hpp"
#include "stages/source_stage.hpp"

using namespace std;

using namespace TorustiqCli::Pipeline;
using namespace TorustiqCli::Typedefs::Pipeline;

Pipeline::Pipeline(const PipelineDefinition& def) {
    size_t count = def.stages.size();
    if (count < 2) {
        throw std::invalid_argument(
            "Pipeline must have at least a source and a sink stage");
    }
    stages.reserve(count);

    for (size_t i = 0; i < count; ++i) {
        const PipelineStageDefinition& stageDef = def.stages[i];
        Stages::AbstractStage* stage =
            (i == 0) ? static_cast<Stages::AbstractStage*>(
                           new Stages::SourceStage(stageDef))
            : (i == count - 1) ? static_cast<Stages::AbstractStage*>(
                                     new Stages::SinkStage(stageDef))
                               : static_cast<Stages::AbstractStage*>(
                                     new Stages::ProcessorStage(stageDef));
        stages.push_back(stage);
    }
}

unordered_set<string> Pipeline::getHandlersInUse() {
    return stages |
           std::views::transform([](const Stages::AbstractStage* stage) {
               return stage->handlerId;
           }) |
           std::ranges::to<unordered_set<string>>();
}

void Pipeline::setPlugins(vector<TorustiqCli::Plugins::StagePlugin>& plugins) {
    for (Stages::AbstractStage* stage : stages) {
        for (TorustiqCli::Plugins::StagePlugin& plugin : plugins) {
            if (stage->handlerId == plugin.GetId()) {
                stage->plugin = &plugin;
                break;
            }
        }
    }
}

void Pipeline::initStages() {
    for (Stages::AbstractStage* stage : stages) {
        stage->init();
    }
}

void Pipeline::start() { std::cout << "Pipeline started" << std::endl; }
