#include "Workshop.h"

Workshop::Workshop()
{
    //ctor
}

//Workshop::draw()
//{
//   //  Save transformation
//   glPushMatrix();
//   //  Offset
//   glTranslated(x,0,z);
//   glRotated(th,0,1,0);
//
//   //Building - Brown Workshop
//   texScale = 0.5;
//   cube(0,1.6,0, 2,0.4,1, 0); //Top
//   cube(-1.75,0.65,0, 0.25,0.55,1, 0); //Left
//   cube(1.75,0.65,0, 0.25,0.55,1, 0); //Right
//   cube(0,0.65,0, 0.2,0.55,1, 0); //Middle
//
//   //Logo Store
//   glColor3f(0.5, 0.5, 0.5);
//   glBindTexture(GL_TEXTURE_2D,_textureBrandStore);
//   glBegin(GL_QUADS);
//   float texRepX = 1.0;
//   float texRepY = 1.0;
//
//   //Left
//   glNormal3f(0, 0, 1);
//   glTexCoord2f(0.0,0.0); glVertex3f(-1.5, 1.3, 1.01);
//   glTexCoord2f(texRepX,0.0); glVertex3f(-0.2, 1.3, 1.01);
//   glTexCoord2f(texRepX,texRepY); glVertex3f(-0.2, 1.7, 1.01);
//   glTexCoord2f(0.0,texRepY); glVertex3f(-1.5, 1.7, 1.01);
//
//   //Right
//   glNormal3f(0, 0, 1);
//   glTexCoord2f(0.0,0.0); glVertex3f(0.2, 1.3, 1.01);
//   glTexCoord2f(texRepX,0.0); glVertex3f(1.5, 1.3, 1.01);
//   glTexCoord2f(texRepX,texRepY); glVertex3f(1.5, 1.7, 1.01);
//   glTexCoord2f(0.0,texRepY); glVertex3f(0.2, 1.7, 1.01);
//   glEnd();
//
//   //"Floor" for brown workshop
//   glColor3f(0.7, 0.7, 0.7);
//   glBindTexture(GL_TEXTURE_2D,_textureSideWalk);
//   texScale = 1;
//   cube(0,-0.05,0.9, 2,0.15,0.1, 0);
//
//   //Garage Doors
//   glColor3f(0.5, 0.5, 0.5);
//   glBindTexture(GL_TEXTURE_2D,_textureGarageDoor);
//   glBegin(GL_QUADS);
//    texRepX = 1.0;
//    texRepY = 1.0;
//
//   //Left
//   glNormal3f(0, 0, 1);
//   glTexCoord2f(0.0,0.0); glVertex3f(-1.5, 0.1, 0.9);
//   glTexCoord2f(texRepX,0.0); glVertex3f(-0.2, 0.1, 0.9);
//   glTexCoord2f(texRepX,texRepY); glVertex3f(-0.2, 1.2, 0.9);
//   glTexCoord2f(0.0,texRepY); glVertex3f(-1.5, 1.2, 0.9);
//
//   //Right
//   glNormal3f(0, 0, 1);
//   glTexCoord2f(0.0,0.0); glVertex3f(0.2, 0.1, 0.9);
//   glTexCoord2f(texRepX,0.0); glVertex3f(1.5, 0.1, 0.9);
//   glTexCoord2f(texRepX,texRepY); glVertex3f(1.5, 1.2, 0.9);
//   glTexCoord2f(0.0,texRepY); glVertex3f(0.2, 1.2, 0.9);
//   glEnd();
//
//   //Undo transformations
//   glPopMatrix();
//}
