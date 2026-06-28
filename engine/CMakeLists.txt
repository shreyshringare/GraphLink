cmake_minimum_required(VERSION 3.28)

project(
    GraphLinkEngine
    VERSION 0.1.0
    DESCRIPTION "High-performance graph algorithm engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable compile_commands.json (helps VS Code IntelliSense)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add source directories
add_subdirectory(src)

add_executable(graph_tests
    tests/main.cpp
)

target_link_libraries(graph_tests
    PRIVATE
    graphlink_core
)