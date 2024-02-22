cmake_minimum_required(VERSION 3.0)
project(MyGLUTProject)

# Find the OpenGL package
find_package(OpenGL REQUIRED)

# Find the GLUT package
find_package(GLUT REQUIRED)

# Specify the include directories
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

# Define the source files for your project
add_executable(MyExecutable glut.cpp)

# Link the executable with OpenGL and GLUT libraries
target_link_libraries(MyExecutable ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
