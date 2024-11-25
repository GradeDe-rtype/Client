cmake_minimum_required(VERSION 3.16)
project(RType VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include subdirectories for libraries
add_subdirectory(lib/papaya)

# Collect all source files
file(GLOB_RECURSE SOURCES
    "src/**/*.cpp"
    "src/*.cpp"
)

# Define the main executable
add_executable(rtype ${SOURCES})

# Include directories for the project and libraries
target_include_directories(rtype PRIVATE
    "include/"
)

# Link the libraries
target_link_libraries(rtype PRIVATE
    papaya
    sfml-graphics sfml-window sfml-system sfml-audio sfml-network
)

# Copy the resulting executable to the project root
add_custom_command(TARGET rtype POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:rtype> ${CMAKE_SOURCE_DIR}
)

# Custom clean target
add_custom_target(fclean
    COMMAND ${CMAKE_COMMAND} -E remove rtype
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_SOURCE_DIR}/rtype
)
