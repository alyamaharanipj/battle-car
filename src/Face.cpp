#include "Face.h"

Face::Face(int edge, int *vertices, int *texcoords, int normal){
            this->edge = edge;
            this->vertices = vertices;
            this->texcoords = texcoords;
            this->normal = normal;
        }
