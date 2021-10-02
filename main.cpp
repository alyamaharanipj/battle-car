int POS_X, POS_Y;
#define WIDTH 1200
#define HEIGHT 900

#define INTERVAL 15
#include "string"
#include <GL/freeglut.h>
#include <GL/glext.h>
#include "Model.h"
#include "JTKPOLBAN.h"
#include "Cube.h"
#include "DataType.h"
#include "Car.h"
#include "PoliceCar.h"
#include "StraightRoad.h"
#include "SideRoad.h"
#include "Laser.h"

std::string treeName = "Models/Lowpoly_tree.obj";

GLfloat light_pos[] = {-10.0f, 10.0f, 100.00f, 1.0f};

enum ProjectionMode {
	BIRD,
	FIRST_PERSON
};

ProjectionMode projection = BIRD;       //  Projection mode

GLuint
_textureSkyboxBack,
_textureSkyboxFront,
_textureSkyboxLeft,
_textureSkyboxRight,
_textureSkyboxTop,
_textureGlass,
_textureWoodFence,
_textureAsphalt,
_textureBasicMetal,
_textureBrownBrick,
_textureCarWheel,
_textureCinderBlock,
_textureGarageDoor,
_textureGrass,
_textureGreyBrick,
_textureHedge,
_textureSidewalk,
_textureWalkway,
_textureWhiteBrick,
_textureCarGrill,
_textureFrontDoor2,
_textureWindow1,
_textureMetalRoof,
_textureTireTread,
_textureWarehouseWindow,
_textureHeadLamp,
_textureCarbonFiber,
_textureWoodBeam,
_textureChecker,
_textureTrackFence,
_textureFloor,
_textureStandFence,
_textureSponsor,
_textureSideWalk;

// track
float mTrackBlockSize = 4;

//Light Vectors
float Ambient[]   = {0.01*80 ,0.01*80 ,0.01*80 ,1.0};
float Diffuse[]   = {1.0,1.0,1.0,1.0};
float Specular[]  = {0.01*0,0.01*0,0.01*0,1.0};

//Texture Variables
int tMode = 0;

//Object Model
Model tree(0.0f, -2.0f, 18.0f);
Model building(-0.9f, 0.0f, 15.0f);

bool shoot = false;
//Create Car Object
//enemy red car
point enemyRedCarStartPoint{5, 1, -13};
point enemyRedCarEndPoint{0.5 * mTrackBlockSize, 0.4 * mTrackBlockSize, 0.4 * mTrackBlockSize};
color enemyRedCarColor{0.7, 0.2, 0.2};
Car enemyRedCar(enemyRedCarStartPoint, enemyRedCarEndPoint, 0, enemyRedCarColor, 0.1000);

//enemy blue car
point enemyBlueCarStartPoint{5, 1, 13};
point enemyBlueCarEndPoint{0.5 * mTrackBlockSize, 0.4 * mTrackBlockSize, 0.4 * mTrackBlockSize};
color enemyBlueCarColor{0.2, 0.2, 0.7};
Car enemyBlueCar(enemyBlueCarStartPoint, enemyBlueCarEndPoint, 0, enemyBlueCarColor, 0.10);

// enemy green car
point enemyGreenCarStartPoint{-5, 1, 13};
point enemyGreenCarEndPoint{0.5 * mTrackBlockSize, 0.4 * mTrackBlockSize, 0.4 * mTrackBlockSize};
color enemyGreenCarColor{0.2, 0.7, 0.2};
Car enemyGreenCar(enemyGreenCarStartPoint, enemyGreenCarEndPoint, 180, enemyGreenCarColor, 0.0800);

// enemy yellow car
point enemyYellowCarStartPoint{-5, 1, -13};
point enemyYellowCarEndPoint{0.5 * mTrackBlockSize, 0.4 * mTrackBlockSize, 0.4 * mTrackBlockSize};
color enemyYellowCarColor{0.7, 0.7, 0.2};
Car enemyYellowCar(enemyYellowCarStartPoint, enemyYellowCarEndPoint, 180, enemyYellowCarColor, 0.0800);

//police car
point policeStartPoint{0, 1, 0};
point policeEndPoint{0.5 * mTrackBlockSize, 0.4 * mTrackBlockSize, 0.4 * mTrackBlockSize};
color policeColor{0.1, 0.1, 0.1};
PoliceCar policeCar(policeStartPoint, policeEndPoint, 270, policeColor, 0.1000);

// Construct Laser
point startPointLaser{2.0f, 1.0f, 2.0f};
point endPointLaser{policeStartPoint.x, 1.0f, policeStartPoint.z};
Laser laser(startPointLaser, endPointLaser, policeCar.getAngle(), 0.1000);

