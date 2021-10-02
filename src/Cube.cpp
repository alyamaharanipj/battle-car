#include "Cube.h"

Cube::Cube(){}

Cube::Cube(point startPoint, point endPoint, GLint texture, float _angle, float texScale)
{
    this->dStartPoint = startPoint;
    this->dEndPoint = endPoint;
    this->texture = texture;
    this->objectTile.horizontal = 1;
    this->objectTile.vertical = 1;
    this->_angle = _angle;
    this->texScale = texScale;
}

void Cube::setStartPoint(point startPoint){
    this->startPoint = startPoint;
}

void Cube::setEndPoint(point endPoint)
{

}

void Cube::setPoint(point startPoint, point endPoint)
{

}

void Cube::setCoordinate(){
    startPoint = dStartPoint;
    endPoint = dEndPoint;
}

void Cube::drawFront(){
   objectTile.horizontal = endPoint.x/texScale;
   objectTile.vertical = endPoint.y/texScale;
   glNormal3f( 0, 0, 1);
   glTexCoord2f(0.0,0.0); glVertex3f(-1,-1, 1);
   glTexCoord2f(objectTile.horizontal,0.0); glVertex3f(+1,-1, 1);
   glTexCoord2f(objectTile.horizontal,objectTile.vertical); glVertex3f(+1,+1, 1);
   glTexCoord2f(0.0,objectTile.vertical); glVertex3f(-1,+1, 1);
}

void Cube::drawBack(){
   objectTile.horizontal = endPoint.x/texScale;
   objectTile.vertical = endPoint.y/texScale;
   glNormal3f(0, 0,-1);
   glTexCoord2f(0.0,0.0); glVertex3f(+1,-1,-1);
   glTexCoord2f(objectTile.horizontal,0.0); glVertex3f(-1,-1,-1);
   glTexCoord2f(objectTile.horizontal,objectTile.vertical); glVertex3f(-1,+1,-1);
   glTexCoord2f(0.0,objectTile.vertical); glVertex3f(+1,+1,-1);
}

void Cube::drawLeft(){
   objectTile.horizontal = endPoint.z/texScale;
   objectTile.vertical = endPoint.y/texScale;
   glNormal3f(-1, 0, 0);
   glTexCoord2f(0.0,0.0); glVertex3f(-1,-1,-1);
   glTexCoord2f(objectTile.horizontal,0.0); glVertex3f(-1,-1,+1);
   glTexCoord2f(objectTile.horizontal,objectTile.vertical); glVertex3f(-1,+1,+1);
   glTexCoord2f(0.0,objectTile.vertical); glVertex3f(-1,+1,-1);
}

void Cube::drawRight(){
   objectTile.horizontal = endPoint.z/texScale;
   objectTile.vertical = endPoint.y/texScale;
   glNormal3f(+1, 0, 0);
   glTexCoord2f(0.0,0.0); glVertex3f(+1,-1,+1);
   glTexCoord2f(objectTile.horizontal,0.0); glVertex3f(+1,-1,-1);
   glTexCoord2f(objectTile.horizontal,objectTile.vertical); glVertex3f(+1,+1,-1);
   glTexCoord2f(0.0,objectTile.vertical); glVertex3f(+1,+1,+1);
}

void Cube::drawTop(){
   objectTile.horizontal = endPoint.x/texScale;
   objectTile.vertical = endPoint.z/texScale;
   glNormal3f(0,+1, 0);
   glTexCoord2f(0.0,0.0); glVertex3f(-1,+1,+1);
   glTexCoord2f(objectTile.horizontal,0.0); glVertex3f(+1,+1,+1);
   glTexCoord2f(objectTile.horizontal,objectTile.vertical); glVertex3f(+1,+1,-1);
   glTexCoord2f(0.0,objectTile.vertical); glVertex3f(-1,+1,-1);
}

void Cube::drawBottom(){
   objectTile.horizontal = endPoint.x/texScale;
   objectTile.vertical = endPoint.z/texScale;
   glNormal3f( 0,-1, 0);
   glTexCoord2f(0.0,0.0); glVertex3f(-1,-1,-1);
   glTexCoord2f(objectTile.horizontal,0.0); glVertex3f(+1,-1,-1);
   glTexCoord2f(objectTile.horizontal,objectTile.vertical); glVertex3f(+1,-1,+1);
   glTexCoord2f(0.0,objectTile.vertical); glVertex3f(-1,-1,+1);
}

void Cube::draw(){
   setCoordinate();
   glPushMatrix();

   //  Offset, scale and rotate
   glTranslated(startPoint.x,startPoint.y,startPoint.z);
   glRotated(_angle,0,1,0);
   glScaled(endPoint.x,endPoint.y,endPoint.z);

   float texScale = endPoint.x;

    glBindTexture(GL_TEXTURE_2D, texture);
   //  Cube
   glBegin(GL_QUADS);

    drawFront();
    drawBack();
    drawLeft();
    drawRight();
    drawTop();
    drawBottom();

   //  End
   glEnd();

   //  Undo transofrmations
   glPopMatrix();
}
