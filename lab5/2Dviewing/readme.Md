# CLIPPING ALGORITHMS

## COHEN-SUTHERLAND-LINE-CLIPPING_ALGORITHM

The code begins by including the necessary header files, setting up global variables for defining the clipping window coordinates (xMin, xMax, yMin, yMax), and the coordinates of the line segment (xc1, yc1, xc2, yc2).

Next, four constants (Left, Right, Bot, Top) are defined, representing the four sides of the clipping window. Two variables (C1 and C2) are initialized to store the computed outcodes for the endpoints of the line segment. Clip_Flag and Flag are flags used for controlling the clipping process and drawing the line segment.

The Get_Code function calculates and returns the outcode of a given point based on its position with respect to the clipping window. The function checks if the point is to the left, right, bottom, or top of the window and sets the corresponding bits in the outcode.

The Clip function performs the actual clipping of the line segment. It checks the outcode of the point to determine which side of the window the line intersects. Based on the intersection point formula, it calculates the coordinates of the intersection point and updates the appropriate endpoint of the line segment (xc1, yc1 or xc2, yc2).

The Draw function is responsible for rendering the scene. It first clears the buffer and draws the clipping window as a white quadrilateral. Then, if Flag is set to 1, it draws the line segment between the endpoints (xc1, yc1) and (xc2, yc2) as a magenta line.

Inside the while loop in the Draw function, the code performs the iterative clipping process until the line segment is completely inside the window (C1 and C2 both equal 0), or if the line segment is completely outside or parallel to one of the clipping window edges (C1 & C2 != 0). If the line segment needs clipping, the Clip function is called to update the endpoints accordingly.

The Keyboard function is called when a key is pressed, and in this case, it sets Clip_Flag to 1, indicating that clipping should be performed. It then triggers a redisplay.

Finally, in the main function, the code initializes GLUT and creates a window. It sets the display mode, window size, and position. It registers the Draw and Keyboard functions as the display and keyboard callbacks, respectively. The program enters the main loop and waits for events.

To conclude, this code sets up a simple graphical environment using OpenGL and GLUT and demonstrates the application of the Cohen-Sutherland line clipping algorithm. When a key is pressed, it triggers the clipping process and updates the display accordingly.

## SUTHERLAND-HODGEMAN-POLYGON-CLIPPING-ALGORITHM

The code begins by including the necessary header files and defining a Point structure to represent the vertices of the polygon. It also declares global variables, including the array w to store the clipping window vertices and the array oVer to store the output vertices after clipping. Nout is used to keep track of the number of vertices in oVer.

The drawPoly function is responsible for rendering a polygon given an array of points. It uses the glBegin and glEnd functions to draw a filled polygon by iterating through the points and calling glVertex2f for each vertex.

The insideVer function checks if a given point is inside the clipping window. It compares the x and y coordinates of the point with the coordinates of the minimum and maximum vertices of the window.

The addVer function adds a vertex to the oVer array and increments Nout by 1.

The getInterSect function calculates the intersection point between an edge of the clipping window and a line segment defined by two points. It handles both vertical and non-vertical edges by calculating the slope (m) and using it to determine the intersection point.

The clipAndDraw function performs the Sutherland-Hodgman clipping algorithm. It takes an array of input vertices (inVer) and the number of vertices (Nin). It iterates through the edges of the clipping window and performs the clipping operation on the input vertices. It checks if each line segment intersects the clipping window edges and adds the intersection points and valid vertices to the oVer array. The inVer array is then updated with the clipped vertices, and the process repeats for each edge of the clipping window.

The init function sets up the initial OpenGL parameters, including the background color and the orthographic projection for a 2D view.

The display function is the main rendering function. It initializes the scene, draws the clipping window in white, and draws the input polygon in yellow. It then calls the clipAndDraw function to perform the polygon clipping and render the clipped polygon in red.

Finally, in the main function, the code initializes GLUT, creates a window, and sets the display mode, size, and position. It registers the display function as the display callback and enters the main event loop.

To conclude, this code sets up a simple graphical environment using OpenGL and GLUT and demonstrates the application of the Sutherland-Hodgman polygon clipping algorithm. It performs clipping of a polygon against a rectangular clipping window and renders the clipped polygon in a different color.