//Camera settings
float fpX, fpY = 5, fpZ; // Eye Position
int th;                 //  Azimuth of view angle
int ph = 0;             //  Elevation of view angle
int fov = 100;          //  Field of view (for perspective)
int light = 1;          //  Lighting
double asp = 2;         //  Aspect ratio
double dim = 35.0;      //  Size of world

// Light values
int distance  =   25;  // Light distance
int smooth    =   1;  // Smooth/Flat shading
int local     =   0;  // Local Viewer Model
float shiny   =   1;  // Shininess (value)
int zh        =  90;  // Light azimuth

int axes = 0;       //  Display axes
int mode = 0;       //  Projection mode
int move = 1;       //  Move light

// Track values
float texScale = 0.5;
float roadSize = 3;
float sideWalkSize = 1;
float totalRoadSize = sideWalkSize * 2 + roadSize;
float landSize = totalRoadSize * 5 + 1;
float leftPoint = (landSize * -2.5) - totalRoadSize;
float rightPoint = (landSize * 2.5) + totalRoadSize;

void init() {
    _textureSkyboxBack = LoadTexBMP("skybox-back.bmp");
	_textureSkyboxFront = LoadTexBMP("skybox-front.bmp");
	_textureSkyboxLeft = LoadTexBMP("skybox-left.bmp");
	_textureSkyboxRight = LoadTexBMP("skybox-right.bmp");
	_textureSkyboxTop = LoadTexBMP("skybox-top.bmp");
	_textureGlass = LoadTexBMP("glass.bmp");
	_textureWoodFence = LoadTexBMP("wood-fence.bmp");
	_textureAsphalt = LoadTexBMP("asphalt.bmp");
	_textureBasicMetal = LoadTexBMP("basic-metal.bmp");
	_textureBrownBrick = LoadTexBMP("brown-brick.bmp");
	_textureCarWheel = LoadTexBMP("car-wheel.bmp");
	_textureCinderBlock = LoadTexBMP("cinder-block.bmp");
	_textureGarageDoor = LoadTexBMP("garage-door.bmp");
	_textureGrass = LoadTexBMP("grass.bmp");
	_textureGreyBrick = LoadTexBMP("grey-brick.bmp");
	_textureHedge = LoadTexBMP("hedge.bmp");
	_textureSidewalk = LoadTexBMP("sidewalk.bmp");
	_textureWalkway = LoadTexBMP("walkway.bmp");
	_textureWhiteBrick = LoadTexBMP("white-brick.bmp");
	_textureCarGrill = LoadTexBMP("car-grill.bmp");
	_textureFrontDoor2 = LoadTexBMP("front-door-2.bmp");
	_textureWindow1 = LoadTexBMP("window-1.bmp");
	_textureMetalRoof = LoadTexBMP("metal-roof.bmp");
	_textureTireTread = LoadTexBMP("tire-tread.bmp");
	_textureWarehouseWindow = LoadTexBMP("warehouse-window.bmp");
	_textureHeadLamp = LoadTexBMP("headlamp.bmp");
	_textureCarbonFiber = LoadTexBMP("carbon-fiber.bmp");
	_textureWoodBeam = LoadTexBMP("wood-beam.bmp");
	_textureChecker = LoadTexBMP("checker.bmp");
	_textureTrackFence = LoadTexBMP("track-fence.bmp");
	_textureFloor = LoadTexBMP("floor.bmp");
	_textureStandFence = LoadTexBMP("stand-fence.bmp");
	_textureSponsor = LoadTexBMP("sponsor.bmp");

	tree.load(treeName.c_str());
}

