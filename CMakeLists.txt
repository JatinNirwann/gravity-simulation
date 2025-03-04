cmake_minimum_required(VERSION 3.10)
project(GravitySimulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(main gravity_sim.cpp)

target_link_libraries(main PRIVATE GLEW::GLEW glfw glm::glm)
