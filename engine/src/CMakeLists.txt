add_library(graphlink_core
    graph.cpp
    union_find.cpp
    bfs.cpp
)

target_include_directories(graphlink_core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)