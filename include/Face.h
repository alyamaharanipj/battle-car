#ifndef FACE_H
#define FACE_H


    class Face {
      public:
        int edge;
        int *vertices;
        int *texcoords;
        int normal;

        Face(int edge, int *vertices, int *texcoords, int normal = -1);
    };

#endif // FACE_H
