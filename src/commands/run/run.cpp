#include "run.hpp"

#include <iostream>

using namespace std;

using namespace TorustiqCli::Commands::Run;

RunCommand::RunCommand(string module_dir, string pipeline_path)
    : module_dir(module_dir), pipeline_path(pipeline_path) {}

void RunCommand::run() { cout << "hello2" << endl; }
