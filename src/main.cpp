#include <CLI/CLI.hpp>

#include "defs.hpp"

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

    CLI11_PARSE(app, argc, argv);


    return 0;
}