#include "Material.h"

        Material::Material(float *ambient, float *diffuse, float *specular) {
            this->ambient = ambient;
            this->diffuse = diffuse;
            this->specular = specular;
            this->texture = 0;
        }
