Personal boilerplate for simple projects. This is intended to quickly have a working CMAKE + CXX + Testing project without doing the manual work. Should work cross platform as well.

Symlink: 
- ln -s build/compile_commands.json compile_commands.json
- from root after first build to symlink the file.

Compile:
- cmake -S . -B build -G Ninja

Build:
- cmake --build build

Test:
- ctest --test-dir build --output-on-failure

Run:
- ./build/Tests
- ./build/App
