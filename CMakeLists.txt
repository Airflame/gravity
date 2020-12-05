cmake_minimum_required(VERSION 3.13)
project(gravity)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_executable(gravity main.cpp src/Star.cpp include/Star.h src/Particle.cpp include/Particle.h)
target_link_libraries(gravity sfml-graphics sfml-window sfml-system)