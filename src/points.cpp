#include "main.h"

void drawElongatedSquareDipyramid(GLfloat a)
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

void drawHexagonalDipyramid(GLfloat a)
{
    GLfloat vertices[] = {
        // base
        -a/2, 0, a,
        a/2, 0, a,
        a, 0, 0,
        a/2, 0, -a,
        -a/2, 0, -a,
        -a, 0, 0,
    };

    std::vector<GLdouble> triangles;
    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
                triangles.push_back(vertices[3 * i + j]);
            for (int j = 0; j < 3; j++)
                triangles.push_back(vertices[3 * ((i + 1) % 6) + j]);
            triangles.push_back(0);
            if (k == 0)
                triangles.push_back(sqrt(3) * a/2);
            else
                triangles.push_back(-sqrt(3) * a/2);
            triangles.push_back(0);
        }
    }

    GLdouble vertexArray[(int)(triangles.size())];
    for (int i = 0; i < triangles.size(); i++)
        vertexArray[i] = triangles[i];

    GLdouble colors[] ={
        0.8, 0, 0,
        0, 0.8, 0,
        0, 0, 0.8,    
    };

    GLdouble colorArray[(int)(triangles.size())];
    for (int i = 0; i < triangles.size()/18; i++)
    {
        if (i % 3 == 0)
            for (int j = 0; j < 3; j++)
                colorArray[9*i+j*3] = colors[0],
                colorArray[9*i+j*3+1] = colors[1],
                colorArray[9*i+j*3+2] = colors[2];
        else if (i % 3 == 1)
            for (int j = 0; j < 3; j++)
                colorArray[9*i+j*3] = colors[3],
                colorArray[9*i+j*3+1] = colors[4],
                colorArray[9*i+j*3+2] = colors[5];
        else
            for (int j = 0; j < 3; j++)
                colorArray[9*i+j*3] = colors[6],
                colorArray[9*i+j*3+1] = colors[7],
                colorArray[9*i+j*3+2] = colors[8];
    }

    for (int i = triangles.size()/18; i < triangles.size()/9; i++)
    {
        if (i % 3 == 2)
            for (int j = 0; j < 3; j++)
                colorArray[9*i+j*3] = colors[0],
                colorArray[9*i+j*3+1] = colors[1],
                colorArray[9*i+j*3+2] = colors[2];
        else if (i % 3 == 0)
            for (int j = 0; j < 3; j++)
                colorArray[9*i+j*3] = colors[3],
                colorArray[9*i+j*3+1] = colors[4],
                colorArray[9*i+j*3+2] = colors[5];
        else
            for (int j = 0; j < 3; j++)
                colorArray[9*i+j*3] = colors[6],
                colorArray[9*i+j*3+1] = colors[7],
                colorArray[9*i+j*3+2] = colors[8];
    }

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_DOUBLE, 0, vertexArray);
    glColorPointer(3, GL_DOUBLE, 0, colorArray);
    glDrawArrays(GL_TRIANGLES, 0, (int)(triangles.size()/3));
    
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void regularDodecahedron(GLfloat a)
{
    int n = 11;
    std::vector<GLdouble> vertices, triangles;

    for (int i = 0; i < n; i++) 
    {
        vertices.push_back(a * cos(2 * M_PI * i / n));
        vertices.push_back(0);
        vertices.push_back(a * sin(2 * M_PI * i / n));
    }

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
                triangles.push_back(vertices[3 * i + j]);
            for (int j = 0; j < 3; j++)
                triangles.push_back(vertices[3 * ((i + 1) % n) + j]);
            triangles.push_back(0);
            if (k == 0)
                triangles.push_back(0);
            else
                triangles.push_back(sqrt(3) * a/2);
            triangles.push_back(0);
        }
    }

    GLdouble vertexArray[(int)(triangles.size())];
    for (int i = 0; i < triangles.size(); i++)
        vertexArray[i] = triangles[i];

    GLdouble shade = 0.26;
    GLdouble colorArray[(int)(triangles.size())];
    for (int i = 0; i < triangles.size()/3; i++)
    {
        colorArray[3 * i] = shade;
        colorArray[3*i + 1] = shade;
        colorArray[3*i + 2] = shade;
        if (i % 3 == 2 && i > triangles.size()/6)
            shade += 0.03;
    }

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_DOUBLE, 0, vertexArray);
    glColorPointer(3, GL_DOUBLE, 0, colorArray);
    glDrawArrays(GL_TRIANGLES, 0, (int)(triangles.size()/3));
    
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}
