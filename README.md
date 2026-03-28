# CppFactories
C++20 factories for unit tests and mock object

# Requirements
- C++ compiler
- cmake
- conan

# How to build manually
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

# How to build with build.sh
Simply run the script from the project root directory:
```bash
./build.sh
```
To clean the build artifacts, run:
```bash
./build.sh clean
```
