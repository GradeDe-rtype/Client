cmake_minimum_required(VERSION 3.5)
project(RType VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES
        "src/**/*.cpp"
        "src/*.cpp"
)

add_executable(rtype ${SOURCES})
target_include_directories(rtype PRIVATE
    "include/"
)

target_link_libraries(rtype PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network)

add_custom_command(TARGET rtype POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:rtype> ${CMAKE_SOURCE_DIR}
)

add_custom_target(fclean
    COMMAND ${CMAKE_COMMAND} -E remove rtype
    COMMAND ${CMAKE_COMMAND} -E remove ../rtype
)