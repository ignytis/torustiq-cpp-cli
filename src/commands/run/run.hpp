#ifndef _TORUSTIQ_CLI_COMMANDS_RUN_RUN_H_
#define _TORUSTIQ_CLI_COMMANDS_RUN_RUN_H_

#include <string>

#include "../abstract.hpp"

namespace TorustiqCli {
namespace Commands {
namespace Run {

/**
 * This command runs a specified pipeline
 */
class RunCommand : public AbstractCommand {
   private:
    std::string module_dir;
    std::string pipeline_path;

   public:
    RunCommand(std::string module_dir, std::string pipeline_path);
    void run();
};

}  // namespace Run
}  // namespace Commands
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_COMMANDS_RUN_RUN_H_
