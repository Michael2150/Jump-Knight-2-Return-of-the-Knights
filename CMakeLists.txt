cmake_minimum_required(VERSION 3.26)
project(CA3)

set(CMAKE_CXX_STANDARD 17)


add_executable(CA3 src/main.cpp
        src/components/Component.cpp
        src/components/Component.h
        src/entities/Entity.cpp
        src/entities/Entity.h
        src/engine/GameEngine.cpp
        src/engine/GameEngine.h
)
