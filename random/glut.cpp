#include <GL/glut.h>
#include <iostream>


// This function is called to display the objects.
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Set the current drawing color to red
    glColor3f(1.0, 0.0, 0.0);

    // Begin drawing mode for lines
    // glBegin(GL_LINES);
    //     // Specify the two endpoints of the line
    //     glVertex2f(-0.5, 0.0); // Point 1 (x1, y1)
    //     glVertex2f(0.5, 0.0);  // Point 2 (x2, y2)
    // glEnd();


    for(int x = 1; x < 10.0; x++) {
        glBegin(GL_LINES);
            // Specify the two endpoints of the line
            glVertex2f(x, 0.0); // Point 1 (x1, y1)
            glVertex2f(x, 10.0);  // Point 2 (x2, y2)
        glEnd();
    }

    for(int y = 1; y < 10.0; y++) {
        glBegin(GL_LINES);
            // Specify the two endpoints of the line
            glVertex2f(0.0, y); // Point 1 (x1, y1)
            glVertex2f(10.0, y);  // Point 2 (x2, y2)
        glEnd();
    }

    glFlush(); // Ensure that the drawing commands are executed
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode

    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowSize(screenWidth, screenHeight); // Set the window size
    glutInitWindowPosition(0, 0); // Set the window position
    glutCreateWindow("Draw Line Example"); // Create the window with a title

    // Set the clear color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set up the viewing volume: Default to identity matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set the clipping volume
    // left, right, bottom, top
    gluOrtho2D(0.0, 10.0, 0.0, 10.0);

    glutDisplayFunc(display); // Register the display callback function

    glutMainLoop(); // Enter the GLUT main loop

    return 0;
}

// Handle ASCII key presses
// void handleKeypress(unsigned char key, int x, int y) {
//     switch(key) {
//         case 'q': // Quit program
//             std::cout << "Exiting program." << std::endl;
//             exit(0);
//             break;
//         // Handle other ASCII keys here
//     }
// }
//
// // Handle special key presses
// void handleSpecialKeypress(int key, int x, int y) {
//     switch(key) {
//         case GLUT_KEY_UP:
//             std::cout << "Up arrow pressed." << std::endl;
//             break;
//         // Handle other special keys here
//     }
// }
//
// void handleMouse(int button, int state, int x, int y) {
//     if (state == GLUT_DOWN) {
//         std::cout << "Mouse button pressed at (" << x << ", " << y << ")" << std::endl;
//         // Handle mouse press
//     } else {
//         // Handle mouse release
//     }
// }
//
// void display() {
//     glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
//
//     // Set the current drawing color to red
//     glColor3f(1.0, 0.0, 0.0);
//
//     // Begin drawing mode for lines
//     glBegin(GL_LINES);
//         // Specify the two endpoints of the line
//         glVertex2f(-0.5, 0.0); // Point 1 (x1, y1)
//         glVertex2f(0.5, 0.0);  // Point 2 (x2, y2)
//     glEnd();
//
//     glFlush(); // Ensure that the drawing commands are executed
// }

// Display callback function
// void display() {
//     // Clear the color buffer
//     glClear(GL_COLOR_BUFFER_BIT);
//     
//     // Set the current drawing color to white
//     glColor3f(1.0, 0.0, 1.0);
//     
//     // Start drawing a rectangle
//     // glBegin(GL_POLYGON);
//     //     glVertex2f(0.25, 0.25);
//     //     glVertex2f(0.75, 0.25);
//     //     glVertex2f(0.75, 0.75);
//     //     glVertex2f(0.25, 0.75);
//     // glEnd();
//     //
//     glColor3f(1.0, 1.0, 1.0);
//     glLineWidth(2.5);
//     glBegin(GL_LINES);
//         glVertex2f(200, 0);
//         glVertex2f(200, 200);
//     glEnd();
//     
//     // Flush drawing commands
//     glFlush();
// }

// Main function
// int main(int argc, char** argv) {
//     // Initialize GLUT
//     glutInit(&argc, argv);
//
//
//     int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
//     int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
//
//     // Fixed grid 40 by 40
//
//     
//     // Set display mode
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//     // Set the window size
//     glutInitWindowSize(screenWidth, screenHeight);
//
//     // Set the window position
//     glutInitWindowPosition(0, 0);
//
//     // Create the window
//     glutCreateWindow("GLUT Program");
//
//     // Set the clear color to black
//     glClearColor(0.0, 0.0, 0.0, 0.0);
//
//     // Initialize viewing values
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0.0, 1.0, 0.0, 1.0);
//
//     // Register the display callback function
//     glutDisplayFunc(display);
//
//     // Register keyboard callbacks
//     glutKeyboardFunc(handleKeypress);
//     glutSpecialFunc(handleSpecialKeypress);
//
//
//     glutMouseFunc(handleMouse);
//
//     // Enter the GLUT main loop
//     glutMainLoop();
//     
//     return 0;
// }
//
