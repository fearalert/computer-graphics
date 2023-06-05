# Rubik's Cube 3D Visualization

## Code Functionalities

- ChangeSize(int w, int h):
This function is a callback function that is invoked by GLUT whenever the window size is changed. It sets the viewport dimensions to match the new window size.

- renderBitmapString(float x, float y, void*font, const char* string):
This function is defined elsewhere in the code. It is used to render text strings on the screen using GLUT's bitmap fonts.

- setcol(int cc):
This function is responsible for setting the color of a cube face based on the given color index cc. It uses a switch statement to select the appropriate color for each case:
    Case 0: Sets the color to white with RGB values (1.0, 1.0, 1.0).
    Case 1: Sets the color to blue with RGB values (0.0, 0.0, 1.0).
    Case 2: Sets the color to yellow with RGB values (1.0, 1.0, 0.0).
    Case 3: Sets the color to green with RGB values (0.0, 1.0, 0.0).
    Case 4: Sets the color to red with RGB values (1.0, 0.0, 0.0).
    Case 5: Sets the color to orange with RGB values (1.0, 0.5, 0.0).
    Case 6: Sets the color to dark red with RGB values (0.1, 0.0, 0.0).
    If cc does not match any of the defined cases, no action is taken.

- mycube(int pic, float siz, float x, float y, float z, int d, int f, int u, int b, int r, int l):
This function draws a single cube with the specified parameters.
    pic: The index of the cube.
    siz: The size of the cube.
    x, y, z: The coordinates of the cube's center.
    d, f, u, b, r, l: The colors of each face of the cube (represented by their respective indices).
    The function first applies rotations to the cube based on the stored rotation values in yro, xro, and zro arrays. These arrays store the rotation values for each cube in the Rubik's Cube. Then, the function uses glTranslatef to translate the cube to the specified coordinates.The cube is drawn using glBegin(GL_POLYGON) and glEnd() to define and draw each face of the cube separately. The setcol function is called to set the appropriate color for each face based on the provided color indices.

- rubic(float siz, float x):
This function is responsible for drawing the Rubik's Cube by calling the mycube function for each individual cube in the Rubik's Cube. The function uses a series of calls to mycube, providing the necessary parameters for each cube based on its position in the Rubik's Cube. Each cube is identified by a unique index (1 to 27), and the color indices for each face are retrieved from the C array. The size parameter represents the size of the individual cubes, and the x parameter represents the offset between the cubes. By calling mycube with the appropriate parameters, the function draws each cube of the Rubik's Cube, creating the overall 3D structure.

- xrotation:
This function performs an x-axis rotation on the cube. It takes two parameters: lay (which can be 1, 2, or 3) representing the layer to rotate, and dir (-1 or 1) representing the direction of rotation. The function swaps the elements in the specified layer according to the rotation direction.

- yrotation:
This function performs a y-axis rotation on the cube. It takes two parameters: lay (which can be 1, 2, or 3) representing the layer to rotate, and dir (-1 or 1) representing the direction of rotation. The function calls the rmy function to perform the actual rotation based on the layer and direction.

- rmy:
This function is a helper function for yrotation. It performs a y-axis rotation on a specific face of the cube. It takes four parameters: fr, le, ba, and ri, which represent the positions of elements on the front, left, back, and right faces respectively. The function swaps the elements on these positions according to the rotation direction.

- zrotation:
This function performs a z-axis rotation on the cube. It takes two parameters: lay (which can be 1, 2, or 3) representing the layer to rotate, and dir (-1 or 1) representing the direction of rotation. The function calls the rmz function to perform the actual rotation based on the layer and direction.

- rmz:
This function is a helper function for zrotation. It performs a z-axis rotation on a specific face of the cube. It takes four parameters: up, ri, dw, and le, which represent the positions of elements on the up, right, down, and left faces respectively. The function swaps the elements on these positions according to the rotation direction.

- fr: This function performs a clockwise rotation on a specific face of the cube. It takes one parameter face (which can be 0 to 5) representing the face to rotate. The function swaps the elements on the face in a clockwise direction.

- franti: This function performs a counterclockwise rotation on a specific face of the cube. It takes one parameter face (which can be 0 to 5) representing the face to rotate. The function swaps the elements on the face in a counterclockwise direction.

