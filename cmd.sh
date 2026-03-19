#!/usr/bin/env bash

set -eo pipefail

COMMAND=$1
shift

set -u

app_name="$(cat project.json | jq -r '.name')"

function compile {
    make -j$(nproc)
}

function run {
    ./build/$app_name $@
}

if [ "$COMMAND" = "init" ]; then
    cmake -DCMAKE_BUILD_TYPE=Debug .
elif [ "$COMMAND" = "compile" ]; then
    compile
elif [ "$COMMAND" = "run" ]; then
    run $@
elif [ "$COMMAND" = "compile-run" ]; then
    compile
    run $@
elif [ "$COMMAND" = "format" ]; then
    find src \( -name '*.cpp' -o -name '*.hpp' \)  | xargs -I % clang-format -i % -style=file
else
    echo "Usage: ./cmd.sh [init|compile|run|compile-run|format]"
fi