
# 3D transformations- Scaling, translation and Rotations

The code begins by including the necessary header files, defining constants and variables, and initializing the cube's vertices, faces, and colors. It also includes functions for matrix operations, cube transformations, initialization, drawing the cube, display handling, resizing the window, keyboard input, and mouse interaction.

To compile and run this code, you need to have the GLUT library installed and configured properly. You can compile the code with the following command:
g++ main.cpp -o output -lGL -lGLU -lglut

Make sure to have the necessary development libraries installed on your system.

Once compiled successfully, you can run the program by executing the generated executable.

The program will open a window showing the 3D cube. You can use the following keyboard commands to perform transformations:

Rotation:
'x': Rotate the cube along the X-axis in the counter-clockwise direction.
'X': Rotate the cube along the X-axis in the clockwise direction.
'y': Rotate the cube along the Y-axis in the counter-clockwise direction.
'Y': Rotate the cube along the Y-axis in the clockwise direction.
'z': Rotate the cube along the Z-axis in the counter-clockwise direction.
'Z': Rotate the cube along the Z-axis in the clockwise direction.

Scaling:
'1': Scale the cube along the X-axis by a factor of 1.2.
'2': Scale the cube along the Y-axis by a factor of 1.2.
'3': Scale the cube along the Z-axis by a factor of 1.2.
'4': Scale the cube along the X-axis by a factor of 0.12.
'5': Scale the cube along the Y-axis by a factor of 0.12.
'6': Scale the cube along the Z-axis by a factor of 0.12.

Translation:
'q' or 'Q': Translate the cube along the X-axis in the positive direction.
'w' or 'W': Translate the cube along the Y-axis in the positive direction.
'e' or 'E': Translate the cube along the Z-axis in the positive direction.
'a' or 'A': Translate the cube along the X-axis in the negative direction.
's' or 'S': Translate the cube along the Y-axis in the negative direction.
'd' or 'D': Translate the cube along the Z-axis in the negative direction.
