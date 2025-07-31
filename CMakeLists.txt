cmake_minimum_required(VERSION 3.16)
project(MySDL2Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Put final executables in bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Always include SDL2 headers (they're needed in both cases)
include_directories(${CMAKE_SOURCE_DIR}/external/SDL2/include)

# ✅ Add this for stb_image.h
include_directories(${CMAKE_SOURCE_DIR}/external)

if(EMSCRIPTEN)
    message(STATUS "Configuring for Emscripten")

    set(SDL2_LIBS "")
else()
    message(STATUS "Configuring for native desktop")

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
