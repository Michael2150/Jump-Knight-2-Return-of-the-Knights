cmake_minimum_required(VERSION 3.26)
project(CA3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(CA3 src/main.cpp
        src/components/Component.cpp
        src/components/Component.h
        src/entities/Entity.cpp
        src/entities/Entity.h
        src/engine/GameEngine.cpp
        src/engine/GameEngine.h
)

target_link_libraries(CA3 PRIVATE sfml-graphics sfml-audio sfml-window sfml-system)
target_compile_features(CA3 PRIVATE cxx_std_17)

#if (WIN32 AND BUILD_SHARED_LIBS)
#    add_custom_command(TARGET CA3 POST_BUILD
#            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:CA3> $<TARGET_FILE_DIR:CA3> COMMAND_EXPAND_LISTS)
#endif()

install(TARGETS CA3)