#include "run.hpp"

#include <yaml-cpp/yaml.h>

#include <filesystem>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>

#include "../../pipeline/pipeline.hpp"
#include "../../plugins/builtin/factory.hpp"
#include "../../plugins/stage_plugin.hpp"
#include "../../system/dll.hpp"
#include "../../typedefs/pipeline/pipeline.hpp"

using namespace std;
using namespace std::ranges;

using TorustiqCli::Commands::Run::RunCommand;
using TorustiqCli::Pipeline::Pipeline;
using TorustiqCli::System::DynamicLibrary;
using TorustiqCli::System::kLibFileExtension;
using TorustiqCli::Typedefs::Pipeline::PipelineDefinition;

RunCommand::RunCommand(Configuration* config, string pipeline_path)
    : config(config), pipeline_path(pipeline_path) {}

void RunCommand::run() {
    cout << "Executing a pipeline from file: " << pipeline_path << endl
         << "Config dir: " << config->moduleDir << endl;

    PipelineDefinition pipeDef =
        YAML::LoadFile(pipeline_path).as<PipelineDefinition>();
    Pipeline::Pipeline pipeline = Pipeline::Pipeline(pipeDef);
    cout << "Pipeline name: " << pipeDef.name << endl;

    unordered_set<string> handlers = pipeline.getHandlersInUse();
    cout << "Pipeline handlers in use:" << endl;
    for (const string& handler : handlers) {
        cout << "\t" << handler << endl;
    }

    // Format a set of plugins. Start with builtins
    vector<StagePlugin> plugins_builtin =
        TorustiqCli::Plugins::Builtin::GetBuiltinPlugins();

    // TODO: implement plugins here
    for (const filesystem::directory_entry& entry :
         filesystem::directory_iterator(config->moduleDir)) {
        if (entry.path().extension() == kLibFileExtension) {
            DynamicLibrary lib = DynamicLibrary(entry.path().string());
            // lib.get("init");
        }
    }

    vector<StagePlugin> plugins =
        plugins_builtin | views::filter([&handlers](const StagePlugin& plugin) {
            return handlers.contains(plugin.GetId());
        }) |
        to<vector<StagePlugin>>();

    for (StagePlugin& plugin : plugins) {
        plugin.init();
    }

    pipeline.start();
}
