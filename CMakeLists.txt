cmake_minimum_required(VERSION 3.26)
project(CA3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

#### Add External Dependencies ####
# SFML - graphics library
add_subdirectory("lib/sfml" EXCLUDE_FROM_ALL)
include_directories("lib/sfml/include")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

# B2D - Box2D phyics library
add_subdirectory("lib/b2d/Box2D")
include_directories("lib/b2d/Box2D/")
set(B2D_INCS "lib/b2d/Box2D/")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

add_executable(CA3 src/main.cpp
        src/components/Component.cpp
        src/components/Component.h
        src/entities/Entity.cpp
        src/entities/Entity.h
        src/engine/GameEngine.cpp
        src/engine/GameEngine.h
)

target_link_libraries(CA3 PRIVATE sfml-graphics sfml-audio sfml-window sfml-system Box2D)
target_compile_features(CA3 PRIVATE cxx_std_17)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET CA3 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:CA3> $<TARGET_FILE_DIR:CA3> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS CA3)