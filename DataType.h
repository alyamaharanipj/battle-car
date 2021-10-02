#ifndef DATATYPE_H_INCLUDED
#define DATATYPE_H_INCLUDED

#include <GL/glut.h>
struct point{
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

struct tile{
    GLfloat vertical;
    GLfloat horizontal;
};

struct color{
    GLfloat cr;
    GLfloat cb;
    GLfloat cg;
};

#endif // DATATYPE_H_INCLUDED
