#ifndef _TORUSTIQ_CLI_COMMANDS_ABSTRACT_H_
#define _TORUSTIQ_CLI_COMMANDS_ABSTRACT_H_

namespace TorustiqCli {
namespace Commands {
class AbstractCommand {
   public:
    virtual void run() = 0;
};
}  // namespace Commands
}  // namespace TorustiqCli

#endif  // _TORUSTIQ_CLI_COMMANDS_ABSTRACT_H_
