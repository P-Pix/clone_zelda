cmake_minimum_required(VERSION 3.16)
project(ZeldaLike VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML
find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML REQUIRED sfml-all>=2.5)

# Include directories
include_directories(include)

# Collect all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SFML libraries
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${SFML_CFLAGS_OTHER})

# Set compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -O2)

# Copy assets to build directory
file(COPY ${CMAKE_SOURCE_DIR}/image DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/font DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/maping DESTINATION ${CMAKE_BINARY_DIR})
