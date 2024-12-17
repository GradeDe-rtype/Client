#  ---- SETUP ---- #
cmake_minimum_required(VERSION 3.16)
project(RType VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#  ---- FIND BOOST ---- #
find_package(Boost 1.70 REQUIRED COMPONENTS system)

#  ---- LIBRARIES ---- #
set(RTYPE_LIBRARIES
    gradeDe
    papaya
    rfcArgParser
)

foreach(LIB ${RTYPE_LIBRARIES})
    add_subdirectory(lib/${LIB})
endforeach()

#  ---- SOURCES ---- #
file(GLOB_RECURSE SOURCES
    "src/**/**/**/*.cpp"
    "src/**/**/*.cpp"
    "src/**/*.cpp"
    "src/*.cpp"
)

#  ---- EXECUTABLE ---- #
add_executable(r-type_client ${SOURCES})

#  ---- INCLUDES ---- #
foreach(LIB ${RTYPE_LIBRARIES})
    target_include_directories(r-type_client PRIVATE "lib/${LIB}/include/")
endforeach()

target_include_directories(r-type_client PRIVATE
    ${Boost_INCLUDE_DIRS}
    "include/"
    "src/"
    "src/Communication/"
    "src/Communication/Client/"
    "src/Communication/Commands/"
    "src/Communication/SendList/"
    "src/Game/"
    "src/Game/Audio/"
    "src/Game/Audio/MusicManager/"
    "src/Game/Client/"
    "src/Game/Components/Entity/"
    "src/Game/Components/Entity/Base/"
    "src/Game/Components/Entity/Enemy/"
    "src/Game/Components/Entity/Player/"
    "src/Game/Components/Entity/Shoot/"
    "src/Game/Components/Entity/Star/"
    "src/Game/Components/StarRating/"
    "src/Game/Components/StarsBackground/"
    "src/Game/Components/WaveIndicators/"
    "src/Game/Scene/"
    "src/Game/Scene/Base/"
    "src/Game/Scene/SceneManager/"
    "src/Game/Scene/Scenes/"
    "src/Game/Scene/Scenes/Game/"
    "src/Game/Scene/Scenes/Menu/"
    "src/Helpers/"
    "src/Helpers/Mutex/"
    "src/Helpers/Path/"
    "src/Helpers/Thread/"
    "src/Helpers/Utils/"
    "src/Parsing/"
    "src/Ressources/"
)

#  ---- LINK LIBRARIES ---- #
target_link_libraries(r-type_client PRIVATE
    ${RTYPE_LIBRARIES}
    sfml-graphics sfml-window sfml-system sfml-audio sfml-network
    Boost::system
)

#  ---- POST BUILD ---- #
add_custom_command(TARGET r-type_client POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:r-type_client> ${CMAKE_SOURCE_DIR}
)
