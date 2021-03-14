#include "main.h"

void drawElong(GLfloat a)
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
