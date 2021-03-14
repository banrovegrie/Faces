#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include <iostream>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 500
#define ROTATION_SPEED 5

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;

/* Draw Stuff */
void drawCube(GLfloat a)
{   
    GLfloat vertices[] = {
        // front face
        -a/2, +a/2, +a/2, // top left
        +a/2, +a/2, +a/2, // top right
        +a/2, -a/2, +a/2, // bottom right
        -a/2, -a/2, +a/2, // bottom left
        
        // back face
        -a/2, +a/2, -a/2, // top left
        +a/2, +a/2, -a/2, // top right
        +a/2, -a/2, -a/2, // bottom right
        -a/2, -a/2, -a/2, // bottom left
        
        // left face
        -a/2, +a/2, +a/2, // top left
        -a/2, +a/2, -a/2, // top right
        -a/2, -a/2, -a/2, // bottom right
        -a/2, -a/2, +a/2, // bottom left
        
        // right face
        +a/2, +a/2, +a/2, // top left
        +a/2, +a/2, -a/2, // top right
        +a/2, -a/2, -a/2, // bottom right
        +a/2, -a/2, +a/2, // bottom left
    };

    GLdouble triangles[] = {
        // top
        -a/2, +a/2, +a/2, // top left
        -a/2, +a/2, -a/2, // top right
        0.0, (1 + sqrt(2)) * a/2, 0.0,
        -a/2, +a/2, -a/2, // top right
        +a/2, +a/2, -a/2, // bottom right
        0.0, (1 + sqrt(2)) * a/2, 0.0,
        +a/2, +a/2, -a/2, // bottom right
        +a/2, +a/2, +a/2, // bottom left
        0.0, (1 + sqrt(2)) * a/2, 0.0,
        +a/2, +a/2, +a/2, // bottom left
        -a/2, +a/2, +a/2, // top left
        0.0, (1 + sqrt(2)) * a/2, 0.0,

        // down
        -a/2, -a/2, +a/2, // top left
        -a/2, -a/2, -a/2, // top right
        0.0, -(1 + sqrt(2)) * a/2, 0.0,
        -a/2, -a/2, -a/2, // top right
        +a/2, -a/2, -a/2, // bottom right
        0.0, -(1 + sqrt(2)) * a/2, 0.0,
        +a/2, -a/2, -a/2, // bottom right
        +a/2, -a/2, +a/2, // bottom left
        0.0, -(1 + sqrt(2)) * a/2, 0.0,
        +a/2, -a/2, +a/2, // bottom left
        -a/2, -a/2, +a/2, // top left
        0.0, -(1 + sqrt(2)) * a/2, 0.0
    };

    GLfloat colors1[] = {
        // front face
        20, 20, 0,
        20, 20, 0,
        20, 20, 0,
        20, 20, 0,
        
        // back face
        0, 20, 20,
        0, 20, 20,
        0, 20, 20,
        0, 20, 20,        
        
        // left face
        20, 0, 20,
        20, 0, 20,
        20, 0, 20,
        20, 0, 20,  
        
        // right face
        0.80, 0.5, 0,
        0.80, 0.5, 0,
        0.80, 0.5, 0,
        0.80, 0.5, 0, 
    };

    GLdouble colors2[] = {
        // top
        0.7, 0, 0,
        0.7, 0, 0,
        0.7, 0, 0,
        0, 0.7, 0,
        0, 0.7, 0,
        0, 0.7, 0,
        0, 0, 0.7,
        0, 0, 0.7,
        0, 0, 0.7,
        0.2, 0.4, 0.4,
        0.2, 0.4, 0.4,
        0.2, 0.4, 0.4,

        // down
        0.7, 0, 0,
        0.7, 0, 0,
        0.7, 0, 0,
        0, 0.7, 0,
        0, 0.7, 0,
        0, 0.7, 0,
        0, 0, 0.7,
        0, 0, 0.7,
        0, 0, 0.7,
        0.2, 0.4, 0.4,
        0.2, 0.4, 0.4,
        0.2, 0.4, 0.4,
    };
    
    /* Cube Part */
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors1);
    glDrawArrays(GL_QUADS, 0, 16);
    
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);


    /* Pyramids */
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_DOUBLE, 0, triangles);
    glColorPointer(3, GL_DOUBLE, 0, colors2);
    glDrawArrays(GL_TRIANGLES, 0, 24);
    
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

/* Process Input */
void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods )
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
            drawCube(300);
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
