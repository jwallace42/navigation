project(search_algorithms)
cmake_minimum_required(VERSION 3.5)
add_compile_options(-g)

include_directories(include)

# Need access to the grid map
find_package(grid_map REQUIRED)

