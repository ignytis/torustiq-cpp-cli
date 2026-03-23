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
    string sub_run_option_pipeline_path;
    string sub_run_option_module_dir;
    sub_run->add_option("-p,--pipeline-path", sub_run_option_pipeline_path,
                        "Path to pipeline file e.g. mypipeline.yaml");
    sub_run->add_option("-m,--module-dir", sub_run_option_module_dir,
                        "Pipeline filename e.g. /opt/mymodules");

    AbstractCommand* cmd;

    CLI11_PARSE(app, argc, argv);

    if (sub_run->parsed()) {
        cmd = new RunCommand(sub_run_option_pipeline_path,
                             sub_run_option_module_dir);
        cmd->run();
    }

    return 0;
}