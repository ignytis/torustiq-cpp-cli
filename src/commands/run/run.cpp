#include "run.hpp"

#include <iostream>

using namespace std;

using namespace TorustiqCli::Commands::Run;

RunCommand::RunCommand(string pipeline_path)
    : pipeline_path(pipeline_path) {}

void RunCommand::run() { cout << "Executing a pipeline from file: " << pipeline_path << endl; }
