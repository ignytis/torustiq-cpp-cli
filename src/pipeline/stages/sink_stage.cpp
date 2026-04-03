#include "sink_stage.hpp"

using TorustiqCli::Pipeline::Stages::SinkStage;
using TorustiqCli::Typedefs::Pipeline::PipelineStageDefinition;

SinkStage::SinkStage(const PipelineStageDefinition& def) : AbstractStage(def) {}