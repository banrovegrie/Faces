#include "main.h"

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;
GLfloat rotationZ = 0.0f;

GLfloat moveX = 0.0f;
GLfloat moveY = 0.0f;
GLfloat moveZ = 0.0f;

GLfloat ZOOM = 1;
GLfloat Z_SPEED = 0.03;

int spinZ = 0;
int spinY = 0;

/* Draw Stuff */
void draw(int c)
{
    switch(c)
    {
        case 1:
            drawElongatedSquareDipyramid(300);
            break;
        case 2:
            drawHexagonalDipyramid(300);
            break;
        case 3:
        regularDodecahedron(300);
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
            /* For Spins */
            case GLFW_KEY_Z:
                rotationX = rotationY = rotationZ = 0;
                spinZ ^= 1;
                break;
            case GLFW_KEY_X:
                rotationX = rotationY = rotationZ = 0;
                spinY ^= 1;
                break;

            /* For Rotations */
            case GLFW_KEY_W:
                rotationX -= ROTATION_SPEED;
                break;
            case GLFW_KEY_S:
                rotationX += ROTATION_SPEED;
                break;
            case GLFW_KEY_D:
                rotationY += ROTATION_SPEED;
                break;
            case GLFW_KEY_A:
                rotationY -= ROTATION_SPEED;
                break;
            case GLFW_KEY_E:
                rotationZ += ROTATION_SPEED;
                break;
            case GLFW_KEY_Q:
                rotationZ -= ROTATION_SPEED;
                break;
            
            /* For Movement */
            case GLFW_KEY_I:
                moveY += MOVE_SPEED;
                break;
            case GLFW_KEY_K:
                moveY -= MOVE_SPEED;
                break;
            case GLFW_KEY_L:
                moveX += MOVE_SPEED;
                break;
            case GLFW_KEY_J:
                moveX -= MOVE_SPEED;
                break;
            case GLFW_KEY_O:
                moveZ += MOVE_SPEED;
                ZOOM += Z_SPEED;
                break;
            case GLFW_KEY_U:
                moveZ -= MOVE_SPEED;
                ZOOM -= Z_SPEED;
                break;

            /* Transportation */
            case GLFW_KEY_C:
                rotationX = rotationY = rotationZ = 0;
                break;
            case GLFW_KEY_V:
                moveX = moveY = moveZ = 0;
                break;
            case GLFW_KEY_B:
                rotationX = rotationY = rotationZ = 0;
                moveX = moveY = moveZ = 0;
                ZOOM = 1;
                break;

            /* For Escape */
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
            if (spinZ)
                rotationZ += ROTATION_SPEED,
                glRotatef(rotationZ, 0, 0, 1);
            else if (spinY) 
                rotationY += ROTATION_SPEED,
                glRotatef(rotationY, 0, 1, 0);
            else
            {
                glTranslatef(moveX, 0, 0);
                glTranslatef(0, moveY, 0);
                /* glTranslatef(0, 0, moveZ); */
                glScalef( 1, 1, ZOOM);
                glRotatef(rotationX, 1, 0, 0);
                glRotatef(rotationY, 0, 1, 0);
                glRotatef(rotationZ, 0, 0, 1);
            }

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
