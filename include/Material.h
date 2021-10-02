#ifndef MATERIAL_H
#define MATERIAL_H

#include <GL/glut.h>

    class Material {
      public:
        float *ambient;
        float *diffuse;
        float *specular;
        GLuint texture;

        Material(float *ambient, float *diffuse, float *specular);
    };

#endif // MATERIAL_H
