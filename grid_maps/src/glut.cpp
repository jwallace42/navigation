#include <GL/glut.h>
#include <cmath>
#include "grid_map.hpp"
#include <iostream>

// Global vars grid map
int rows = 20;
int cols = 25;
float res = 1;

// left, right, bottom, top
float left = 0.0;
float right = cols;
float top = 0.0;
float bottom = rows;
float buffer = 0.1;

// row, col
int start[2] = {0, 0};
int goal[2] = {rows-1, cols-1};


// Mouse coords
int mouse_row, mouse_col;


// Setup the gridmap
grid_map::GridMap<float> grid(rows, cols, res, 1);


// Setup grid search


// This function is called to display the objects.
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Set the current drawing color to white
    glColor3f(1.0, 1.0, 1.0);

    // Render the grid lines
    // Col lines
    float col_step = (right - 2*buffer) / cols; 
    for(float col = buffer; col <= right - buffer; col+=col_step) {
        glBegin(GL_LINES);
            // x, y
            glVertex2f(col, top);
            glVertex2f(col, bottom);
        glEnd();
    }

    // Row Lines
    float row_step = (bottom - 2*buffer) / rows;
    for(float row = buffer; row <= bottom - buffer; row+=row_step) {
        glBegin(GL_LINES);
            // x, y
            glVertex2f(left, row);
            glVertex2f(right, row);
        glEnd();
    }

    // Render the grid
    glPointSize(100.0);
    glColor3f(0.6f, 0.3f, 0.0f); // A brown color
    glBegin(GL_POINTS);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            grid_map::Index index(i, j);
            if (grid.getValue(index) == 100.0f) {
                float row = 0.5 * row_step + buffer + row_step *i;
                float col = 0.5 * col_step + buffer + col_step *j;
                glVertex2f(col, row);
            }
        }
    }
    glEnd();

    // Render Start
    glPointSize(100.0);
    glColor3f(0.0f, 1.0f, 0.0f); // A brown color
    glBegin(GL_POINTS);
    float s_row = 0.5 * row_step + buffer + row_step *start[0];
    float s_col = 0.5 * col_step + buffer + col_step *start[1];
    glVertex2f(s_col, s_row);
    glEnd();

    // Render Goal
    glPointSize(100.0);
    glColor3f(1.0f, 0.0f, 0.0f); // A brown color
    glBegin(GL_POINTS);
    float g_row = 0.5 * row_step + buffer + row_step *goal[0];
    float g_col = 0.5 * col_step + buffer + col_step *goal[1];
    glVertex2f(g_col, g_row);
    glEnd();

    glFlush(); // Ensure that the drawing commands are executed
}

void handleMouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {

        float window_width = glutGet(GLUT_WINDOW_WIDTH);
        float window_height = glutGet(GLUT_WINDOW_HEIGHT);

        float row_conversion = float(right - left) / window_width;
        float x_new = row_conversion * x;

        float col_conversion = float(bottom - top) / window_height;
        float y_new = col_conversion * y;


        // Convert to rows and cols
        if(x_new < buffer || x_new > right - buffer) {
            return;
        }


        if(y_new < buffer || y_new > bottom - buffer) {
            return;
        }

        float step = (right - 2*buffer) / cols; 
        int col = std::floor(x_new - buffer / step);

        step = (bottom - 2*buffer) / rows; 
        int row = std::floor(y_new - buffer / step);

        std::cout << x << " " << y << std::endl;
        std::cout << row << " " << col << std::endl;
        grid_map::Index index(row, col);


        if (grid.getValue(index) <= 10 ) {
            // Clicked to place
            grid.setValue(index, 100.0f);
        } else {
            // Clicked to clear
            grid.setValue(index, 10);
        }
        
        // Update the position
        glutPostRedisplay();


    } else {
        // Handle mouse release
    }
}

void mouseMotion(int x, int y) {
    mouse_col = x;
    mouse_row = y;
}

void keyboard(unsigned char key, int x, int y) {
    // need to handle case where mouse is not in the window
    if (key == 's' || key == 'S') {
        float window_width = glutGet(GLUT_WINDOW_WIDTH);
        float window_height = glutGet(GLUT_WINDOW_HEIGHT);

        float row_conversion = float(right - left) / window_width;
        float new_mouse_col = row_conversion * mouse_col;

        float col_conversion = float(bottom - top) / window_height;
        float new_mouse_row = col_conversion * mouse_row;

        float step = (right - 2*buffer) / cols; 
        int col = std::floor(new_mouse_col - buffer / step);

        step = (bottom - 2*buffer) / rows; 
        int row = std::floor(new_mouse_row - buffer / step);

        start[0] = row;
        start[1] = col;
        glutPostRedisplay();
    }


    if (key == 'g' || key == 'g') {
        float window_width = glutGet(GLUT_WINDOW_WIDTH);
        float window_height = glutGet(GLUT_WINDOW_HEIGHT);

        float row_conversion = float(right - left) / window_width;
        float new_mouse_col = row_conversion * mouse_col;

        float col_conversion = float(bottom - top) / window_height;
        float new_mouse_row = col_conversion * mouse_row;

        float step = (right - 2*buffer) / cols; 
        int col = std::floor(new_mouse_col - buffer / step);

        step = (bottom - 2*buffer) / rows; 
        int row = std::floor(new_mouse_row - buffer / step);

        goal[0] = row;
        goal[1] = col;
        glutPostRedisplay();
    }
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mod

    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowSize(screenWidth, screenHeight); // Set the window size
    glutInitWindowPosition(0, 0); // Set the window position
    glutCreateWindow("Grid Search"); // Create the window with a title

    // Set the clear color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // Set up the viewing volume: Default to identity matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set the clipping volume
    // left, right, bottom, top
    gluOrtho2D(left, right, bottom, top);

    glutMouseFunc(handleMouse);
    glutDisplayFunc(display); // Register the display callback function

    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(mouseMotion); // For mouse movement without button press
    glutMainLoop(); // Enter the GLUT main loop

    return 0;
}
