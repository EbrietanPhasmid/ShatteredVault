cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXE_LINKER_FLAGS "-L/opt/homebrew/opt/sdl2/lib -L/opt/homebrew/opt/sdl2_image/lib")

project(Shattered-Vault VERSION 1.0.0)

# Find pkg-config
find_package(PkgConfig REQUIRED)

# Locate SDL2 using pkg-config
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)

# Add executable
add_executable(${PROJECT_NAME} src/main.cc)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include utils ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror)

# Google Test using FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.8.0.zip
)
FetchContent_MakeAvailable(googletest)

# Add tests
if(BUILD_TESTING)
  add_executable(Shattered-Vault-Tests tests/drawcalltest.cc)
  target_include_directories(Shattered-Vault-Tests PRIVATE include utils src ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
  target_link_libraries(Shattered-Vault-Tests PRIVATE gtest gtest_main ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
  target_compile_options(Shattered-Vault-Tests PRIVATE -Wall -Werror)

  enable_testing()
  add_test(NAME DrawCallTest COMMAND Shattered-Vault-Tests)
endif()