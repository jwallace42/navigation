project(grid_maps)
cmake_minimum_required(VERSION 3.5)
add_compile_options(-g)

include_directories(include)

find_package(Eigen3 REQUIRED)

add_executable(grid_map src/main.cpp
                        src/grid_map.cpp
)

include_directories(${EIGEN3_INCLUDE_DIR})