static void skybox(float dim) {
   glDisable(GL_POLYGON_OFFSET_FILL);

   //  Set specular color to white
   float white[] = {1,1,1,1};
   float black[] = {0,0,0,1};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,0);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

   glColor3f(0.7, 0.7, 0.7);
   glBindTexture(GL_TEXTURE_2D,_textureSkyboxFront);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
   glBegin(GL_QUADS);
   glNormal3f(0, 0, -1);
   glTexCoord2f(1.0,0.0); glVertex3f(+dim,-dim, dim);
   glTexCoord2f(0.0,0.0); glVertex3f(-dim,-dim, dim);
   glTexCoord2f(0.0,1.0); glVertex3f(-dim,+dim, dim);
   glTexCoord2f(1.0,1.0); glVertex3f(+dim,+dim, dim);
   glEnd();

   glBindTexture(GL_TEXTURE_2D,_textureSkyboxBack);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
   glBegin(GL_QUADS);
   glNormal3f(0, 0, 1);
   glTexCoord2f(1.0,0.0); glVertex3f(-dim,-dim, -dim);
   glTexCoord2f(0.0,0.0); glVertex3f(+dim,-dim, -dim);
   glTexCoord2f(0.0,1.0); glVertex3f(+dim,+dim, -dim);
   glTexCoord2f(1.0,1.0); glVertex3f(-dim,+dim, -dim);
   glEnd();

   glBindTexture(GL_TEXTURE_2D,_textureSkyboxRight);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
   glBegin(GL_QUADS);
   glNormal3f(-1, 0, 0);
   glTexCoord2f(1.0,0.0); glVertex3f(dim,-dim, -dim);
   glTexCoord2f(0.0,0.0); glVertex3f(dim,-dim, +dim);
   glTexCoord2f(0.0,1.0); glVertex3f(dim,+dim, +dim);
   glTexCoord2f(1.0,1.0); glVertex3f(dim,+dim, -dim);
   glEnd();

   glBindTexture(GL_TEXTURE_2D,_textureSkyboxLeft);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
   glBegin(GL_QUADS);
   glNormal3f(1, 0, 0);
   glTexCoord2f(1.0,0.0); glVertex3f(-dim,-dim, +dim);
   glTexCoord2f(0.0,0.0); glVertex3f(-dim,-dim, -dim);
   glTexCoord2f(0.0,1.0); glVertex3f(-dim,+dim, -dim);
   glTexCoord2f(1.0,1.0); glVertex3f(-dim,+dim, +dim);
   glEnd();

   glBindTexture(GL_TEXTURE_2D,_textureSkyboxTop);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
   glBegin(GL_QUADS);
   glNormal3f(0, -1, 0);
   glTexCoord2f(1.0,0.0); glVertex3f(+dim,dim, +dim);
   glTexCoord2f(0.0,0.0); glVertex3f(-dim,dim, +dim);
   glTexCoord2f(0.0,1.0); glVertex3f(-dim,dim, -dim);
   glTexCoord2f(1.0,1.0); glVertex3f(+dim,dim, -dim);
   glEnd();
}

void car(void)
{
    // car drawing
    enemyBlueCar.draw();
    enemyRedCar.draw();
    enemyGreenCar.draw();
    enemyYellowCar.draw();
    policeCar.drawPolice();
}

void surface(void){
    //Street surface - Main Street
    glColor3f(0.4, 0.4, 0.4);
    glBindTexture(GL_TEXTURE_2D,_textureAsphalt);

    //Road 1
    point startPoint_1{leftPoint, 0.3, (landSize * -2.5)};
    point endPoint_1{rightPoint - totalRoadSize - 1, 0.5, leftPoint + sideWalkSize};
    SideRoad front(startPoint_1, endPoint_1);
    front.draw();

    point startPoint_3{landSize + totalRoadSize + roadSize + sideWalkSize * 2, 0.3, startPoint_1.z};
    point endPoint_3{1, 0.5, roadSize};
    StraightRoad road3(startPoint_3, endPoint_3);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            startPoint_3.z += landSize;
            road3.setBottomLeftPoint(startPoint_3);
            road3.drawHorizontally();
        }
        startPoint_3.x += -32;
        startPoint_3.z = startPoint_1.z;
    }

    point startPoint_4{- landSize * 2 - totalRoadSize * 3 + sideWalkSize * 3, 0.3, - startPoint_1.z - totalRoadSize * 5 - sideWalkSize * 4.8};
    point endPoint_4{1, 0.5, roadSize};
    StraightRoad road4(startPoint_4, endPoint_4);
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            startPoint_4.x += landSize + totalRoadSize + sideWalkSize ;
            road4.setBottomLeftPoint(startPoint_4);
            road4.drawVertically();
        }
        startPoint_4.z -= 26;
        startPoint_4.x = - landSize * 2 - totalRoadSize * 3 + sideWalkSize * 3;
    }
}

void grass(void) {
	point startPoint{100, 0, 100};
	point endPoint{mTrackBlockSize / 2, 0.1, mTrackBlockSize / 2};

	glColor3f(0.4, 0.6, 0.2);

	for(int i = 0; i < 51; i++) {
        startPoint.z = 100;
		for(int j = 0; j < 51; j++) {
            Cube cube(startPoint, endPoint, _textureGrass, 0, endPoint.x);
            cube.draw();
			startPoint.z -= mTrackBlockSize;
		}
		startPoint.x -= mTrackBlockSize;
	}
}

void drawLaser(void){
    laser.draw();
}

void drawModel(void)
{
    // Draw tree
    for(int i = 2; i > -3; i--)
    {
        for(int j = 2; j > -3; j--)
        {
            if(j != 0)
            {
                glPushMatrix();
                    glTranslatef(j * 25.0f, -2.0f, i * 25.0f);
                    tree.draw();
                glPopMatrix();
            }
        }
    }
}

