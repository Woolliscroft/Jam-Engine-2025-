cmake_minimum_required(VERSION 3.16)
project(MySDL2Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Put final executables in bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Always include SDL2 headers (they're needed in both cases)
include_directories(${CMAKE_SOURCE_DIR}/external/SDL2/include)

if(EMSCRIPTEN)
    message(STATUS "Configuring for Emscripten")

    # For Emscripten, SDL2 is built-in — no linking against external libs
    set(SDL2_LIBS "")

    # You can add Emscripten-specific linker flags here if needed,
    # for example to preload assets in your game/CMakeLists.txt

else()
    message(STATUS "Configuring for native desktop")

    # Link SDL2 libraries based on compiler
    if(MSVC)
        link_directories(${CMAKE_SOURCE_DIR}/external/SDL2/lib/msvc)
        set(SDL2_LIBS SDL2 SDL2main)
    else()
        link_directories(${CMAKE_SOURCE_DIR}/external/SDL2/lib/mingw)
        set(SDL2_LIBS SDL2 SDL2main)
    endif()
endif()

# Add your engine and game subprojects
add_subdirectory(engine)
add_subdirectory(game)
