#include "abstract_stage.hpp"

using TorustiqCli::Pipeline::Stages::AbstractStage;

AbstractStage::AbstractStage(
    const TorustiqCli::Typedefs::Pipeline::PipelineStageDefinition& def)
    : name(def.name), handlerId(def.handler), config(def.config) {}