static void setEnvLighting()
{
   float ambScale = 0.8;

   // Light values
    int zh        =  90;  // Light azimuth

   if(Sin(zh) >= 0.2) {
      Ambient[0] = (255 / 255) * ambScale;
      Ambient[1] = (255 / 255) * ambScale;
      Ambient[2] = (255 / 255) * ambScale;

      Diffuse[0] = 1.0;
      Diffuse[1] = 1.0;
      Diffuse[2] = 1.0;
   } else if (Sin(zh) < 0.4 && Sin(zh) >= 0) {
      Ambient[0] = (255 / 255) * ambScale;
      Ambient[1] = ((60 + (195*Sin(zh)*2.5)) / 255) * ambScale;
      Ambient[2] = ((60 + (195*Sin(zh)*2.5)) / 255) * ambScale;

      Diffuse[0] = Sin(zh)*2.5;
      Diffuse[1] = Sin(zh)*2.5;
      Diffuse[2] = Sin(zh)*2.5;
   } else if (Sin(zh) < 0 && Sin(zh) >= -0.4){
      Ambient[0] = ((255 - (235*Sin(zh)*-2.5)) / 255) * ambScale;
      Ambient[1] = (60 / 255) * ambScale;
      Ambient[2] = ((60 + (120*Sin(zh)*-2.5)) / 255) * ambScale;

      Diffuse[0] = 0;
      Diffuse[1] = 0;
      Diffuse[2] = 0;
   } else {
      Ambient[0] = (20 / 255) * ambScale;
      Ambient[1] = (60 / 255) * ambScale;
      Ambient[2] = (180 / 255) * ambScale;

      Diffuse[0] = 0;
      Diffuse[1] = 0;
      Diffuse[2] = 0;
   }
}

void display() {
    //  Erase the window and the depth buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //  Enable Z-buffering in OpenGL
    glEnable(GL_DEPTH_TEST);
    //Enable Face Culling
    glEnable(GL_CULL_FACE);
    //Enable Textures
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV , GL_TEXTURE_ENV_MODE , tMode?GL_REPLACE:GL_MODULATE);

    glEnable(GL_CULL_FACE);
	glDisable(GL_CULL_FACE);
    //  Undo previous transformations
    glLoadIdentity();
    //  Perspective - set eye position
    th = policeCar.getAngle() + 90;
    //  Elevation of view angle
    if(projection == BIRD)
    {
        fpX = policeCar.getStartPoint().x - 5 * Cos(policeCar.getAngle());
        fpZ = policeCar.getStartPoint().z + 5 * Sin(policeCar.getAngle());
    }else
    {
        fpX = policeCar.getStartPoint().x;
        fpZ = policeCar.getStartPoint().z;
    }

    float refX = (dim * Sin(th)) + fpX;
    float refY = (dim * Sin(ph));
    float refZ = (dim * Cos(th)) + fpZ;
    gluLookAt(fpX,fpY,fpZ, refX,refY,refZ, 0,1,0);

    //  Flat or smooth shading
    glShadeModel(smooth ? GL_SMOOTH : GL_FLAT);

    //  Light position
    float Position[]  = {distance*Cos(zh),distance*Sin(zh),0,1.0};

    //  OpenGL should normalize normal vectors
    glEnable(GL_NORMALIZE);
    //  Enable lighting
    glEnable(GL_LIGHTING);
    //  Location of viewer for specular calculations
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,local);
    //  glColor sets ambient and diffuse color materials
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    //  Enable light 0 - Sun
    glEnable(GL_LIGHT0);
    //  Set ambient, diffuse, specular components and position of light 0 (Sun)
    glLightfv(GL_LIGHT0,GL_AMBIENT ,Ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
    glLightfv(GL_LIGHT0,GL_POSITION,Position);

    //Skybox
    skybox(128);

    //  Set specular color to white
    float white[] = {1,1,1,1};
    float black[] = {0,0,0,1};

    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

    //Enable offset for windows, doors, and other decals
    glPolygonOffset(1,1);
    glEnable(GL_POLYGON_OFFSET_FILL);

    // Grass
    grass();
    drawModel();
    surface();
    car();
    if(shoot)
    {
        drawLaser();
    }

    //  Render the scene and make it visible
    ErrCheck("display");
    glFlush();
    glutSwapBuffers();
}

void reshape(int width,int height)
{
   //  Ratio of the width to the height of the window
   asp = (height > 0) ? (double) width / height : 1;
   //  Set the viewport to the entire window
   glViewport(0,0, width,height);
   //  Set projection
   Project(fov, asp, dim);
}

