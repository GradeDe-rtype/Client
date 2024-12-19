cmake_minimum_required(VERSION 3.16)
project(gradeDe)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Source files
set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Color.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Error.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Event.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Font.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/FrameRate.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/JoyStick.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/KeyBoard.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Mouse.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Music.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/RectangleShape.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Shape.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Sound.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Text.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Texture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Time.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Vector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Vertex.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/VertexArray.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Window.cpp
)

# Create a static library
add_library(gradeDe STATIC ${SRC})

# Output library to the "lib" directory in the root of the project
set(LIB_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/lib)
set(INCLUDE_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/include)

set_target_properties(gradeDe PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
)

# Ensure output directories exist and copy files
add_custom_command(
    TARGET gradeDe POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${INCLUDE_OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:gradeDe> ${LIB_OUTPUT_DIR}/libgradeDe.a
)
