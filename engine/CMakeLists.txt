add_library(engine
    src/Engine.cpp
    src/Window.cpp
    # add other engine source files here
)

target_include_directories(engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