void special(int key,int x,int y)
{
   //  Right arrow key - increase angle by 5 degrees
   if (key == GLUT_KEY_RIGHT)
   {
        if(policeCar.getAngle() >= 135 && policeCar.getAngle() < 225){
            policeCar.moveBack();
        }else if(policeCar.getAngle() >= 225 && policeCar.getAngle() < 315){
            policeCar.moveLeft();
        }else if((policeCar.getAngle() >= 315 && policeCar.getAngle() < 360) || (policeCar.getAngle() > 0 && policeCar.getAngle() < 45)){
            policeCar.moveFront();
        }else if(policeCar.getAngle() >= 45 && policeCar.getAngle() < 135){
            policeCar.moveRight();
        }
   }
   //  Left arrow key - decrease angle by 5 degrees
   else if (key == GLUT_KEY_LEFT)
    {
        if(policeCar.getAngle() >= 135 && policeCar.getAngle() < 225){
            policeCar.moveFront();
        }else if(policeCar.getAngle() >= 225 && policeCar.getAngle() < 315){
            policeCar.moveRight();
        }else if((policeCar.getAngle() >= 315 && policeCar.getAngle() < 360) || (policeCar.getAngle() > 0 && policeCar.getAngle() < 45)){
            policeCar.moveBack();
        }else if(policeCar.getAngle() >= 45 && policeCar.getAngle() < 135){
            policeCar.moveLeft();
        }
   }
   //  Up arrow key - increase elevation by 5 degrees
   else if (key == GLUT_KEY_UP)
      ph += 5;
   //  Down arrow key - decrease elevation by 5 degrees
   else if (key == GLUT_KEY_DOWN)
      ph -= 5;
 //  PageUp key - increase dim
   else if (key == GLUT_KEY_PAGE_DOWN)
      dim += 0.1;
   //  PageDown key - decrease dim
   else if (key == GLUT_KEY_PAGE_UP && dim>1)
      dim -= 0.1;
   th %= 360;
   ph %= 360;

   //  Update projection
   Project(fov,asp,dim);
   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}

/*
 *  GLUT calls this routine when the window is resized
 */
void idle()
{
   //  Elapsed time in seconds
   double t = glutGet(GLUT_ELAPSED_TIME)/1000.0;
   zh = fmod(10*t,360.0);

   setEnvLighting();

   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}

/*
 *  GLUT calls this routine when a key is pressed
 */void key(unsigned char ch,int x,int y)
{
   //  Exit on ESC
   if (ch == 27)
      exit(0);
   //  Reset view angle
   else if (ch == '0')
      th = ph = 0;
   //  Toggle axes
   else if (ch == 'x' || ch == 'X')
    {
        policeCar.increaseStepsInc();
        printf("%f", policeCar.getStepsInc());
    }
       else if (ch == 'z' || ch == 'Z')
    {
        policeCar.decreaseStepsInc();
        printf("%f", policeCar.getStepsInc());
    }
   //  Switch projection mode
   else if (ch == 'p' || ch == 'P') {
        if(projection == BIRD)
        {
            projection = FIRST_PERSON;
            ph = -15;             //  Elevation of view angle
        }else{
            projection = BIRD;
            ph = 0;             //  Elevation of view angle
        }
   }
   else if (ch == 'a'|| ch == 'A')
   {
      policeCar.addAngle();
   }
   else if (ch == 'd' || ch == 'D')
   {
      policeCar.decreaseAngle();
   }
   else if(ch==' ')
   {
       shoot = true;
   }

   th %= 360;
   ph %= 360;

   //  Update projection
   Project(fov,asp,dim);

   //  Reproject
   Project(fov,asp,dim);
   //  Animate if requested
   glutIdleFunc(move?idle:NULL);
   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}

