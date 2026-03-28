# CppFactories
C++20 factories for unit tests and mock object

# Requirements
- C++ compiler
- cmake
- conan

# How to build
1.
```bash
conan profile detect --name mycpp23
```
-> Creates your custom profile 
compiler.cppstd=gnu23

2.
```bash
conan install . --output-folder=build --build=missing --profile=mycpp23
```

3. 
```bash
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build .
```
