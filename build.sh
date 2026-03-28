#!/bin/bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$SCRIPT_DIR/build"
PROFILE_NAME="mycpp23"

usage() {
    echo "Usage: ./build.sh [OPTIONS]"
    echo ""
    echo "Options:"
    echo "  clean    Perform a clean build (removes and rebuilds from scratch)"
    echo "  (none)   Perform a regular build"
    echo "  --help   Display this help message"
    exit 0
}

if [ "$1" == "--help" ] || [ "$1" == "-h" ]; then
    usage
fi

if [ "$1" == "clean" ]; then
    echo "Performing clean build..."
    rm -rf "$BUILD_DIR"
fi

# Create conan profile if it doesn't exist
if ! conan profile show --profile "$PROFILE_NAME" > /dev/null 2>&1; then
    echo "Creating conan profile '$PROFILE_NAME'..."
    conan profile detect --name "$PROFILE_NAME"
fi

echo "Installing dependencies with conan..."
conan install "$SCRIPT_DIR" --output-folder="$BUILD_DIR" --build=missing --profile="$PROFILE_NAME"

cd "$BUILD_DIR"

echo "Configuring with cmake..."
cmake "$SCRIPT_DIR" -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release

echo "Building project..."
cmake --build .

cd "$SCRIPT_DIR"

echo ""
echo "Build complete!"
echo "Executables:"
[ -f "$BUILD_DIR/dummy_app" ] && echo "  - dummy_app"
[ -f "$BUILD_DIR/g_test" ] && echo "  - g_test"
