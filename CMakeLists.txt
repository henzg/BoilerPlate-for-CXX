cmake_minimum_required(VERSION 3.28)

# proj vars
set(proj_name AProject)
set(options_library ALibrary)
set(solutions_library Solutions)
set(app_name App)
set(test_name Tests)

project(${proj_name} LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# cpp settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

# default build type
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# warnings + sanitizers
add_library(${options_library} INTERFACE)

if(MSVC)
    target_compile_options(${options_library} INTERFACE /W4)
else()
    target_compile_options(${options_library} INTERFACE -Wall -Wextra -Wshadow -Wsign-conversion -Wfloat-conversion -Wpedantic)
endif()

option(ENABLE_SANITIZERS "ASan + UBSan in Debug" ON)
if(ENABLE_SANITIZERS AND NOT MSVC)
    target_compile_options(${options_library} INTERFACE $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
    target_link_options(${options_library} INTERFACE $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
endif()

# src/
file(GLOB_RECURSE SOLUTION_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(${solutions_library} STATIC ${SOLUTION_SOURCES})
target_include_directories(${solutions_library} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${solutions_library} PUBLIC ${options_library})

# app exe
add_executable(${app_name} app/main.cpp)
target_link_libraries(${app_name} PRIVATE ${solutions_library})

# tests
enable_testing()
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(${test_name} ${TEST_SOURCES})
target_link_libraries(${test_name} PRIVATE ${solutions_library})
target_include_directories(${test_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libraries/)
add_test(NAME "all tests" COMMAND ${test_name})