void enemyBlueCarTimer(void) {
    if(enemyBlueCar.getStepsInc()>0)
    {
	if(enemyBlueCar.getAngle() > 359) enemyBlueCar.setAngle(0);
	else if(enemyBlueCar.getAngle() < 0) enemyBlueCar.setAngle(359);;

	if(enemyBlueCar.getStartPoint().x == enemyBlueCarStartPoint.x && enemyBlueCar.getStartPoint().z == enemyBlueCarStartPoint.z && enemyBlueCar.getAngle() == 0)
    {
        enemyBlueCar.resetStep();
    }

	// lane 1, step 0 - 12, direction -x
	if(enemyBlueCar.getSteps() >= 0 && enemyBlueCar.getSteps() < 27) {
		enemyBlueCar.moveRight();
		enemyBlueCar.addSteps();
	}

    // Turn left - Road 2
    if(enemyBlueCar.getSteps() >= 27 && enemyBlueCar.getSteps() < 80) {
		if(enemyBlueCar.getAngle() >= 0 && enemyBlueCar.getAngle() <= 90)
        {
            enemyBlueCar.addAngle();
        }else{
            enemyBlueCar.moveBack();
            enemyBlueCar.addSteps();
        }
	}

    // Turn left - Road 3
    if(enemyBlueCar.getSteps() >= 80 && enemyBlueCar.getSteps() < 143) {
		if(enemyBlueCar.getAngle() >= 90 && enemyBlueCar.getAngle() <= 180)
        {
            enemyBlueCar.addAngle();
        }else{
            enemyBlueCar.moveLeft();
            enemyBlueCar.addSteps();
        }
	}

//    // Turn left - Road 4
    if(enemyBlueCar.getSteps() >= 143 && enemyBlueCar.getSteps() < 196) {
		if(enemyBlueCar.getAngle() >= 180 && enemyBlueCar.getAngle() <= 270)
        {
            enemyBlueCar.addAngle();
        }else{
            enemyBlueCar.moveFront();
            enemyBlueCar.addSteps();
        }
	}

    // Turn left - Road 5
    if(enemyBlueCar.getSteps() >= 196 && enemyBlueCar.getSteps() < 230) {
		if(enemyBlueCar.getAngle() != 180)
        {
            enemyBlueCar.decreaseAngle();
        }else{
            enemyBlueCar.moveLeft();
            enemyBlueCar.addSteps();
        }
	}

    // Turn left - Road 6
    if(enemyBlueCar.getSteps() >= 230 && enemyBlueCar.getSteps() < 308) {
		if(enemyBlueCar.getAngle() != 90)
        {
            enemyBlueCar.decreaseAngle();
        }else{
            enemyBlueCar.moveBack();
            enemyBlueCar.addSteps();
        }
	}

    // Turn left - Road 7
    if(enemyBlueCar.getSteps() >= 308 && enemyBlueCar.getSteps() < 436) {
		if(enemyBlueCar.getAngle() != 0)
        {
            enemyBlueCar.decreaseAngle();
        }else{
            enemyBlueCar.moveRight();
            enemyBlueCar.addSteps();
        }
	}

	    // Turn left - Road 8
    if(enemyBlueCar.getSteps() >= 436 && enemyBlueCar.getSteps() < 564) {
		if(enemyBlueCar.getAngle() != 270)
        {
            enemyBlueCar.decreaseAngle();
        }else{
            enemyBlueCar.moveFront();
            enemyBlueCar.addSteps();
        }
	}

	// Road 9
    if(enemyBlueCar.getSteps() >= 564 && enemyBlueCar.getSteps() < 595) {
		if(enemyBlueCar.getAngle() != 180)
        {
            enemyBlueCar.decreaseAngle();
        }else{
            enemyBlueCar.moveLeft();
            enemyBlueCar.addSteps();
        }
	}

    // Road 10
    if(enemyBlueCar.getSteps() >= 595 && enemyBlueCar.getSteps() < 620) {
		if(enemyBlueCar.getAngle() != 90)
        {
            enemyBlueCar.decreaseAngle();
        }else{
            enemyBlueCar.moveBack();
            enemyBlueCar.addSteps();
        }
	}

    // Road 11
    if(enemyBlueCar.getSteps() >= 620 && enemyBlueCar.getSteps() < 649) {
		if(enemyBlueCar.getAngle() >= 90 && enemyBlueCar.getAngle() <= 180)
        {
            enemyBlueCar.addAngle();
        }else{
            enemyBlueCar.moveLeft();
            enemyBlueCar.addSteps();
        }
	}

    // Road 12
    if(enemyBlueCar.getSteps() >= 649 && enemyBlueCar.getSteps() < 674) {
		if(enemyBlueCar.getAngle() != 90)
        {
            enemyBlueCar.decreaseAngle();
        }else{
            enemyBlueCar.moveBack();
            enemyBlueCar.addSteps();
        }
	}

    if(enemyBlueCar.getSteps() >= 674 && enemyBlueCar.getSteps() < 676) {
		if(enemyBlueCar.getAngle() != 0)
        {
            enemyBlueCar.decreaseAngle();
        }else{
            enemyBlueCar.moveRight();
            enemyBlueCar.addSteps();
        }
	}
    }
}

void enemyRedCarTimer(void)
{
    if(enemyRedCar.getStepsInc()>0)
    {
        if(enemyRedCar.getAngle() > 359) enemyRedCar.setAngle(0);
        else if(enemyRedCar.getAngle() < 0) enemyRedCar.setAngle(359);;

        // lane 1, step 0 - 12, direction -x
        if(enemyRedCar.getSteps() >= 0 && enemyRedCar.getSteps() < 50) {
            enemyRedCar.moveRight();
            enemyRedCar.addSteps();
        }
    }
}

