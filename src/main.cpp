#include "main.h"

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;

/* Draw Stuff */
void draw(int c)
{
    switch(c)
    {
        case 1:
            drawElong(300);
            break;
        case 2:
            break;
        case 3:
            break;
    }
}

/* Process Input */
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    // GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
            case GLFW_KEY_UP:
                rotationX -= ROTATION_SPEED;
                break;
            case GLFW_KEY_DOWN:
                rotationX += ROTATION_SPEED;
                break;
            case GLFW_KEY_RIGHT:
                rotationY += ROTATION_SPEED;
                break;
            case GLFW_KEY_LEFT:
                rotationY -= ROTATION_SPEED;
                break;
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, true);
                break;
        }       
    }
}

int main()
{
    int choice;
    std::cout << "Press 1-3 to see which dodecahedron you deserve" << std::endl;
    std::cin >> choice;
    
    if (choice > 3 || choice < 1)
    {
        std::cout << "Error in input" << std::endl;
        return -1;
    }

    /* OpenGL Initialisation */
    glfwInit();

    /* Create GLFW Window */
    GLFWwindow* window = glfwCreateWindow(
        SCREEN_WIDTH, SCREEN_HEIGHT, "Faces", NULL, NULL
    );

    /* Input */
    glfwSetKeyCallback(window, keyCallback);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
    
    /* Make Context */
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    if (window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    /* Make sure resizing window works */
    glViewport( 0.0f, 0.0f, screenWidth, screenHeight);
    GLfloat halfScreenWidth = screenWidth / 2;
    GLfloat halfScreenHeight = screenHeight / 2;

    /* Camera Movements */
    /* 
        Specifies the part of the window to which OpenGL will draw 
        (in pixels), convert from normalised to pixels
    */
    glMatrixMode(GL_PROJECTION);
    /* 
        Replace the current matrix with the identity matrix 
        and starts us a fresh because matrix transforms 
        such as glOrpho and glRotate cumulate
        basically puts us at (0, 0, 0)
    */
    glLoadIdentity();
    /* Essentially set the coordinate system */
    glOrtho(-screenWidth, screenWidth, -screenHeight, screenHeight, -1000, 1000);
    /*
        Default matrix mode: modelview matrix 
        defines how your objects are transformed 
        (meaning translation, rotation and scaling) 
        in your world
    */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);


    /* Render here */
    while(!glfwWindowShouldClose(window))
    {
        // background color
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // movements
        glPushMatrix();
        {
            glTranslatef(0, 0, 0);
            glRotatef(rotationX, 1, 0, 0);
            glRotatef(rotationY, 0, 1, 0);
            glTranslatef(0, 0, 0);

            // draw
            draw(choice);
        }
        glPopMatrix();

        // call events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    /* GLFW Termination */
    glfwTerminate();
    return 0;
}
