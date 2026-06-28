add_library(graphlink_core
    graph.cpp
)

target_include_directories(graphlink_core
PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