void enemyYellowCarTimer(void)
{
    if(enemyYellowCar.getStepsInc()>0)
    {
        if(enemyYellowCar.getAngle() > 359) enemyYellowCar.setAngle(0);
        else if(enemyYellowCar.getAngle() < 0) enemyYellowCar.setAngle(359);;

        // lane 1, step 0 - 12, direction -x
        if(enemyYellowCar.getSteps() >= 0 && enemyYellowCar.getSteps() < 10) {
            enemyYellowCar.moveLeft();
            enemyYellowCar.addSteps();
        }
    }
}

void enemyGreenCarTimer(void)
{
    if(enemyGreenCar.getStepsInc()>=0)
    {
        if(enemyGreenCar.getAngle() > 359) enemyGreenCar.setAngle(0);
        else if(enemyGreenCar.getAngle() < 0) enemyGreenCar.setAngle(359);

        if(enemyGreenCar.getStartPoint().x == enemyGreenCarStartPoint.x && enemyGreenCar.getStartPoint().z == enemyGreenCarStartPoint.z && enemyGreenCar.getAngle() == 180)
        {
            enemyGreenCar.resetStep();
        }


        // Road 1
        if(enemyGreenCar.getSteps() >= 0 && enemyGreenCar.getSteps() < 60) {
            enemyGreenCar.moveLeft();
            enemyGreenCar.addSteps();
        }

        // Turn left - Road 2
        if(enemyGreenCar.getSteps() >= 60 && enemyGreenCar.getSteps() < 111) {
            if(enemyGreenCar.getAngle() >= 180 && enemyGreenCar.getAngle() <= 270)
            {
                enemyGreenCar.addAngle();
            }else{
                enemyGreenCar.moveFront();
                enemyGreenCar.addSteps();
            }
        }

        // Turn left - Road 3
        if(enemyGreenCar.getSteps() >= 111 && enemyGreenCar.getSteps() < 241) {
            if(enemyGreenCar.getAngle() >= 270 && enemyGreenCar.getAngle() <= 360)
            {
                enemyGreenCar.addAngle();
            }else{
                enemyGreenCar.moveRight();
                enemyGreenCar.addSteps();
            }
        }
        // Turn left - Road 4
        if(enemyGreenCar.getSteps() >= 241 && enemyGreenCar.getSteps() < 371) {
            if(enemyGreenCar.getAngle() >= 0 && enemyGreenCar.getAngle() <= 90)
            {
                enemyGreenCar.addAngle();
            }else{
                enemyGreenCar.moveBack();
                enemyGreenCar.addSteps();
            }
        }

        // Turn left - Road 5
        if(enemyGreenCar.getSteps() >= 371 && enemyGreenCar.getSteps() < 403) {
            if(enemyGreenCar.getAngle() >= 90 && enemyGreenCar.getAngle() <= 180)
            {
                enemyGreenCar.addAngle();
            }else{
                enemyGreenCar.moveLeft();
                enemyGreenCar.addSteps();
            }
        }

        // Turn left - Road 6
        if(enemyGreenCar.getSteps() >= 403 && enemyGreenCar.getSteps() < 455) {
            if(enemyGreenCar.getAngle() >= 180 && enemyGreenCar.getAngle() <= 270)
            {
                enemyGreenCar.addAngle();
            }else{
                enemyGreenCar.moveFront();
                enemyGreenCar.addSteps();
            }
        }

        // Turn left - Road 7
        if(enemyGreenCar.getSteps() >= 455 && enemyGreenCar.getSteps() < 487) {
            if(enemyGreenCar.getAngle() != 180)
            {
                enemyGreenCar.decreaseAngle();
            }else{
                enemyGreenCar.moveLeft();
                enemyGreenCar.addSteps();
            }
        }

        // Turn left - Road 8
        if(enemyGreenCar.getSteps() >= 487 && enemyGreenCar.getSteps() < 539) {
            if(enemyGreenCar.getAngle() != 90)
            {
                enemyGreenCar.decreaseAngle();
            }else{
                enemyGreenCar.moveBack();
                enemyGreenCar.addSteps();
            }
        }

        // Turn left - Road 9
        if(enemyGreenCar.getSteps() >= 539 && enemyGreenCar.getSteps() < 605) {
            if(enemyGreenCar.getAngle() != 180)
            {
                enemyGreenCar.addAngle();
            }else{
                enemyGreenCar.moveLeft();
                enemyGreenCar.addSteps();
            }
        }

        // Turn left - Road 10
        if(enemyGreenCar.getSteps() >= 605 && enemyGreenCar.getSteps() < 632) {
            if(enemyGreenCar.getAngle() >= 180 && enemyGreenCar.getAngle() <= 270)
            {
                enemyGreenCar.addAngle();
            }else{
                enemyGreenCar.moveFront();
                enemyGreenCar.addSteps();
            }
        }

        // Turn Left - Road 10
        if(enemyGreenCar.getSteps() >= 632 && enemyGreenCar.getSteps() < 760) {
            if(enemyGreenCar.getAngle() >= 270 && enemyGreenCar.getAngle() <= 360)
            {
                enemyGreenCar.addAngle();
            }else{
                enemyGreenCar.moveRight();
                enemyGreenCar.addSteps();
            }
        }

        // Turn Left - Road 11
        if(enemyGreenCar.getSteps() >= 760 && enemyGreenCar.getSteps() < 812) {
            if(enemyGreenCar.getAngle() != 270)
            {
                enemyGreenCar.decreaseAngle();
            }else{
                enemyGreenCar.moveFront();
                enemyGreenCar.addSteps();
            }
        }

        // Turn Left - Road 12
        if(enemyGreenCar.getSteps() >= 812 && enemyGreenCar.getSteps() < 880) {
            if(enemyGreenCar.getAngle() != 180)
            {
                enemyGreenCar.decreaseAngle();
            }else{
                enemyGreenCar.moveLeft();
                enemyGreenCar.addSteps();
            }
        }
    }
}

