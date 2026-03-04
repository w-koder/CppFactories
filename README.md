# CppFactories
C++20 factories for unit tests and mock object

# Requirements
- C++ compiler
- cmake
- conan

# How to build
1.
conan profile detect --force
-> Detect profile and set compiler version to C++20 or C++23
compiler.cppstd=gnu23

2.
conan install . --output-folder=build --build=missing

3. 
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build .
