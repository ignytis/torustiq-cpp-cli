#include <CLI/CLI.hpp>

#include "commands/abstract.hpp"
#include "commands/run/run.hpp"
#include "defs.hpp"

using namespace TorustiqCli::Commands;
using namespace TorustiqCli::Commands::Run;

using namespace std;

int main(int argc, char* argv[]) {
    CLI::App app{APP_DESCRIPTION};

    CLI::App* sub_run = app.add_subcommand("run", "Runs a pipeline");
    string sub_run_option_config;
    string sub_run_option_filename;
    sub_run->add_option("-c,--config", sub_run_option_config,
                        "Path to configuration file e.g. torustiq.yaml");
    sub_run->add_option("-f,--file", sub_run_option_filename,
                        "Pipeline filename e.g. pipeline.yaml");

    AbstractCommand* cmd;

    CLI11_PARSE(app, argc, argv);

    if (sub_run->parsed()) {
        cmd = new RunCommand(sub_run_option_config, sub_run_option_filename);
        cmd->run();
    }

    return 0;
}