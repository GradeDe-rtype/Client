cmake_minimum_required(VERSION 3.16)
project(RType VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the list of libraries
set(RTYPE_LIBRARIES
    gradeDe
    papaya
    rfcArgParser
)

# Include subdirectories for libraries
foreach(LIB ${RTYPE_LIBRARIES})
    add_subdirectory(lib/${LIB})
endforeach()

# Collect all source files
file(GLOB_RECURSE SOURCES
    "src/**/**/*.cpp"
    "src/**/*.cpp"
    "src/*.cpp"
)

# Define the main executable
add_executable(r-type_client ${SOURCES})

# Include directories for the project and libraries
target_include_directories(r-type_client PRIVATE
    "include/"
    "src/Graphique/Player/"
    "src/Parsing/"
    "src/Utils/Utils/"
    "src/Utils/Path/"
    "src/Ressources/"
)
foreach(LIB ${RTYPE_LIBRARIES})
    target_include_directories(r-type_client PRIVATE "lib/${LIB}/include/")
endforeach()

# Link the libraries
target_link_libraries(r-type_client PRIVATE
    ${RTYPE_LIBRARIES}
    sfml-graphics sfml-window sfml-system sfml-audio sfml-network
)

# Copy the resulting executable to the project root
add_custom_command(TARGET r-type_client POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:r-type_client> ${CMAKE_SOURCE_DIR}
)

# Custom clean target
add_custom_target(fclean
    COMMAND ${CMAKE_COMMAND} -E remove r-type_client
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_SOURCE_DIR}/r-type_client
)
