#include "run.hpp"

#include <yaml-cpp/yaml.h>

#include <iostream>

#include "../../pipeline/pipeline.hpp"
#include "../../typedefs/pipeline/pipeline.hpp"

using namespace std;

using TorustiqCli::Commands::Run::RunCommand;
using TorustiqCli::Typedefs::Pipeline::PipelineDefinition;
using TorustiqCli::Pipeline::Pipeline;

RunCommand::RunCommand(Configuration* config, string pipeline_path)
    : config(config), pipeline_path(pipeline_path) {}

void RunCommand::run() {
    cout << "Executing a pipeline from file: " << pipeline_path << endl
         << "Config: " << config->moduleDir << endl;

    PipelineDefinition pipeDef =
        YAML::LoadFile(pipeline_path).as<PipelineDefinition>();
    Pipeline::Pipeline pipeline = Pipeline::Pipeline(pipeDef, config->moduleDir);

    cout << "Pipeline name: " << pipeDef.name << endl;
    pipeline.start();
}
