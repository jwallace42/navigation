project(grid_maps)
cmake_minimum_required(VERSION 3.5)
add_compile_options(-g)

include_directories(include)

find_package(Eigen3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Specify the include directories
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${EIGEN3_INCLUED_DIR})

add_executable(viz_grid_map src/glut.cpp)

target_link_libraries(viz_grid_map ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

