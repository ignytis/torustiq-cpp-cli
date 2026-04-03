#include "processor_stage.hpp"

using TorustiqCli::Pipeline::Stages::ProcessorStage;

ProcessorStage::ProcessorStage(
    const TorustiqCli::Typedefs::Pipeline::PipelineStageDefinition& def)
    : AbstractStage(def) {}