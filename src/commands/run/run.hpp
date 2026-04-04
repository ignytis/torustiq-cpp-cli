#ifndef _TORUSTIQ_CLI_COMMANDS_RUN_RUN_H_
#define _TORUSTIQ_CLI_COMMANDS_RUN_RUN_H_

#include <string>

#include "../../typedefs/configuration/configuration.hpp"
#include "../abstract.hpp"

using namespace std;

namespace TorustiqCli {
namespace Commands {
namespace Run {

using TorustiqCli::Typedefs::Configuration::Configuration;

/**
 * This command runs a specified pipeline
 */
class RunCommand : public AbstractCommand {
   private:
    Configuration* config;
    string pipeline_path;

   public:
    RunCommand(Configuration* config, string pipeline_path);
    void run();
};

}  // namespace Run
}  // namespace Commands
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_COMMANDS_RUN_RUN_H_