void policeCarTimer(void)
{
    if(policeCar.getStepsInc() > 0)
    {
        if(policeCar.getAngle() > 360) policeCar.setAngle(0);
        else if(policeCar.getAngle() < 0) policeCar.setAngle(360);
        if(policeCar.getAngle() >= 135 && policeCar.getAngle() < 225){
            policeCar.moveLeft();
        }else if(policeCar.getAngle() >= 225 && policeCar.getAngle() < 315){
            policeCar.moveFront();
        }else if((policeCar.getAngle() >= 315 && policeCar.getAngle() <= 360) || (policeCar.getAngle() >= 0 && policeCar.getAngle() < 45)){
            policeCar.moveRight();
        }else if(policeCar.getAngle() >= 45 && policeCar.getAngle() < 135){
            policeCar.moveBack();
        }
        policeCar.addSteps();
    }
}

void laserTimer()
{
    if(shoot)
    {
        if(policeCar.getAngle() > 360) policeCar.setAngle(0);
        else if(policeCar.getAngle() < 0) policeCar.setAngle(360);

        if(laser.getSteps() >=0 && laser.getSteps() < 10)
        {
            point currentPointLaser{policeCar.getStartPoint().x + laser.getSteps() * Cos(policeCar.getAngle()), policeCar.getStartPoint().y, policeCar.getStartPoint().z - (laser.getSteps())*Sin(policeCar.getAngle())};
            point currentEndPointLaser{policeCar.getStartPoint().x + (laser.getSteps() + 3) * Cos(policeCar.getAngle()) , policeCar.getStartPoint().y, policeCar.getStartPoint().z - (laser.getSteps() + 3)*Sin(policeCar.getAngle())};
            laser.setStartPoint(currentPointLaser);
            laser.setEndPoint(currentEndPointLaser);
            drawLaser();
            laser.addSteps();
        }

        if(laser.getSteps() >= 10)
        {
            shoot = false;
            laser.resetStep();
        }

        if(laser.getStartPoint().x >= enemyBlueCar.getStartPoint().x - 0.5 && laser.getStartPoint().x <= enemyBlueCar.getStartPoint().x + 0.5 && laser.getStartPoint().x >= enemyBlueCar.getStartPoint().z - 0.5 && laser.getStartPoint().z <= enemyBlueCar.getStartPoint().z + 0.5)
        {
            enemyBlueCar.decreaseStepsInc();
        }

        if(laser.getStartPoint().x >= enemyGreenCar.getStartPoint().x - 0.5 && laser.getStartPoint().x <= enemyGreenCar.getStartPoint().x + 0.5 && laser.getStartPoint().x >= enemyGreenCar.getStartPoint().z - 0.5 && laser.getStartPoint().z <= enemyGreenCar.getStartPoint().z + 0.5)
        {
            enemyGreenCar.decreaseStepsInc();
        }
    }
}

void timer(int miliseconds) {
	enemyBlueCarTimer();
	enemyRedCarTimer();
	enemyYellowCarTimer();
	enemyGreenCarTimer();
	policeCarTimer();
	laserTimer();

	glutPostRedisplay();
	glutTimerFunc(10, timer, 0);
}

int main(int argc, char **argv) {
    //  Initialize GLUT
    glutInit(&argc,argv);
    //  Request double buffered, true color window with Z buffering at 600x600
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800,600);
    glutCreateWindow("Final Project");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(special);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutTimerFunc(10, timer, 0);
    glutMainLoop();
    return 0;
}