- draw:
The draw function appears to be a part of a graphical program, possibly related to a Rubik's Cube simulation or game. Here is a breakdown of the function:
The function initializes some variables and clears the color buffer and depth buffer using glClear function. It applies rotation transformations to the scene based on the values of rotate_x and rotate_y variables using glRotatef function. These variables seem to control the rotation of the view.
If the rot variable is true, it means a rotation is in progress. In that case, the ang variable is incremented by insp value. If ang becomes greater than 90, it means the rotation is completed, and various variables related to the rotation are reset. Then, based on the value of rot, specific rotation functions (yrotation, xrotation, or zrotation) are called to perform the rotation on the Rubik's Cube. Additionally, some specific rotations are performed when rot has certain values (9, 11, 14, 16). Finally, the rot variable is set to 0, indicating that the rotation is finished.
The rubic function is called with the siz and x variables as arguments to render the Rubik's Cube.
Some text is rendered on the screen using the renderBitmapString function. The text includes "RESET", "SCRAMBLE", and "Project By: Rohan Dhakal". A loop checks if the Rubik's Cube is solved by comparing the center elements of each face (C[i][5]) with the other elements of the same face. If any element is different, the flag variable is set to 1. If flag is still 0, it means the Rubik's Cube is solved, and "SOLVED" is displayed on the screen using renderBitmapString. Finally, the buffers are swapped using glutSwapBuffers to display the updated scene.
Overall, the draw function is responsible for rendering the Rubik's Cube, handling rotations, displaying text, and checking if the cube is solved in a graphical program.

- scramble : The purpose of the scramble function is to provide a way to generate random starting configurations for the Rubik's Cube, creating a challenging puzzle for the player to solve.

- keyb function:
This function is called when a regular key on the keyboard is pressed.
It takes the ASCII value of the key, as well as the mouse coordinates (x and y) as parameters.
The variable pressed is set to 1.
If the variable yes is true (non-zero), the function performs a specific action based on the key pressed.
The switch statement matches the ASCII value of the key with various cases and calls corresponding functions (xfinal, yfinal, zfinal, wholr) with specific parameters.
The variable yes is set to 0 to prevent further actions until it is enabled again.

- specialKeys function:
This function is called when a special key (such as arrow keys) is pressed.
It takes the key code, as well as the mouse coordinates (x and y) as parameters.
If the variable yes is true (non-zero), the function performs a specific action based on the key pressed.
The if-else if statements match the key code with various cases (e.g., GLUT_KEY_RIGHT, GLUT_KEY_LEFT) and call the function wholr with specific parameters to rotate the Rubik's Cube.

- mouse_click function:
This function is called when a mouse button is clicked.
It takes the button code, state (pressed or released), and mouse coordinates (x and y) as parameters.
If the left button is clicked and released, the function checks the mouse coordinates to determine if the click was within specific regions on the screen.
If the click falls within a specific region, certain actions are performed. For example:
If the click falls within the region defined by (x > 92 && x < 217 && y > 33 && y < 53), the Rubik's Cube is scrambled by calling the scramble function with the parameter x.
If the click falls within the region defined by (x > 519 && x < 596 && y > 33 && y < 53), the Rubik's Cube is reset to its initial state by resetting various variables and arrays.
If the left button is pressed down, the dragging variable is set to 1 to indicate that the user is dragging the mouse.

- void keyb(unsigned char key, int x, int y):
This function is responsible for handling regular keyboard inputs. It checks for specific keys and calls corresponding functions based on the key pressed. It is helper function of keyb function.

- void specialKeys(int key, int x, int y): This function handles special keys such as arrow keys. It checks for specific keys and calls the wholr function to perform a rotation on the entire cube. It is helper function of special keys function.

- void mouse_click(int button, int state, int x, int y):
This function handles mouse clicks. It checks for specific areas clicked and performs actions accordingly, such as scrambling the cube or resetting it. It is helper function of mouseclick function.

- void wholr(int ax, int dir):
This function is called to perform a rotation on the entire cube. It sets flags and variables to indicate the rotation direction and axis.

- void anim(int t): This function is used for animation. It updates the display and sets a timer for the next animation frame.

- void yfinal(int com), void xfinal(int com), void zfinal(int com):
These functions are called to perform specific layer rotations on the cube. They set flags and variables to indicate the rotation direction and layer.

- int main(int argc, char** argv):
This is the main function of the program. It initializes the cube's state, sets up the OpenGL window, and registers callback functions for handling user inputs. It also contains a message for the moves and frequently used rotations.
