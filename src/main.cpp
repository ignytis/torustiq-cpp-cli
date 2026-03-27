#include <yaml-cpp/yaml.h>

#include <CLI/CLI.hpp>

#include "commands/abstract.hpp"
#include "commands/run/run.hpp"
#include "config/configuration.hpp"
#include "defs.hpp"
#include "system/env.hpp"

using namespace TorustiqCli::Commands;
using namespace TorustiqCli::Commands::Run;
using namespace TorustiqCli::Config;
using namespace TorustiqCli::System;

using namespace std;

int main(int argc, char* argv[]) {
    CLI::App app{APP_DESCRIPTION};

    CLI::App* sub_run = app.add_subcommand("run", "Runs a pipeline");
    string sub_run_option_pipeline_path;
    sub_run->add_option("pipeline-path", sub_run_option_pipeline_path,
                        "Path to pipeline file e.g. mypipeline.yaml");

    CLI11_PARSE(app, argc, argv);

    if (sub_run->parsed()) {
        string torustiqConfigPath =
            getEnv("TORUSTIQ_CONFIG", getAppHome(APP_NAME) + "/config.yaml");
        YAML::Node configYaml = YAML::LoadFile(torustiqConfigPath);
        Configuration config = configYaml.as<Configuration>();

        RunCommand cmd(&config, sub_run_option_pipeline_path);
        cmd.run();
    }

    return 0;
}