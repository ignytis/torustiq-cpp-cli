#ifndef _TORUSTIQ_CLI_COMMANDS_RUN_RUN_H_
#define _TORUSTIQ_CLI_COMMANDS_RUN_RUN_H_

#include <string>

#include "../abstract.hpp"

namespace TorustiqCli {
namespace Commands {
namespace Run {

/// Command to execute a pipeline
class RunCommand : public AbstractCommand {
   private:
    std::string config_path;
    std::string pipeline_path;

   public:
    RunCommand(std::string config_path, std::string pipeline_path);
    void run();
};

}  // namespace Run
}  // namespace Commands
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_COMMANDS_RUN_RUN_H_
