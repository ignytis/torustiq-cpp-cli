#ifndef _TORUSTIQ_CLI_SYSTEM_ENV_H_
#define _TORUSTIQ_CLI_SYSTEM_ENV_H_

#include <string>

using namespace std;

namespace TorustiqCli {
namespace System {

/**
 * Returns a value of environment variable,
 * or default value if environment variable is not defined
 */
string getEnv(string key, string defaultValue = "");

/**
 * Returns the platform-specific application home directory.
 */
string getAppHome(string appName);

}  // namespace System
}  // namespace TorustiqCli

#endif
