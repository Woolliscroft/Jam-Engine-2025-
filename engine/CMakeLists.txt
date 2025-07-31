add_library(engine
    src/Engine.cpp
    src/Window.cpp
    src/TextureLoader.cpp
    src/ResourceManager.cpp
    # Add Engine Source Files here
)

target_include_directories(engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
