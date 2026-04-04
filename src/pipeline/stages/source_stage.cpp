#include "source_stage.hpp"

using TorustiqCli::Pipeline::Stages::SourceStage;
using TorustiqCli::Typedefs::Pipeline::PipelineStageDefinition;

SourceStage::SourceStage(const PipelineStageDefinition& def)
    : AbstractStage(def) {}
