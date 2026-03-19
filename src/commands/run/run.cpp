#include "run.hpp"

#include <iostream>

using namespace std;

using namespace TorustiqCli::Commands::Run;

RunCommand::RunCommand(string config_path, string pipeline_path)
    : config_path(config_path), pipeline_path(pipeline_path) {}

void RunCommand::run() { cout << "hello" << endl; }
