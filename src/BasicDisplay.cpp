#include "BasicDisplay.h"

//Constructor
BasicDisplay::BasicDisplay(){}

BasicDisplay::BasicDisplay(point startPoint, point endPoint, tile objectTile, GLint texture, float _angle){
    this->startPoint = startPoint;
    this->endPoint = endPoint;
    this->texture = texture;
    this->objectTile = objectTile;
    this->_angle = _angle;
}
// Display object for the front or back side
void BasicDisplay::displayFront(){
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(-2,0,-22);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS); //Wall
            glTexCoord3f(0.0,objectTile.vertical,0.1); glVertex3f(endPoint.x,startPoint.y,startPoint.z);
            glTexCoord3f(objectTile.horizontal,objectTile.vertical,0.1); glVertex3f(startPoint.x,startPoint.y,startPoint.z);
            glTexCoord3f(objectTile.horizontal,0.0,0.1); glVertex3f(startPoint.x,endPoint.y,startPoint.z);
            glTexCoord3f(0.0,0.0,0.1); glVertex3f(endPoint.x,endPoint.y,startPoint.z);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

// Display object for the top or bottom side
void BasicDisplay::displayBase(){
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(-2,0,-22);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS); //Wall
            glTexCoord3f(0.0,objectTile.vertical,0.1); glVertex3f(startPoint.x,startPoint.y,startPoint.z);
            glTexCoord3f(objectTile.horizontal,objectTile.vertical,0.1); glVertex3f(endPoint.x,startPoint.y,startPoint.z);
            glTexCoord3f(objectTile.horizontal,0.0,0.1); glVertex3f(endPoint.x,startPoint.y,endPoint.z);
            glTexCoord3f(0.0,0.0,0.1); glVertex3f(startPoint.x,startPoint.y,endPoint.z);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

// Display object for the left or right side
void BasicDisplay::displaySide(){
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(-2,0,-22);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS); //Wall
            glTexCoord3f(0.0,objectTile.vertical,0.1); glVertex3f(endPoint.x,startPoint.y,startPoint.z);
            glTexCoord3f(objectTile.horizontal,objectTile.vertical,0.1); glVertex3f(endPoint.x,startPoint.y,endPoint.z);
            glTexCoord3f(objectTile.horizontal,0.0,0.1); glVertex3f(startPoint.x,endPoint.y,endPoint.z);
            glTexCoord3f(0.0,0.0,0.1); glVertex3f(startPoint.x,endPoint.y,startPoint.z);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
