#include "run.hpp"

#include <iostream>

using namespace std;

using namespace TorustiqCli::Commands::Run;
using namespace TorustiqCli::Config;

RunCommand::RunCommand(Configuration* config, string pipeline_path)
    : config(config), pipeline_path(pipeline_path) {}

void RunCommand::run() {
    cout << "Executing a pipeline from file: " << pipeline_path << endl
         << "Config: " << config->moduleDir << endl;
}
