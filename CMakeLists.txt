cmake_minimum_required(VERSION 3.26)
project(CA3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

#### Add External Dependencies ####
# SFML - graphics library
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# B2D - Box2D phyics library
add_subdirectory("lib/b2d/Box2D")
include_directories("lib/b2d/Box2D/")
set(B2D_INCS "lib/b2d/Box2D/")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

# Add the source files to the executable recursively
file(GLOB SOURCES "src/*.cpp" "src/**/*.cpp")
add_executable(CA3 ${SOURCES}
        src/entities/Entity_Ball.h
        src/level_system/LevelMap.cpp
        src/level_system/LevelMap.h
        src/level_system/Tileset.cpp
        src/level_system/Tileset.h
        src/entities/PlayerController.h
)

# add a JSON library
FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)

# Delete the resources folder in the build directory
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/resources)

# Copy the resources folder to the build directory
file(COPY "resources" DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(CA3 PRIVATE sfml-graphics sfml-audio sfml-window sfml-system Box2D nlohmann_json::nlohmann_json)
target_compile_features(CA3 PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET CA3 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:CA3> $<TARGET_FILE_DIR:CA3> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS CA3)