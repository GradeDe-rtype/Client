# Tests CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(RType VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#  ---- FIND PACKAGES ---- #
find_package(Boost 1.70 REQUIRED COMPONENTS system)
find_package(SFML REQUIRED COMPONENTS graphics window system audio network)
find_package(PkgConfig REQUIRED)
pkg_check_modules(CRITERION REQUIRED criterion)

# ---- INCLUDE LIBRARIES ---- #
set(LIBRARY_PATH ${CMAKE_SOURCE_DIR}/../lib)
set(GRADEDE_LIB ${LIBRARY_PATH}/libgradeDe.a)
set(PAPAYA_LIB ${LIBRARY_PATH}/libpapaya.a)
set(RFCARGPARSER_LIB ${LIBRARY_PATH}/librfcArgParser.a)
set(TRADUCTOR_LIB ${LIBRARY_PATH}/libtraductor.a)

# ---- SOURCES ---- #
file(GLOB TEST_SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")

# ---- SRC SOURCES ---- #
file(GLOB_RECURSE SRC_SOURCES
    "${CMAKE_SOURCE_DIR}/../src/**/*.cpp"
)

# ---- CHECK FILES ---- #
foreach(FILE ${TEST_SOURCES} ${SRC_SOURCES})
    if (NOT EXISTS "${FILE}")
        message(FATAL_ERROR "Source file not found: ${FILE}")
    endif()
endforeach()

# ---- EXECUTABLE ---- #
add_executable(r-type_tests ${TEST_SOURCES} ${SRC_SOURCES})

# ---- INCLUDES ---- #
target_include_directories(r-type_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/../include/
    ${CMAKE_SOURCE_DIR}/../src/
    ${CMAKE_SOURCE_DIR}/../src/Game/
    ${CMAKE_SOURCE_DIR}/../src/Game/Components/
    ${CMAKE_SOURCE_DIR}/../src/Game/Entity/
    ${CMAKE_SOURCE_DIR}/../src/Game/Entity/Base/
    ${CMAKE_SOURCE_DIR}/../src/Game/Entity/Enemy/
    ${CMAKE_SOURCE_DIR}/../src/Game/Entity/Player/
    ${CMAKE_SOURCE_DIR}/../src/Game/Entity/SelectArrow/
    ${CMAKE_SOURCE_DIR}/../src/Game/Entity/Shoot/
    ${CMAKE_SOURCE_DIR}/../src/Game/Managers/
    ${CMAKE_SOURCE_DIR}/../src/Game/Scenes/
    ${CMAKE_SOURCE_DIR}/../src/Game/Room/
    ${CMAKE_SOURCE_DIR}/../src/Game/Timer/
    ${CMAKE_SOURCE_DIR}/../src/Parsing/
    ${CMAKE_SOURCE_DIR}/../src/Server/
    ${CMAKE_SOURCE_DIR}/../src/Network/
    ${CMAKE_SOURCE_DIR}/../src/Utils/
    ${CMAKE_SOURCE_DIR}/../src/Utils/Path/
    ${CMAKE_SOURCE_DIR}/../lib/gradeDe/include/
    ${CMAKE_SOURCE_DIR}/../lib/papaya/include/
    ${CMAKE_SOURCE_DIR}/../lib/rfcArgParser/include/
    ${CMAKE_SOURCE_DIR}/../lib/traductor/include/
)

# ---- LINK LIBRARIES ---- #
target_link_libraries(r-type_tests PRIVATE
    ${Boost_LIBRARIES}
    ${CRITERION_LIBRARIES}
    ${GRADEDE_LIB}
    ${PAPAYA_LIB}
    ${RFCARGPARSER_LIB}
    ${TRADUCTOR_LIB}
    sfml-graphics sfml-window sfml-system sfml-audio sfml-network
)

# ---- COMPILE OPTIONS ---- #
target_compile_options(r-type_tests PRIVATE -g -O0)

# ---- TESTS ---- #
enable_testing()

# ---- ADD TEST ---- #
add_test(
    NAME RTypeTests
    COMMAND $<TARGET_FILE:r-type_tests>
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/../assets ${CMAKE_BINARY_DIR}/assets
)
add_dependencies(r-type_tests copy_assets)


# ---- MANUAL TESTS EXECUTION ---- #
add_custom_target(run_tests
    COMMAND $<TARGET_FILE:r-type_tests>
    DEPENDS r-type_tests
    COMMENT "Manual Criterion test execution"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    VERBATIM
)
