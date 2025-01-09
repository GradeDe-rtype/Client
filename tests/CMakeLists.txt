# Tests CMakeLists.txt

# ---- DEPENDENCIES ----
file(GLOB TEST_SOURCES "*.cpp")

set(SRC_SOURCES
    ${CMAKE_SOURCE_DIR}/src/Game/Entity/Base/AEntity.cpp
    ${CMAKE_SOURCE_DIR}/src/Game/Entity/Enemy/Enemy.cpp
)

foreach(FILE ${TEST_SOURCES} ${SRC_SOURCES})
    if (NOT EXISTS "${FILE}")
        message(FATAL_ERROR "Source file not found : ${FILE}")
    endif()
endforeach()

# ---- EXECUTABLE ----
add_executable(r-type_tests ${TEST_SOURCES} ${SRC_SOURCES})

# ---- INCLUDES ----
target_include_directories(r-type_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/include/
    ${CMAKE_SOURCE_DIR}/src/
    ${CMAKE_SOURCE_DIR}/src/Game/
    ${CMAKE_SOURCE_DIR}/src/Game/Entity/Enemy/
    ${CMAKE_SOURCE_DIR}/lib/gradeDe/include/
    ${CMAKE_SOURCE_DIR}/lib/papaya/include/
    ${CMAKE_SOURCE_DIR}/lib/rfcArgParser/include/
    ${CMAKE_SOURCE_DIR}/lib/traductor/include/
)

# ---- LINK LIBRARIES ----
target_link_libraries(r-type_tests PRIVATE
    ${Boost_LIBRARIES}
    ${CRITERION_LIBRARIES}
    ${RTYPE_LIBRARIES}
    sfml-graphics sfml-window sfml-system sfml-audio sfml-network
)

# ---- COMPILE OPTIONS ----
target_compile_options(r-type_tests PRIVATE -g -O0)

# ---- TESTS ----
enable_testing()

# ---- ADD TEST ----
add_test(
    NAME RTypeTests
    COMMAND $<TARGET_FILE:r-type_tests>
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# ---- MANUAL TESTS EXECUTION ----
add_custom_target(run_tests
    COMMAND $<TARGET_FILE:r-type_tests>
    DEPENDS r-type_tests
    COMMENT "Manual Criterion test execution"
    VERBATIM
)
