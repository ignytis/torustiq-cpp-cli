# Project: torustiq-cli

## General instructions

- CMake + GNU Make are used to build the project
- In Linux, the compiled binary `torustiq` is located in `build` directory

## Libraries in use

- C11
- yaml-cpp

## Project structure

- All `*.cpp` and `*.hpp` source files are located in `src` directory

## Coding style

- Use the Google C++ Style Guide
- Prefer modern C++ standard (C++23) features if they are compatible
  with current versions of Linux and Windows compilers
- Prefer ternary operators instead of if-else blocks with single statements
- Return early if the whole remaining code inside function is if-else statement
- Prefer explicit type declaration over `auto` keyword
- Format code by invocation of `clang-format` via `./cmd.sh format`
- Add comments for classes and functions
- Avoid using exceptions. For critical errors print the error message to stdout
  and exit with non-zero status code


## Namespaces

- Namespaces are used to organize code into logical units. The structure of namespaces should
  reflect the project's directory structure, e.g.
  `src/some/dir` directory -> `TorustiqCli::Some::Dir`
- When using `std` namespace, avoid `std::` prefix; use `using namespace std;` instead

### CMakeLists.txt

- Keep only one `CMakeLists.txt` file in the root directory

### `#include` statements

- Include guards in header files have a `_H_` suffix and include a path to header file relatively
  to `src` directory. Example: `src/dir/subdir/myfile.hpp` -> `_TORUSTIQ_CLI_DIR_SUBDIR_MYFILE_H_`
- Group the `#include` statements, adding an empty line between each group:
  - for `*.cpp` files the corresponding `*.hpp` file is first
  - standard library includes, like `#include <iostream>`
  - third-party includes, like `#include <vendor/lib.h>`
  - project includes, like `#include "myfile.h"`
- Group include statements: global includes e.g. `<MyModule>` are placed before
  relative includes like `"mymodule.h"`. Groups are separated with empty line.
- Prefer relative paths in `#include` statements

### *.cpp files

- Prefer `using namespace <namespace>;` instead of `namespace <namespace> {`

## Validation of result

- Use multi-threaded building when applicable
- In Unix environments use `./cmd.sh compile` to build the project
