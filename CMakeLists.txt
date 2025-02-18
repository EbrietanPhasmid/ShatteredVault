cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXE_LINKER_FLAGS "-L/opt/homebrew/opt/sdl2/lib -L/opt/homebrew/opt/sdl2_image/lib")

project(Shattered-Vault VERSION 1.0.0)

# Find pkg-config
find_package(PkgConfig REQUIRED)

# Locate SDL2 using pkg-config
pkg_search_module(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})

# Locate SDL2_image using pkg-config
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# Our project has an executable that is generated
add_executable(${PROJECT_NAME} src/main.cc)

# Link libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Include project-specific headers
target_include_directories(${PROJECT_NAME} PRIVATE include/)

add_subdirectory(tests)

set(CMAKE_CXX_FLAGS "-Wall -Werror")