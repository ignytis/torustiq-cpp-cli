#include "env.hpp"

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>

using namespace std;
using namespace TorustiqCli::System;

/**
 * Returns the value of an environment variable, or a default value if not set.
 */
string TorustiqCli::System::getEnv(string key, string defaultValue) {
    char* value = getenv(key.c_str());
    return nullptr == value ? defaultValue : value;
}

/**
 * Returns the platform-specific application home directory.
 */
string TorustiqCli::System::getAppHome(string appName) {
#ifdef _WIN32
    // Windows: Use AppData
    const char* appData = getenv("APPDATA");
    if (appData) {
        return string(appData) + "\\" + appName;
    }
    throw runtime_error("APPDATA environment variable not set");
#elif __APPLE__
    // macOS: $HOME/Library/Application Support/AppName
    const char* home = getenv("HOME");
    if (home) {
        return string(home) + "/Library/Application Support/" + appName;
    }
    throw runtime_error("HOME environment variable not set");
#else
    // Linux: $HOME/.config/appname (XDG standard) or $HOME/.appname
    const char* xdgConfig = getenv("XDG_CONFIG_HOME");
    if (xdgConfig && xdgConfig[0] != '\0') {
        return string(xdgConfig) + "/" + appName;
    }

    const char* home = getenv("HOME");
    if (home) {
        return string(home) + "/.config/" + appName;
    }
    throw runtime_error("HOME environment variable not set");
#endif
}
