

#include <windows.h>//windows api(creating, managing windows)
#include<GL/glut.h> //openGL functions
#include<GL/glu.h> //accessory
#include<stdio.h>
#include<math.h>
#include<stdlib.h>//memory allocation,process control
#include<string.h> //memory allocation,string conversions
#define DEG2RAD 3.14159/180.0
#include <vector> //similar to array
#define PI 3.14159
using namespace std;

int i;
char *str1 = "BANGALORE INSTITUTE OF TECHNOLOGY(BIT), BANGALORE";
char *str2 = "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING";
char *str3 = "COMPUTER GRAPHICS AND VISUALIZATION LABORATORY";
char *str4 = "A MINI PROJECT";
char *str5 = "ON";
char *str6 = "IMPLEMENTATION OF BLOCKCHAIN";
char *str7 = "DESIGNED BY:";
char *str8 = "VISHAL D. BHAT & VISHWADUTT M.S.";
char *str9 = "(1BI17CS176) & (1BI17CS179)";
char *str10 = "LAB INCHARGES:";
char *str11 = "DR. GIRIJA J. & ";
char *str12 = "PROF. CHAITRA K.";
char *str13 = "********************************************* MENU *********************************************";
char *str14 = "Press (1) : Create a Block";
char *str15 = "Press (2) : Tamper with a Block";
char *str16 = "Press (3) : Distribution of a Block";
char *str17 = "Press (4) : When do you need a Blockchain?";
char *str18 = "Press (5) : Quit";
char *str19 = "************************************************************************************************";
char *str20 = "Thank You!";
char *str21 = "CREATION OF A BLOCK";
char *str22 = "Cryptographic Hash of the previous block";
char *str23 = "A Timestamp";
char *str24 = "Transaction Data";
char *str25 = "A block records some or all of the most recent Bitcoin transactions that have not yet entered any prior blocks. Thus, a block";
char *str26 = "is like a page of a ledger or record book. Each time a block is 'completed', it gives way to the next block in the blockchain.";
char *str27 = "------------->";
char *str28 = "( Press 'ENTER' to continue )";
char *str29 = "TAMPER WITH A BLOCK";
char *str30 = "Hash: ";
char *str31 = "Previous Hash: ";
char *str32 = "1Z8F";
char *str33 = "0000";
char *str34 = "6BQ1";
char *str35 = "3H4Q";
char *str36 = "H62Y";
char *str37 = "Uh, that's not right!";
char *str38 = "Here, we have a chain of 3 blocks. As you can see, each block has a hash and hash of the previous block.";
char *str39 = "So, block 3 points to block 2, and block 2 points to block 1.";
char *str40 = "1st block is special. It cannot point to previous block because it's the first one. We call this block, `The Genesis Block`.";
char *str41 = "1";
char *str42 = "2";
char *str43 = "3";
char *str44 = "Now, lets say that you tamper with the 2nd block, this causes the hash of the block to change as well.";
char *str45 = "In turn, that will make block 3 and all following block invalid because they no longer store a valid hash of the previous block.";
char *str46 = "So, changing a single block will make all following blocks invalid.";
char *str47 = "DISTRIBUTION OF A BLOCK";
char *str48 = "Blockchain uses peer to peer network and everyone is allowed to join.";
char *str49 = "When someone joins this network, he gets the full copy of the blockchain.";
char *str50 = "When a new block is created, each node will verify and add the block to their own blockchain (if it is not tampered).";
char *str51 = "All the nodes in this network creates consensus. They agree about what blocks are valid and which aren't.";
char *str52 = "Blocks that are tampered with, will be rejected by other nodes in the network.";
char *str53 = "WHEN DO YOU NEED A BLOCKCHAIN?";
char *str54 = "yes";
char *str55 = "no";
char *str56 = "Do you need a";
char *str57 = "database?";
char *str58 = "Do many people";
char *str59 = "need to write to it?";
char *str60 = "Do those people ";
char *str61 = "trust each other?";
char *str62 = "Do they have one person ";
char *str63 = "in common they trust?";
char *str64 = "you don't need a";
char *str65 = "blockchain.";
char *str66 = "YOU NEED A";
char *str67 = "BLOCKCHAIN!";
char *str68 = "(Press 'Enter' and Left Click to continue)";
char *str69 = "(Press 'd' to switch to dark mode)";
char *str70 = "(Press 'Enter' to switch to default mode)";
char *str71 = "BLOCK IN A BLOCKCHAIN";
char *str72 = "REPRESENTATION OF A LEDGER";

//color cube
#define ARRAY_COUNT( array ) (sizeof( array ) / (sizeof( array[0] ) * (sizeof( array ) != sizeof(void*) || sizeof( array[0] ) <= sizeof(void*))))

GLfloat vertices[][3]={-0.25,-0.25,-0.25,    -0.25,0.25,-0.25,    0.25,0.25,-0.25,   0.25,-0.25,-0.25,
                        -0.25,-0.25,0.25,     -0.25,0.25,0.25,     0.25,0.25,0.25,    0.25,-0.25,0.25};
GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0},
                       {0.0,0.0,1.0},{1.0,0.0,1.0},{1.0,1.0,1.0},{0.0,1.0,1.0}};
static GLfloat theta[]={0.0,0.0,0.0};
GLint axis =1;
float r,g,b,x,y;
bool check=true;

void *font = GLUT_BITMAP_HELVETICA_18;

//keyboard functions - 11
void myKey(unsigned char key, int x, int y);
void myKeyNew(unsigned char key, int x, int y);
void myKey1(unsigned char key, int x, int y);
void myKey1r(unsigned char key, int x, int y);
void myKey1New(unsigned char key, int x, int y);
void myKey2(unsigned char key, int x, int y);
void myKey2New(unsigned char key, int x, int y);
void myKey3(unsigned char key, int x, int y);
void myKey3New(unsigned char key, int x, int y);
void myKey4(unsigned char key, int x, int y);
void myKey4New(unsigned char key, int x, int y);

//the display functions - 17
void display1();
void display2();
void display2New();//dark mode
void display3();
void display3New();//dark mode
void display3intermediate();
void display3intermediateNew();//dark mode
void display4();
void display4New();//dark mode
void display4intermediate();
void display4intermediateNew();//dark mode
void display5();
void display5New();//dark mode
void display6();
void display6New();//dark mode
void display7();
void display7New();//dark mode

//Function to display the cube in 'Block in a Blockchain' page
void mouses(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        check=true;

        x = mousex;
        y = 725-mousey;

        r=(rand()%9)/8;
        g=(rand()%9)/8;
        b=(rand()%9)/8;
    }
    else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)//undo(clear)the drawing
    {
        glClearColor(1, 1, 1, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        check = false;
    }
    glutPostRedisplay();
}

//function to draw ellipse
void DrawEllipse(float x, float y, float radiusX, float radiusY)
{
	int i;
	//gl translate is used for the purpose of multiplying the current matrix with the translation matrix: takes 3 parameters: x,y & z
	glTranslatef(x, y, 0.0f);
	//Translation is an extreme core function in case of the ellipse construction
	glBegin(GL_LINE_LOOP);
	for (i = 0;i < 360;i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(cos(rad)*radiusX, sin(rad)*radiusY);
	}
	glEnd();
}

//Functions to display colour cube
void polygon(int a, int b,int c,int d)
{
  //draw a polygon via list of vertices
  glBegin(GL_POLYGON);
  glColor3fv(colors[a]);
  glVertex3fv(vertices[a]);
  glColor3fv(colors[b]);
  glVertex3fv(vertices[b]);
  glColor3fv(colors[c]);
  glVertex3fv(vertices[c]);
  glColor3fv(colors[d]);
  glVertex3fv(vertices[d]);
  glEnd();
}
void colorcube(void)
{
    //map vertices to faces
    polygon(0,3,2,1);
    polygon(2,3,7,6);
    polygon(0,4,7,3);
    polygon(1,2,6,5);
    polygon(4,5,6,7);
    polygon(0,1,5,4);
}

void spinCube()
{
   // idle callback,spin cube 2 degreees about selected axis
   theta[axis] +=0.1;
   if(theta[axis]>360.0)
   theta[axis]-= 360.0;
   glutPostRedisplay();
}
void mouse(int btn,int state,int x,int y)
{
    //mouse calback ,select an axis about which to rotate
    if(btn== GLUT_LEFT_BUTTON && state ==GLUT_DOWN) axis =0;//x
    if(btn== GLUT_MIDDLE_BUTTON && state ==GLUT_DOWN) axis =1;//y
    if(btn== GLUT_RIGHT_BUTTON && state ==GLUT_DOWN) axis =2;//z
}


//keyboard function-called by display2()
void myKey(unsigned char key, int x, int y)
{
	if (key == 'd') //Hit d to go to dark Menu Page
	{
		glutDisplayFunc(display2New);
		display2New();
		glEnd();
		glFlush();
	}
	if (key == '1') //option 1 is choosen from the Menu
	{
		glutDisplayFunc(display3);
		display3();
		glEnd();
		glFlush();
	}
	if (key == '2') //option 2 is choosen from the Menu
	{
		glutDisplayFunc(display4);
		display4();
		glEnd();
		glFlush();
	}
	if (key == '3') //option 3 is choosen from the Menu
	{
		glutDisplayFunc(display5);
		display5();
		glEnd();
		glFlush();
	}
	if (key == '4') //option 4 is choosen from the Menu
	{
		glutDisplayFunc(display6);
		display6();
		glEnd();
		glFlush();
	}
	if (key == (char)27 || key == '5') //Hit ESC or 5 to Exit
	{
		glClearColor(1, 1, 1, 0); //background color
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-10, 10, -10, 10);
		glColor3f(0, 0, 0); // foreground color
		glRasterPos2f(-1, 0);
		for (i = 0;i<strlen(str20);i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str20[i]); //Thank You!
		glFlush();
		for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay
		exit(0); //quit
	}
}

//keyboard function-called by display2New()
void myKeyNew(unsigned char key, int x, int y)
{
	if (key == (char)13) //Hit Enter to go to Menu Page
	{
		glutDisplayFunc(display2);
		display2();
		glEnd();
		glFlush();
	}
	if (key == '1') //option 1 is choosen from the Menu
	{
		glutDisplayFunc(display3New);
		display3New();
		glEnd();
		glFlush();
	}
	if (key == '2') //option 2 is choosen from the Menu
	{
		glutDisplayFunc(display4New);
		display4New();
		glEnd();
		glFlush();
	}
	if (key == '3') //option 3 is choosen from the Menu
	{
		glutDisplayFunc(display5New);
		display5New();
		glEnd();
		glFlush();
	}
	if (key == '4') //option 4 is choosen from the Menu
	{
		glutDisplayFunc(display6New);
		display6New();
		glEnd();
		glFlush();
	}
	if (key == (char)27 || key == '5') //Hit ESC or 5 to Exit
	{
		glClearColor(0, 0, 0, 0); //background color
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-10, 10, -10, 10);
		glColor3f(1, 1, 1); // foreground color
		glRasterPos2f(-1, 0);
		for (i = 0;i<strlen(str20);i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str20[i]); //Thank You!
		glFlush();
		for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay
		exit(0); //quit
	}
}

//keyboard function-called by display1()
void myKey1(unsigned char key, int x, int y)
{
	if (key == (char)13) //Hit Enter to go to Menu Page
	{
		glutDisplayFunc(display2);
		display2();
		glEnd();
		glFlush();
	}
	if (key == 'd')
    {
        glutDisplayFunc(display2New);//dark mode
		display2New();
		glEnd();
		glFlush();
    }

}

//keyboard function-called by cube rotate
void myKey1r(unsigned char key, int x, int y)
{
	if (key == (char)13) //Hit Enter to go to Menu Page
	{
		glutDisplayFunc(display2);
		display2();
		glEnd();
		glFlush();
	}
}

//keyboard function-called by display3intermediateNew()
void myKey1New(unsigned char key, int x, int y)
{
	if (key == (char)13) //Hit Enter to go to Menu Page
	{
		glutDisplayFunc(display2New);
		display2New();
		glEnd();
		glFlush();
	}
}

//keyboard function-called by display4()
void myKey2(unsigned char key, int x, int y)
{
    if (key == (char)13) //Hit Enter to go to second tamper page Page
	{
		glutDisplayFunc(display4intermediate);
		display4intermediate();
		glEnd();
		glFlush();
	}
}

//keyboard function-called by display4New()
void myKey2New(unsigned char key, int x, int y)
{
    if (key == (char)13) //Hit Enter to go to second tamper page Page
	{
		glutDisplayFunc(display4intermediateNew);
		display4intermediateNew();
		glEnd();
		glFlush();
	}
}

//keyboard function-called by display3()
void myKey3(unsigned char key, int x, int y)
{
	if (key == (char)13) //Hit Enter to go to Menu Page
	{
		glutDisplayFunc(display2);
		display2();
		glEnd();
		glFlush();
	}
    if (key == '6') //To display rotating cube
    {
        //glutReshapeFunc(myReshape);
        glutDisplayFunc(display3intermediate);
        glutIdleFunc(spinCube);
        glutMouseFunc(mouse);
        glutKeyboardFunc(myKey1r);
        glEnd();
        glFlush();
        glutPostRedisplay();
    }
}

//keyboard function-called by display3New()
void myKey3New(unsigned char key, int x, int y)
{
	if (key == (char)13) //Hit Enter to go to Menu Page
	{
		glutDisplayFunc(display2New);
		display2New();
		glEnd();
		glFlush();
	}
    if (key == '6') //To display rotating cube
    {
        //glutReshapeFunc(myReshape);
        glutDisplayFunc(display3intermediateNew);
        glutIdleFunc(spinCube);
        glutMouseFunc(mouse);
        glutKeyboardFunc(myKey1New);
        glEnd();
        glFlush();
    }
}

//keyboard function-called by display4intermediate()
void myKey4(unsigned char key, int x, int y)
{
	if(key == (char)13)
    {
        glutDisplayFunc(display7);
        glutMouseFunc(mouses);
        glutKeyboardFunc(myKey1r);
        glEnd();
        glFlush();
    }
}

//keyboard function-called by display4intermediateNew()
void myKey4New(unsigned char key, int x, int y)
{
	if(key == (char)13)
    {
        glutDisplayFunc(display7New);
        glutMouseFunc(mouses);
        glutKeyboardFunc(myKey1New);
        glEnd();
        glFlush();
    }
}


//display First page : DETAILS
void display1()
{
	glClearColor(0, 1, 0, 0); //background color
	glClear(GL_COLOR_BUFFER_BIT); //to clear the previous color frame buffer
	glMatrixMode(GL_PROJECTION); //the coordinates need to be projected
	glLoadIdentity(); //replace the current matrix with the identity matrix
	gluOrtho2D(-10, 10, -10, 10); //gl ortho is used to position the object into the right position in cartesian coordinates
	glColor3f(1, 0, 0); // foreground color
	glRasterPos2f(-5.3, 7); // to convert the positions into a raster form
	for (i = 0;i < strlen(str1);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]); //BANGALORE INSTITUTE OF TECHNOLOGY(BIT), BANGALORE
	glRasterPos2f(-5, 6);
	for (i = 0;i<strlen(str2);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str2[i]); //DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING
	glRasterPos2f(-5, 3);
	for (i = 0;i<strlen(str3);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]); //COMPUTER GRAPHICS AND VISUALIZATION LABORATORY
	glRasterPos2f(-1.5, 1);
	for (i = 0;i<strlen(str4);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str4[i]); //A MINI PROJECT
	glRasterPos2f(-0.5, 0);
	for (i = 0;i<strlen(str5);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str5[i]); //ON
	glRasterPos2f(-3.2, -1);
	for (i = 0;i<strlen(str6);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str6[i]); //IMPLEMENTATION OF BLOCKCHAIN
	glRasterPos2f(-9, -5);
	for (i = 0;i<strlen(str7);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str7[i]); //DESIGNED BY:
	glRasterPos2f(-8.5, -6);
	for (i = 0;i<strlen(str8);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str8[i]); //VISHAL D. BHAT & VISHWADUTT M.S.
	glRasterPos2f(-8.5, -7);
	for (i = 0;i<strlen(str9);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str9[i]); //(1BI17CS176) & (1BI17CS179)
	glRasterPos2f(4.75, -5);
	for (i = 0;i<strlen(str10);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str10[i]); //LAB INCHARGES:
	glRasterPos2f(5.5, -6);
	for (i = 0;i<strlen(str11);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str11[i]); //DR. GIRIJA J.
	glRasterPos2f(5.5, -7);
	for (i = 0;i<strlen(str12);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str12[i]); //PROF. CHAITRA K.
	glColor3f(1, 0, 0);
	glFlush();
	glRasterPos2f(-2.25, -8.5);
	for (i = 0;i<strlen(str28);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str28[i]); // ( Press `ENTER` to continue )
    glRasterPos2f(-2.5, -9.5);
	for (i = 0;i<strlen(str69);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str69[i]); // (Press d to switch to dark mode)
	glFlush();
	glutKeyboardFunc(myKey1);
	glFlush();
}

//display Second page : MENU
void display2()
{
	glClearColor(0, 1, 1, 0); //background color
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glColor3f(0, 0, 0); // foreground color
	glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str13);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str13[i]); //***** MENU *****
	glRasterPos2f(-3, 4);
	for (i = 0;i<strlen(str14);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str14[i]); //Press (1) : Create a Block
	glRasterPos2f(-3, 2);
	for (i = 0;i<strlen(str15);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str15[i]); //Press (2) : Tamper with a Block
	glRasterPos2f(-3, 0);
	for (i = 0;i<strlen(str16);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str16[i]); //Press (3) : Distribution of a Block
	glRasterPos2f(-3, -2);
	for (i = 0;i<strlen(str17);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str17[i]); //Press (4) : When do you need a Blockchain?
	glRasterPos2f(-3, -4);
	for (i = 0;i<strlen(str18);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str18[i]); //Press (5) : Quit
	glRasterPos2f(-8.5, -7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
    glRasterPos2f(-2.25, -9);
	for (i = 0;i<strlen(str69);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str69[i]);//Enter d for dark mode
	glutKeyboardFunc(myKey); //take user input for the menu
	glFlush();
}

//display Second page : MENU dark mode
void display2New()
{
	glClearColor(0, 0, 0, 0); //background color
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glColor3f(1, 1, 1); // foreground color
	glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str13);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str13[i]); //***** MENU *****
	glRasterPos2f(-3, 4);
	for (i = 0;i<strlen(str14);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str14[i]); //Press (1) : Create a Block
	glRasterPos2f(-3, 2);
	for (i = 0;i<strlen(str15);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str15[i]); //Press (2) : Tamper with a Block
	glRasterPos2f(-3, 0);
	for (i = 0;i<strlen(str16);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str16[i]); //Press (3) : Distribution of a Block
	glRasterPos2f(-3, -2);
	for (i = 0;i<strlen(str17);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str17[i]); //Press (4) : When do you need a Blockchain?
	glRasterPos2f(-3, -4);
	for (i = 0;i<strlen(str18);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str18[i]); //Press (5) : Quit
	glRasterPos2f(-8.5, -7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
    glRasterPos2f(-2.25, -9);
	for (i = 0;i<strlen(str70);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str70[i]); //Enter to go to default mode
	glutKeyboardFunc(myKeyNew); //take user input for the menu
	glFlush();
}

// option 1 screen
//creation of block
void display3()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1, 1, 0, 1); //background color of the screen
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]);
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-2, 8);
	for (i = 0;i<strlen(str21);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str21[i]); //CREATION OF A BLOCK
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

//hollow cube display begin
	glBegin(GL_LINES);
	glVertex2f(3, -2);
	glVertex2f(5, -3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, -3);
	glVertex2f(7, -2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(3, -2);
	glVertex2f(3, 2);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, -3);
	glVertex2f(5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, -2);
	glVertex2f(7, 2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(3, 2);
	glVertex2f(5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, 1);
	glVertex2f(7, 2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(3, 2);
	glVertex2f(5, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, 3);
	glVertex2f(7, 2);
	glEnd();
	glFlush();
//hollow cube display end

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay

	glRasterPos2f(-8, 2);
	for (i = 0;i<strlen(str22);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str22[i]); //Cryptographic Hash of the previous block
	glFlush();
	for (int i = 0; i < 25000; i++) for (int j = 0; j < 25000; j++); //delay
	glRasterPos2f(-8, 0);
	for (i = 0;i<strlen(str23);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str23[i]); //A Timestamp
	glFlush();
	for (int i = 0; i < 25000; i++) for (int j = 0; j < 25000; j++); //delay
	glRasterPos2f(-8, -2);
	for (i = 0;i<strlen(str24);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str24[i]); //Transaction Data
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay
	glRasterPos2f(-1.5, 2);
	for (i = 0;i<strlen(str27);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str27[i]); //arrow1
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 12000; j++); //delay
	glRasterPos2f(-1.5, 0);
	for (i = 0;i<strlen(str27);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str27[i]); //arrow2
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 12000; j++); //delay
	glRasterPos2f(-1.5, -2);
	for (i = 0;i<strlen(str27);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str27[i]); //arrow3
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 12000; j++); //delay

//filled cube display begin
	//left
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//green
	glVertex2f(3, -2);
	glVertex2f(5, -3);
	glVertex2f(5, 1);
	glVertex2f(3, 2);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//green
	glVertex2f(5, -3);
	glVertex2f(7, -2);
	glVertex2f(7, 2);
	glVertex2f(5, 1);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//green
	glVertex2f(3, 2);
	glVertex2f(5, 1);
	glVertex2f(7, 2);
	glVertex2f(5, 3);
	glEnd();
	glFlush();

	glColor3f(0, 0, 0);//black

	//border
	glBegin(GL_LINES);
	glVertex2f(3, -2);
	glVertex2f(5, -3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, -3);
	glVertex2f(7, -2);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glVertex2f(3, -2);
	glVertex2f(3, 2);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, -3);
	glVertex2f(5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, -2);
	glVertex2f(7, 2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(3, 2);
	glVertex2f(5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, 1);
	glVertex2f(7, 2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(3, 2);
	glVertex2f(5, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, 3);
	glVertex2f(7, 2);
	glEnd();
	glFlush();
//filled cube display end

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay

	glRasterPos2f(-9, -6);
	for (i = 0;i<strlen(str25);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str25[i]); //A block records some or all of the most recent Bitcoin transactions that have not yet entered any prior blocks. Thus a block
	glRasterPos2f(-9, -7);
	for (i = 0;i<strlen(str26);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str26[i]); //is like a page of a ledger or record book. Each time a block is 'completed', it gives way to the next block in the blockchain.
	glFlush();
	for (int i = 0; i < 40000; i++) for (int j = 0; j < 40000; j++); //delay

	glRasterPos2f(-2.5, -9);
	for (i = 0;i<strlen(str28);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str28[i]); // ( Press `ENTER` to continue )

	glFlush();
	glutKeyboardFunc(myKey3);
	glFlush();
}

// option 1 screen
//creation of block dark mode
void display3New()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(0, 0, 0, 0); //background color of the screen
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]);
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-2, 8);
	for (i = 0;i<strlen(str21);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str21[i]); //CREATION OF A BLOCK
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

//hollow cube display begin
	glBegin(GL_LINES);
	glVertex2f(3, -2);
	glVertex2f(5, -3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, -3);
	glVertex2f(7, -2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(3, -2);
	glVertex2f(3, 2);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, -3);
	glVertex2f(5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, -2);
	glVertex2f(7, 2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(3, 2);
	glVertex2f(5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, 1);
	glVertex2f(7, 2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(3, 2);
	glVertex2f(5, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, 3);
	glVertex2f(7, 2);
	glEnd();
	glFlush();
//hollow cube display end

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay

	glRasterPos2f(-8, 2);
	for (i = 0;i<strlen(str22);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str22[i]); //Cryptographic Hash of the previous block
	glFlush();
	for (int i = 0; i < 25000; i++) for (int j = 0; j < 25000; j++); //delay
	glRasterPos2f(-8, 0);
	for (i = 0;i<strlen(str23);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str23[i]); //A Timestamp
	glFlush();
	for (int i = 0; i < 25000; i++) for (int j = 0; j < 25000; j++); //delay
	glRasterPos2f(-8, -2);
	for (i = 0;i<strlen(str24);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str24[i]); //Transaction Data
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay
	glRasterPos2f(-1.5, 2);
	for (i = 0;i<strlen(str27);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str27[i]); //arrow1
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 12000; j++); //delay
	glRasterPos2f(-1.5, 0);
	for (i = 0;i<strlen(str27);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str27[i]); //arrow2
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 12000; j++); //delay
	glRasterPos2f(-1.5, -2);
	for (i = 0;i<strlen(str27);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str27[i]); //arrow3
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 12000; j++); //delay

//filled cube display begin
	//left
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//green
	glVertex2f(3, -2);
	glVertex2f(5, -3);
	glVertex2f(5, 1);
	glVertex2f(3, 2);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//green
	glVertex2f(5, -3);
	glVertex2f(7, -2);
	glVertex2f(7, 2);
	glVertex2f(5, 1);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//green
	glVertex2f(3, 2);
	glVertex2f(5, 1);
	glVertex2f(7, 2);
	glVertex2f(5, 3);
	glEnd();
	glFlush();

	glColor3f(1, 1, 1);//white

	//border
	glBegin(GL_LINES);
	glVertex2f(3, -2);
	glVertex2f(5, -3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, -3);
	glVertex2f(7, -2);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glVertex2f(3, -2);
	glVertex2f(3, 2);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, -3);
	glVertex2f(5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, -2);
	glVertex2f(7, 2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(3, 2);
	glVertex2f(5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, 1);
	glVertex2f(7, 2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(3, 2);
	glVertex2f(5, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, 3);
	glVertex2f(7, 2);
	glEnd();
	glFlush();
//filled cube display end

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay

	glRasterPos2f(-9, -6);
	for (i = 0;i<strlen(str25);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str25[i]); //A block records some or all of the most recent Bitcoin transactions that have not yet entered any prior blocks. Thus a block
	glRasterPos2f(-9, -7);
	for (i = 0;i<strlen(str26);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str26[i]); //is like a page of a ledger or record book. Each time a block is 'completed', it gives way to the next block in the blockchain.
	glFlush();
	for (int i = 0; i < 40000; i++) for (int j = 0; j < 40000; j++); //delay

	glRasterPos2f(-2.5, -9);
	for (i = 0;i<strlen(str28);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str28[i]); // ( Press `ENTER` to continue )

	glFlush();
	glutKeyboardFunc(myKey3New);
	glFlush();
}

//To display colour cube
void display3intermediate(void)
{
   // display callback , clear frame buffer an Z buffer ,rotate cube and draw , swap buffer.
    // display callback , clear frame buffer an Z buffer ,rotate cube and draw , swap buffer.
   glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1, 1, 0, 0); //background color of the screen
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glColor3f(0,0,0);
   glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
	//glFlush();

	//for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-2, 8);
	for (i = 0;i<strlen(str72);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str72[i]); //REPRESENTATION OF A LEDGER
	//glFlush();
	//glColor3f(0,0,0);
	glRasterPos2f(-1.7, -8.5);
	for (i = 0;i<strlen(str28);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str28[i]); // ( Press `ENTER` to continue )
   glLoadIdentity();
   glRotatef(theta[0],0.50,0.0,0.0);
   glRotatef(theta[1],0.0,0.5,0.0);
   glRotatef(theta[2],0.0,0.0,0.5);
   colorcube();
   glFlush();
   glutSwapBuffers();
   //glutPostRedisplay();
}

//To display colour cube dark mode
void display3intermediateNew(void)
{
   // display callback , clear frame buffer an Z buffer ,rotate cube and draw , swap buffer.
   glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(0, 0, 0, 0); //background color of the screen
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glColor3f(1,1,1);
   glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
	//glFlush();

	//for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-2, 8);
	for (i = 0;i<strlen(str72);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str72[i]); //REPRESENTATION OF A LEDGER
	//glFlush();
	//glColor3f(0,0,0);
	glRasterPos2f(-1.7, -8.5);
	for (i = 0;i<strlen(str28);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str28[i]); // ( Press `ENTER` to continue )
   glLoadIdentity();
   glRotatef(theta[0],0.50,0.0,0.0);
   glRotatef(theta[1],0.0,0.5,0.0);
   glRotatef(theta[2],0.0,0.0,0.5);
   colorcube();
   glFlush();
   glutSwapBuffers();
   glutPostRedisplay();
}


// option 2 screen (part1)
//tamper the data
void display4()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1, 1, 1, 1); //background color of the screen
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-2, 8);
	for (i = 0;i<strlen(str29);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str29[i]); //TAMPER WITH A BLOCK
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

//1st block
	//left-side
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-8.5, 1);
	glVertex2f(-7, 0);
	glVertex2f(-7, 3);
	glVertex2f(-8.5, 4);
	glEnd();

	//top-side
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-8.5, 4);
	glVertex2f(-7, 3);
	glVertex2f(-5.5, 4);
	glVertex2f(-7, 5);
	glEnd();

	//right-side
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-7, 0);
	glVertex2f(-5.5, 1);
	glVertex2f(-5.5, 4);
	glVertex2f(-7, 3);
	glEnd();

	//cube border
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-8.5, 4);
	glVertex2f(-8.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 3);
	glVertex2f(-7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5.5, 4);
	glVertex2f(-5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8.5, 1);
	glVertex2f(-7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 0);
	glVertex2f(-5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8.5, 4);
	glVertex2f(-7, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 3);
	glVertex2f(-5.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8.5, 4);
	glVertex2f(-7, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 5);
	glVertex2f(-5.5, 4);
	glEnd();

	glRasterPos2f(-7, 4);
	for (i = 0;i<strlen(str41);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str41[i]); //1
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

//2nd block
	//left-side
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-1.5, 1);
	glVertex2f(0, 0);
	glVertex2f(0, 3);
	glVertex2f(-1.5, 4);
	glEnd();

	//top-side
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-1.5, 4);
	glVertex2f(0, 3);
	glVertex2f(1.5, 4);
	glVertex2f(0, 5);
	glEnd();

	//right-side
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(0, 0);
	glVertex2f(1.5, 1);
	glVertex2f(1.5, 4);
	glVertex2f(0, 3);
	glEnd();

	//cube border
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(-1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 3);
	glVertex2f(0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.5, 4);
	glVertex2f(1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 1);
	glVertex2f(0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(0, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 3);
	glVertex2f(1.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(0, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 5);
	glVertex2f(1.5, 4);
	glEnd();

	glRasterPos2f(0, 4);
	for (i = 0;i<strlen(str42);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str42[i]); //2
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

//3rd block
	//left-side
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0);//orange
	glVertex2f(8.5, 1);
	glVertex2f(7, 0);
	glVertex2f(7, 3);
	glVertex2f(8.5, 4);
	glEnd();

	//top-side
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0);//orange
	glVertex2f(8.5, 4);
	glVertex2f(7, 3);
	glVertex2f(5.5, 4);
	glVertex2f(7, 5);
	glEnd();

	//right-side
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0);//orange
	glVertex2f(7, 0);
	glVertex2f(5.5, 1);
	glVertex2f(5.5, 4);
	glVertex2f(7, 3);
	glEnd();

	//cube border
	glColor3f(0, 0, 0);//black border
	glBegin(GL_LINES);
	glVertex2f(8.5, 4);
	glVertex2f(8.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 3);
	glVertex2f(7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5.5, 4);
	glVertex2f(5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8.5, 1);
	glVertex2f(7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 0);
	glVertex2f(5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8.5, 4);
	glVertex2f(7, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 3);
	glVertex2f(5.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8.5, 4);
	glVertex2f(7, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 5);
	glVertex2f(5.5, 4);
	glEnd();

	glRasterPos2f(7, 4);
	for (i = 0;i<strlen(str43);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str43[i]); //3
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

	//chain line
	glBegin(GL_LINES);
	glVertex2f(-5.5, 2.5);
	glVertex2f(-1.5, 2.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.5, 2.5);
	glVertex2f(5.5, 2.5);
	glEnd();
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

	//line-divider
	glBegin(GL_LINES);
	glVertex2f(-3.5, -1);
	glVertex2f(-3.5, -5);
	glEnd();

	//line-divider
	glBegin(GL_LINES);
	glVertex2f(3.5, -1);
	glVertex2f(3.5, -5);
	glEnd();

	glFlush();

	glRasterPos2f(-8.5, -2);
	for (i = 0;i<strlen(str30);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str30[i]); //Hash:
	glFlush();

	glRasterPos2f(-8.5, -4);
	for (i = 0;i<strlen(str31);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str31[i]); //Previous Hash:
	glFlush();

	glRasterPos2f(-2.5, -2);
	for (i = 0;i<strlen(str30);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str30[i]); //Hash:
	glFlush();

	glRasterPos2f(-2.5, -4);
	for (i = 0;i<strlen(str31);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str31[i]); //Previous Hash:
	glFlush();

	glRasterPos2f(4.5, -2);
	for (i = 0;i<strlen(str30);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str30[i]); //Hash:
	glFlush();

	glRasterPos2f(4.5, -4);
	for (i = 0;i<strlen(str31);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str31[i]); //Previous Hash:
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

	glRasterPos2f(-5.5, -2);
	for (i = 0;i<strlen(str32);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str32[i]); //1Z8F
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-5.5, -4);
	for (i = 0;i<strlen(str33);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str33[i]); //0000
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(1.5, -2);
	for (i = 0;i<strlen(str35);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str35[i]); //6BQ1
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(1.5, -4);
	for (i = 0;i<strlen(str32);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str32[i]); //1Z8F
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(7.5, -2);
	for (i = 0;i<strlen(str36);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str36[i]); //H62Y
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(7.5, -4);
	for (i = 0;i<strlen(str35);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str35[i]); //6BQ1
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay


	glRasterPos2f(-9, -6.5);
	for (i = 0;i<strlen(str38);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str38[i]); //Here we have a chain of 3 blocks. As you can see, each block has a hash and hash of the previous block.
	glFlush();
	for (int i = 0; i < 50000; i++) for (int j = 0; j < 50000; j++); //delay

	DrawEllipse(8, -4, 1, 0.75); //3rd block hash circle
	glFlush();for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay
	DrawEllipse(-6, 2, 1, 0.75); //2nd block hash circle
	glFlush();for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	//3rd to 2nd arrow
	glBegin(GL_LINES);
	glVertex2f(5, -2);
	glVertex2f(1, 0);
	glEnd();
	glFlush();for (int i = 0; i < 40000; i++) for (int j = 0; j < 40000; j++); //delay

	glRasterPos2f(-11, -5.5);
	for (i = 0;i<strlen(str39);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str39[i]); //So, block number 3 points to block number 2, and number 2 points to number 1.
	glFlush();for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	DrawEllipse(0, -2, 1, 0.75); //2nd block previous hash circle
	glFlush();for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	DrawEllipse(-7, 2, 1, 0.75); //1st block previous hash circle
	glFlush();for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	//2nd to 1st arrow
	glBegin(GL_LINES);
	glVertex2f(6, -2);
	glVertex2f(1, 0);
	glEnd();

	glFlush();for (int i = 0; i < 30000; i++) for (int j = 0; j < 30000; j++); //delay

	glRasterPos2f(-4, -6.5);
	for (i = 0;i<strlen(str40);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str40[i]);
		;
	 //1st block is special. It cannot point to previous block because it's the first one. We call this block, `The Genesis Block`.
	glFlush();
    for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++);


	//underline

	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(-0.75, -2.25);
	glVertex2f(0.5, -2.25);
	glEnd();glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(-0.75, -2.45);
	glVertex2f(0.5, -2.45);

	glEnd();
    for (int i = 0; i < 70000; i++) for (int j = 0; j < 60000; j++);

	glRasterPos2f(0, 0);
	glColor3f(0,0,0);
	glRasterPos2f(3.5, -7.5);
	for (i = 0;i<strlen(str28);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str28[i]); // ( Press `ENTER` to continue )

    glutKeyboardFunc(myKey2);
	glFlush();
	glutKeyboardFunc(myKey2);

//	display4intermediate();
}

// option 2 screen (part1)
//tamper the data dark mode
void display4New()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(0, 0, 0, 0); //background color of the screen
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-2, 8);
	for (i = 0;i<strlen(str29);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str29[i]); //TAMPER WITH A BLOCK
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

//1st block
	//left-side
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-8.5, 1);
	glVertex2f(-7, 0);
	glVertex2f(-7, 3);
	glVertex2f(-8.5, 4);
	glEnd();

	//top-side
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-8.5, 4);
	glVertex2f(-7, 3);
	glVertex2f(-5.5, 4);
	glVertex2f(-7, 5);
	glEnd();

	//right-side
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-7, 0);
	glVertex2f(-5.5, 1);
	glVertex2f(-5.5, 4);
	glVertex2f(-7, 3);
	glEnd();

	//cube border
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(-8.5, 4);
	glVertex2f(-8.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 3);
	glVertex2f(-7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5.5, 4);
	glVertex2f(-5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8.5, 1);
	glVertex2f(-7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 0);
	glVertex2f(-5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8.5, 4);
	glVertex2f(-7, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 3);
	glVertex2f(-5.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8.5, 4);
	glVertex2f(-7, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 5);
	glVertex2f(-5.5, 4);
	glEnd();

	glRasterPos2f(-7, 4);
	for (i = 0;i<strlen(str41);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str41[i]); //1
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

//2nd block
	//left-side
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-1.5, 1);
	glVertex2f(0, 0);
	glVertex2f(0, 3);
	glVertex2f(-1.5, 4);
	glEnd();

	//top-side
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-1.5, 4);
	glVertex2f(0, 3);
	glVertex2f(1.5, 4);
	glVertex2f(0, 5);
	glEnd();

	//right-side
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(0, 0);
	glVertex2f(1.5, 1);
	glVertex2f(1.5, 4);
	glVertex2f(0, 3);
	glEnd();

	//cube border
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(-1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 3);
	glVertex2f(0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.5, 4);
	glVertex2f(1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 1);
	glVertex2f(0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(0, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 3);
	glVertex2f(1.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(0, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 5);
	glVertex2f(1.5, 4);
	glEnd();

	glRasterPos2f(0, 4);
	for (i = 0;i<strlen(str42);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str42[i]); //2
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

//3rd block
	//left-side
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0);//orange
	glVertex2f(8.5, 1);
	glVertex2f(7, 0);
	glVertex2f(7, 3);
	glVertex2f(8.5, 4);
	glEnd();

	//top-side
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0);//orange
	glVertex2f(8.5, 4);
	glVertex2f(7, 3);
	glVertex2f(5.5, 4);
	glVertex2f(7, 5);
	glEnd();

	//right-side
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0);//orange
	glVertex2f(7, 0);
	glVertex2f(5.5, 1);
	glVertex2f(5.5, 4);
	glVertex2f(7, 3);
	glEnd();

	//cube border
	glColor3f(1, 1, 1);//black border
	glBegin(GL_LINES);
	glVertex2f(8.5, 4);
	glVertex2f(8.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 3);
	glVertex2f(7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5.5, 4);
	glVertex2f(5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8.5, 1);
	glVertex2f(7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 0);
	glVertex2f(5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8.5, 4);
	glVertex2f(7, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 3);
	glVertex2f(5.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8.5, 4);
	glVertex2f(7, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 5);
	glVertex2f(5.5, 4);
	glEnd();

	glRasterPos2f(7, 4);
	for (i = 0;i<strlen(str43);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str43[i]); //3
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

	//chain line
	glBegin(GL_LINES);
	glVertex2f(-5.5, 2.5);
	glVertex2f(-1.5, 2.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.5, 2.5);
	glVertex2f(5.5, 2.5);
	glEnd();
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

	//line-divider
	glBegin(GL_LINES);
	glVertex2f(-3.5, -1);
	glVertex2f(-3.5, -5);
	glEnd();

	//line-divider
	glBegin(GL_LINES);
	glVertex2f(3.5, -1);
	glVertex2f(3.5, -5);
	glEnd();

	glFlush();

	glRasterPos2f(-8.5, -2);
	for (i = 0;i<strlen(str30);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str30[i]); //Hash:
	glFlush();

	glRasterPos2f(-8.5, -4);
	for (i = 0;i<strlen(str31);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str31[i]); //Previous Hash:
	glFlush();

	glRasterPos2f(-2.5, -2);
	for (i = 0;i<strlen(str30);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str30[i]); //Hash:
	glFlush();

	glRasterPos2f(-2.5, -4);
	for (i = 0;i<strlen(str31);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str31[i]); //Previous Hash:
	glFlush();

	glRasterPos2f(4.5, -2);
	for (i = 0;i<strlen(str30);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str30[i]); //Hash:
	glFlush();

	glRasterPos2f(4.5, -4);
	for (i = 0;i<strlen(str31);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str31[i]); //Previous Hash:
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

	glRasterPos2f(-5.5, -2);
	for (i = 0;i<strlen(str32);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str32[i]); //1Z8F
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-5.5, -4);
	for (i = 0;i<strlen(str33);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str33[i]); //0000
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(1.5, -2);
	for (i = 0;i<strlen(str35);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str35[i]); //6BQ1
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(1.5, -4);
	for (i = 0;i<strlen(str32);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str32[i]); //1Z8F
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(7.5, -2);
	for (i = 0;i<strlen(str36);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str36[i]); //H62Y
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(7.5, -4);
	for (i = 0;i<strlen(str35);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str35[i]); //6BQ1
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay


	glRasterPos2f(-9, -6.5);
	for (i = 0;i<strlen(str38);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str38[i]); //Here we have a chain of 3 blocks. As you can see, each block has a hash and hash of the previous block.
	glFlush();
	for (int i = 0; i < 50000; i++) for (int j = 0; j < 50000; j++); //delay

	DrawEllipse(8, -4, 1, 0.75); //3rd block hash circle
	glFlush();for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay
	DrawEllipse(-6, 2, 1, 0.75); //2nd block hash circle
	glFlush();for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	//3rd to 2nd arrow
	glBegin(GL_LINES);
	glVertex2f(5, -2);
	glVertex2f(1, 0);
	glEnd();
	glFlush();for (int i = 0; i < 40000; i++) for (int j = 0; j < 40000; j++); //delay

	glRasterPos2f(-11, -5.5);
	for (i = 0;i<strlen(str39);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str39[i]); //So, block number 3 points to block number 2, and number 2 points to number 1.
	glFlush();for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	DrawEllipse(0, -2, 1, 0.75); //2nd block previous hash circle
	glFlush();for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	DrawEllipse(-7, 2, 1, 0.75); //1st block previous hash circle
	glFlush();for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	//2nd to 1st arrow
	glBegin(GL_LINES);
	glVertex2f(6, -2);
	glVertex2f(1, 0);
	glEnd();

	glFlush();for (int i = 0; i < 30000; i++) for (int j = 0; j < 30000; j++); //delay

	glRasterPos2f(-4, -6.5);
	for (i = 0;i<strlen(str40);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str40[i]);
		;
	 //1st block is special. It cannot point to previous block because it's the first one. We call this block, `The Genesis Block`.
	glFlush();
    for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++);


	//underline

	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(-0.75, -2.25);
	glVertex2f(0.5, -2.25);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(-0.75, -2.45);
	glVertex2f(0.5, -2.45);

	glEnd();
    for (int i = 0; i < 70000; i++) for (int j = 0; j < 60000; j++);

	glRasterPos2f(0, 0);
	glColor3f(1,1,1);
	glRasterPos2f(3.5, -7.5);
	for (i = 0;i<strlen(str28);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str28[i]); // ( Press `ENTER` to continue )

    glutKeyboardFunc(myKey2New);
	glFlush();
	glutKeyboardFunc(myKey2New);

//	display4intermediate();
}

// option 2 screen (part2)
void display4intermediate()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1, 1, 1, 1); //background color of the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
	glFlush();

	glRasterPos2f(-2, 8);
	for (i = 0;i<strlen(str29);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str29[i]); //TAMPER WITH A BLOCK
	glFlush();

//1st block
	//left-side
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-8.5, 1);
	glVertex2f(-7, 0);
	glVertex2f(-7, 3);
	glVertex2f(-8.5, 4);
	glEnd();

	//top-side
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-8.5, 4);
	glVertex2f(-7, 3);
	glVertex2f(-5.5, 4);
	glVertex2f(-7, 5);
	glEnd();

	//right-side
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-7, 0);
	glVertex2f(-5.5, 1);
	glVertex2f(-5.5, 4);
	glVertex2f(-7, 3);
	glEnd();

	//cube border
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-8.5, 4);
	glVertex2f(-8.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 3);
	glVertex2f(-7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5.5, 4);
	glVertex2f(-5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8.5, 1);
	glVertex2f(-7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 0);
	glVertex2f(-5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8.5, 4);
	glVertex2f(-7, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 3);
	glVertex2f(-5.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8.5, 4);
	glVertex2f(-7, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 5);
	glVertex2f(-5.5, 4);
	glEnd();

	glRasterPos2f(-7, 4);
	for (i = 0;i<strlen(str41);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str41[i]); //1
	glFlush();

//2nd block
	//left-side
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-1.5, 1);
	glVertex2f(0, 0);
	glVertex2f(0, 3);
	glVertex2f(-1.5, 4);
	glEnd();

	//top-side
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-1.5, 4);
	glVertex2f(0, 3);
	glVertex2f(1.5, 4);
	glVertex2f(0, 5);
	glEnd();

	//right-side
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(0, 0);
	glVertex2f(1.5, 1);
	glVertex2f(1.5, 4);
	glVertex2f(0, 3);
	glEnd();

	//cube border
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(-1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 3);
	glVertex2f(0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.5, 4);
	glVertex2f(1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 1);
	glVertex2f(0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(0, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 3);
	glVertex2f(1.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(0, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 5);
	glVertex2f(1.5, 4);
	glEnd();

	glRasterPos2f(0, 4);
	for (i = 0;i<strlen(str42);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str42[i]); //2
	glFlush();

//3rd block
	//left-side
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0);//orange
	glVertex2f(8.5, 1);
	glVertex2f(7, 0);
	glVertex2f(7, 3);
	glVertex2f(8.5, 4);
	glEnd();

	//top-side
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0);//orange
	glVertex2f(8.5, 4);
	glVertex2f(7, 3);
	glVertex2f(5.5, 4);
	glVertex2f(7, 5);
	glEnd();

	//right-side
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0);//orange
	glVertex2f(7, 0);
	glVertex2f(5.5, 1);
	glVertex2f(5.5, 4);
	glVertex2f(7, 3);
	glEnd();

	//cube border
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(8.5, 4);
	glVertex2f(8.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 3);
	glVertex2f(7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5.5, 4);
	glVertex2f(5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8.5, 1);
	glVertex2f(7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 0);
	glVertex2f(5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8.5, 4);
	glVertex2f(7, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 3);
	glVertex2f(5.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8.5, 4);
	glVertex2f(7, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 5);
	glVertex2f(5.5, 4);
	glEnd();

	glRasterPos2f(7, 4);
	for (i = 0;i<strlen(str43);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str43[i]); //3
	glFlush();

	//chain line
	glBegin(GL_LINES);
	glVertex2f(-5.5, 2.5);
	glVertex2f(-1.5, 2.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.5, 2.5);
	glVertex2f(5.5, 2.5);
	glEnd();
	glFlush();

	//line-divider
	glBegin(GL_LINES);
	glVertex2f(-3.5, -1);
	glVertex2f(-3.5, -5);
	glEnd();

	//line-divider
	glBegin(GL_LINES);
	glVertex2f(3.5, -1);
	glVertex2f(3.5, -5);
	glEnd();

	glFlush();

	glRasterPos2f(-8.5, -2);
	for (i = 0;i<strlen(str30);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str30[i]); //Hash:
	glFlush();

	glRasterPos2f(-8.5, -4);
	for (i = 0;i<strlen(str31);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str31[i]); //Previous Hash:
	glFlush();

	glRasterPos2f(-2.5, -2);
	for (i = 0;i<strlen(str30);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str30[i]); //Hash:
	glFlush();

	glRasterPos2f(-2.5, -4);
	for (i = 0;i<strlen(str31);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str31[i]); //Previous Hash:
	glFlush();

	glRasterPos2f(4.5, -2);
	for (i = 0;i<strlen(str30);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str30[i]); //Hash:
	glFlush();

	glRasterPos2f(4.5, -4);
	for (i = 0;i<strlen(str31);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str31[i]); //Previous Hash:
	glFlush();

	glRasterPos2f(-5.5, -2);
	for (i = 0;i<strlen(str32);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str32[i]); //1Z8F
	glFlush();

	glRasterPos2f(-5.5, -4);
	for (i = 0;i<strlen(str33);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str33[i]); //0000
	glFlush();

	glRasterPos2f(1.5, -2);
	for (i = 0;i<strlen(str35);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str35[i]); //6BQ1
	glFlush();

	glRasterPos2f(1.5, -4);
	for (i = 0;i<strlen(str32);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str32[i]); //1Z8F
	glFlush();

	glRasterPos2f(7.5, -2);
	for (i = 0;i<strlen(str36);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str36[i]); //H62Y
	glFlush();

	glRasterPos2f(7.5, -4);
	for (i = 0;i<strlen(str35);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str35[i]); //6BQ1
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	//right-side
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//red
	glVertex2f(0, 0);
	glVertex2f(1.5, 1);
	glVertex2f(1.5, 4);
	glVertex2f(0, 3);
	glEnd();

	//cube border
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(-1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 3);
	glVertex2f(0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.5, 4);
	glVertex2f(1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 1);
	glVertex2f(0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(0, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 3);
	glVertex2f(1.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(0, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 5);
	glVertex2f(1.5, 4);
	glEnd();

	glFlush();

	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2f(1.0, -1.75);
	glVertex2f(3.0, -1.75);
	glEnd();

	glRasterPos2f(1.5, -1.25);
	for (i = 0;i<strlen(str34);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str34[i]); //6BQ1
	glFlush();

	glColor3f(0, 0, 0);
	glRasterPos2f(-9, -6.5);
	for (i = 0;i<strlen(str44);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str44[i]); //Now lets say that you tamper with the 2nd block, this causes the hash of the block to change as well.
	glFlush();

	glFlush();for (int i = 0; i < 50000; i++) for (int j = 0; j < 50000; j++); //delay

	glColor3f(1, 0, 0);
	DrawEllipse(8, -4, 1, 0.75); //3rd block hash circle
	glFlush();for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay
	glRasterPos2f(-2, -1.5);
	for (i = 0;i<strlen(str37);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str37[i]);
	glFlush();

	glColor3f(0, 0, 0);
	glRasterPos2f(-17, -3.5);
	for (i = 0;i<strlen(str45);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str45[i]); //In turn, that will make block 3 and all following block invalid because they no longer store a valid hash of the previous block.
	glFlush();

	for (int i = 0; i < 80000; i++) for (int j = 0; j < 70000; j++); //delay

	glRasterPos2f(-17, -4.5);
	for (i = 0;i<strlen(str46);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str46[i]); //So changing a single block will make all following blocks invalid.
	glFlush();

	for (int i = 0; i < 60000; i++) for (int j = 0; j < 60000; j++); //delay

	glRasterPos2f(-10, -5.5);
	for (i = 0;i<strlen(str68);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str68[i]); // ( Press ENTER and Left Click to continue )

    glutKeyboardFunc(myKey4);
	glFlush();
}

// option 2 screen (part2) dark mode
void display4intermediateNew()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(0, 0, 0, 0); //background color of the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
	glFlush();

	glRasterPos2f(-2, 8);
	for (i = 0;i<strlen(str29);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str29[i]); //TAMPER WITH A BLOCK
	glFlush();

//1st block
	//left-side
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-8.5, 1);
	glVertex2f(-7, 0);
	glVertex2f(-7, 3);
	glVertex2f(-8.5, 4);
	glEnd();

	//top-side
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-8.5, 4);
	glVertex2f(-7, 3);
	glVertex2f(-5.5, 4);
	glVertex2f(-7, 5);
	glEnd();

	//right-side
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-7, 0);
	glVertex2f(-5.5, 1);
	glVertex2f(-5.5, 4);
	glVertex2f(-7, 3);
	glEnd();

	//cube border
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(-8.5, 4);
	glVertex2f(-8.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 3);
	glVertex2f(-7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5.5, 4);
	glVertex2f(-5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8.5, 1);
	glVertex2f(-7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 0);
	glVertex2f(-5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8.5, 4);
	glVertex2f(-7, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 3);
	glVertex2f(-5.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8.5, 4);
	glVertex2f(-7, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 5);
	glVertex2f(-5.5, 4);
	glEnd();

	glRasterPos2f(-7, 4);
	for (i = 0;i<strlen(str41);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str41[i]); //1
	glFlush();

//2nd block
	//left-side
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-1.5, 1);
	glVertex2f(0, 0);
	glVertex2f(0, 3);
	glVertex2f(-1.5, 4);
	glEnd();

	//top-side
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-1.5, 4);
	glVertex2f(0, 3);
	glVertex2f(1.5, 4);
	glVertex2f(0, 5);
	glEnd();

	//right-side
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(0, 0);
	glVertex2f(1.5, 1);
	glVertex2f(1.5, 4);
	glVertex2f(0, 3);
	glEnd();

	//cube border
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(-1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 3);
	glVertex2f(0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.5, 4);
	glVertex2f(1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 1);
	glVertex2f(0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(0, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 3);
	glVertex2f(1.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(0, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 5);
	glVertex2f(1.5, 4);
	glEnd();

	glRasterPos2f(0, 4);
	for (i = 0;i<strlen(str42);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str42[i]); //2
	glFlush();

//3rd block
	//left-side
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0);//orange
	glVertex2f(8.5, 1);
	glVertex2f(7, 0);
	glVertex2f(7, 3);
	glVertex2f(8.5, 4);
	glEnd();

	//top-side
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0);//orange
	glVertex2f(8.5, 4);
	glVertex2f(7, 3);
	glVertex2f(5.5, 4);
	glVertex2f(7, 5);
	glEnd();

	//right-side
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0);//orange
	glVertex2f(7, 0);
	glVertex2f(5.5, 1);
	glVertex2f(5.5, 4);
	glVertex2f(7, 3);
	glEnd();

	//cube border
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(8.5, 4);
	glVertex2f(8.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 3);
	glVertex2f(7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5.5, 4);
	glVertex2f(5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8.5, 1);
	glVertex2f(7, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 0);
	glVertex2f(5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8.5, 4);
	glVertex2f(7, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 3);
	glVertex2f(5.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8.5, 4);
	glVertex2f(7, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 5);
	glVertex2f(5.5, 4);
	glEnd();

	glRasterPos2f(7, 4);
	for (i = 0;i<strlen(str43);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str43[i]); //3
	glFlush();

	//chain line
	glBegin(GL_LINES);
	glVertex2f(-5.5, 2.5);
	glVertex2f(-1.5, 2.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.5, 2.5);
	glVertex2f(5.5, 2.5);
	glEnd();
	glFlush();

	//line-divider
	glBegin(GL_LINES);
	glVertex2f(-3.5, -1);
	glVertex2f(-3.5, -5);
	glEnd();

	//line-divider
	glBegin(GL_LINES);
	glVertex2f(3.5, -1);
	glVertex2f(3.5, -5);
	glEnd();

	glFlush();

	glRasterPos2f(-8.5, -2);
	for (i = 0;i<strlen(str30);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str30[i]); //Hash:
	glFlush();

	glRasterPos2f(-8.5, -4);
	for (i = 0;i<strlen(str31);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str31[i]); //Previous Hash:
	glFlush();

	glRasterPos2f(-2.5, -2);
	for (i = 0;i<strlen(str30);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str30[i]); //Hash:
	glFlush();

	glRasterPos2f(-2.5, -4);
	for (i = 0;i<strlen(str31);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str31[i]); //Previous Hash:
	glFlush();

	glRasterPos2f(4.5, -2);
	for (i = 0;i<strlen(str30);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str30[i]); //Hash:
	glFlush();

	glRasterPos2f(4.5, -4);
	for (i = 0;i<strlen(str31);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str31[i]); //Previous Hash:
	glFlush();

	glRasterPos2f(-5.5, -2);
	for (i = 0;i<strlen(str32);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str32[i]); //1Z8F
	glFlush();

	glRasterPos2f(-5.5, -4);
	for (i = 0;i<strlen(str33);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str33[i]); //0000
	glFlush();

	glRasterPos2f(1.5, -2);
	for (i = 0;i<strlen(str35);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str35[i]); //6BQ1
	glFlush();

	glRasterPos2f(1.5, -4);
	for (i = 0;i<strlen(str32);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str32[i]); //1Z8F
	glFlush();

	glRasterPos2f(7.5, -2);
	for (i = 0;i<strlen(str36);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str36[i]); //H62Y
	glFlush();

	glRasterPos2f(7.5, -4);
	for (i = 0;i<strlen(str35);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str35[i]); //6BQ1
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	//right-side
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//red
	glVertex2f(0, 0);
	glVertex2f(1.5, 1);
	glVertex2f(1.5, 4);
	glVertex2f(0, 3);
	glEnd();

	//cube border
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(-1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 3);
	glVertex2f(0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.5, 4);
	glVertex2f(1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 1);
	glVertex2f(0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(1.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(0, 3);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 3);
	glVertex2f(1.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.5, 4);
	glVertex2f(0, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 5);
	glVertex2f(1.5, 4);
	glEnd();

	glFlush();

	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2f(1.0, -1.75);
	glVertex2f(3.0, -1.75);
	glEnd();

	glRasterPos2f(1.5, -1.25);
	for (i = 0;i<strlen(str34);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str34[i]); //6BQ1
	glFlush();

	glColor3f(1, 1, 1);
	glRasterPos2f(-9, -6.5);
	for (i = 0;i<strlen(str44);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str44[i]); //Now lets say that you tamper with the 2nd block, this causes the hash of the block to change as well.
	glFlush();

	glFlush();for (int i = 0; i < 50000; i++) for (int j = 0; j < 50000; j++); //delay

	glColor3f(1, 0, 0);
	DrawEllipse(8, -4, 1, 0.75); //3rd block hash circle
	glFlush();for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay
	glRasterPos2f(-2, -1.5);
	for (i = 0;i<strlen(str37);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str37[i]);
	glFlush();

	glColor3f(1, 1, 1);
	glRasterPos2f(-17, -3.5);
	for (i = 0;i<strlen(str45);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str45[i]); //In turn, that will make block 3 and all following block invalid because they no longer store a valid hash of the previous block.
	glFlush();

	for (int i = 0; i < 80000; i++) for (int j = 0; j < 70000; j++); //delay

	glRasterPos2f(-17, -4.5);
	for (i = 0;i<strlen(str46);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str46[i]); //So changing a single block will make all following blocks invalid.
	glFlush();

	for (int i = 0; i < 60000; i++) for (int j = 0; j < 60000; j++); //delay

	glRasterPos2f(-10, -5.5);
	for (i = 0;i<strlen(str68);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str68[i]); // ( Press ENTER and Left Click to continue )

    glutKeyboardFunc(myKey4New);
	glFlush();
}

// option 3 screen
void display5()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1, 1, 1, 1); //background color of the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0, 0, 0);
	glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-2.25, 8);
	for (i = 0;i<strlen(str47);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str47[i]); //DISTRIBUTION OF A BLOCK
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-9, -3);
	for (i = 0;i < strlen(str48);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str48[i]); //Blockchain uses peer to peer network and everyone is allowed to join.
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay


//COMPUTER1
	//monitor
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//red
	glVertex2f(-7, 3);
	glVertex2f(-5, 3);
	glVertex2f(-5, 5.5);
	glVertex2f(-7, 5.5);
	glEnd();

	//screen
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);//black
	glVertex2f(-6.9, 3.2);
	glVertex2f(-5.1, 3.2);
	glVertex2f(-5.1, 5.3);
	glVertex2f(-6.9, 5.3);
	glEnd();

	//keyboard
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//red
	glVertex2f(-7, 2.75);
	glVertex2f(-5, 2.75);
	glVertex2f(-4.5, 2);
	glVertex2f(-7.5, 2);
	glEnd();
	glFlush();

//COMPUTER2
	//monitor
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//red
	glVertex2f(5, 3);
	glVertex2f(7, 3);
	glVertex2f(7, 5.5);
	glVertex2f(5, 5.5);
	glEnd();

	//screen
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);//black
	glVertex2f(5.1, 3.2);
	glVertex2f(6.9, 3.2);
	glVertex2f(6.9, 5.3);
	glVertex2f(5.1, 5.3);
	glEnd();

	//keyboard
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//red
	glVertex2f(5, 2.75);
	glVertex2f(7, 2.75);
	glVertex2f(7.5, 2);
	glVertex2f(4.5, 2);
	glEnd();

	glFlush();
	for (int i = 0; i < 60000; i++) for (int j = 0; j < 60000; j++); //delay

	glColor3f(0,0,0);
	glRasterPos2f(-9, -4);
	for (i = 0;i < strlen(str49);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str49[i]); //When someone joins this network, he gets the full copy of the blockchain.
	glFlush();
	for (int i = 0; i < 30000; i++) for (int j = 0; j < 30000; j++); //delay

//block1 of computer1
	//left
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//Sky blue
	glVertex2f(-8, -0.5);
	glVertex2f(-7.5, -1);
	glVertex2f(-7.5, 0);
	glVertex2f(-8, 0.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-7.5, 0);
	glVertex2f(-7.5, -1);
	glVertex2f(-7, -0.5);
	glVertex2f(-7, 0.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-8, 0.5);
	glVertex2f(-7.5, 0);
	glVertex2f(-7, 0.5);
	glVertex2f(-7.5, 1);
	glEnd();
	glFlush();

	glColor3f(0, 0, 0);
	//border
	glBegin(GL_LINES);
	glVertex2f(-8, -0.5);
	glVertex2f(-7.5, -1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7.5, -1);
	glVertex2f(-7.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7.5, 0);
	glVertex2f(-8, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8, 0.5);
	glVertex2f(-8, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7.5, -1);
	glVertex2f(-7, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, -0.5);
	glVertex2f(-7, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 0.5);
	glVertex2f(-7.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 0.5);
	glVertex2f(-7.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7.5, 1);
	glVertex2f(-8, 0.5);
	glEnd();
	glFlush();


//block1 of computer2
	//left
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(3, -0.5);
	glVertex2f(3.5, -1);
	glVertex2f(3.5, 0);
	glVertex2f(3, 0.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(3.5, 0);
	glVertex2f(3.5, -1);
	glVertex2f(4, -0.5);
	glVertex2f(4, 0.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(3, 0.5);
	glVertex2f(3.5, 0);
	glVertex2f(4, 0.5);
	glVertex2f(3.5, 1);
	glEnd();
	glFlush();

	glColor3f(0, 0, 0);
	//border
	glBegin(GL_LINES);
	glVertex2f(3, -0.5);
	glVertex2f(3.5, -1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(3.5, -1);
	glVertex2f(3.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(3.5, 0);
	glVertex2f(3, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(3, 0.5);
	glVertex2f(3, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(3.5, -1);
	glVertex2f(4, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(4, -0.5);
	glVertex2f(4, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(4, 0.5);
	glVertex2f(3.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(4, 0.5);
	glVertex2f(3.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(3.5, 1);
	glVertex2f(3, 0.5);
	glEnd();
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

//block2 of computer1
	//left
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-6, -0.5);
	glVertex2f(-5.5, -1);
	glVertex2f(-5.5, 0);
	glVertex2f(-6, 0.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-5.5, 0);
	glVertex2f(-5.5, -1);
	glVertex2f(-5, -0.5);
	glVertex2f(-5, 0.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-6, 0.5);
	glVertex2f(-5.5, 0);
	glVertex2f(-5, 0.5);
	glVertex2f(-5.5, 1);
	glEnd();
	glFlush();
	glColor3f(0, 0, 0);

	//border
	glBegin(GL_LINES);
	glVertex2f(-6, -0.5);
	glVertex2f(-5.5, -1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5.5, -1);
	glVertex2f(-5.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5.5, 0);
	glVertex2f(-6, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-6, 0.5);
	glVertex2f(-6, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5.5, -1);
	glVertex2f(-5, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5, -0.5);
	glVertex2f(-5, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5, 0.5);
	glVertex2f(-5.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5, 0.5);
	glVertex2f(-5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5.5, 1);
	glVertex2f(-6, 0.5);
	glEnd();
	glFlush();


//block2 of computer2
	//left
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(5, -0.5);
	glVertex2f(5.5, -1);
	glVertex2f(5.5, 0);
	glVertex2f(5, 0.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(5.5, 0);
	glVertex2f(5.5, -1);
	glVertex2f(6, -0.5);
	glVertex2f(6, 0.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(5, 0.5);
	glVertex2f(5.5, 0);
	glVertex2f(6, 0.5);
	glVertex2f(5.5, 1);
	glEnd();
	glFlush();

	glColor3f(0, 0, 0);
	//border
	glBegin(GL_LINES);
	glVertex2f(5, -0.5);
	glVertex2f(5.5, -1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5.5, -1);
	glVertex2f(5.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5.5, 0);
	glVertex2f(5, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, 0.5);
	glVertex2f(5, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5.5, -1);
	glVertex2f(6, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(6, -0.5);
	glVertex2f(6, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(6, 0.5);
	glVertex2f(5.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(6, 0.5);
	glVertex2f(5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5.5, 1);
	glVertex2f(5, 0.5);
	glEnd();
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

	//line connecting block1 and block2 of computer1
	glBegin(GL_LINES);
	glVertex2f(-7, 0);
	glVertex2f(-6, 0);
	glEnd();

	//line connecting block1 and block2 of computer2
	glBegin(GL_LINES);
	glVertex2f(4, 0);
	glVertex2f(5, 0);
	glEnd();

	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

//The BIG BLOCK
	//left
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(-0.5, 3.5);
	glVertex2f(0.0, 3);
	glVertex2f(0.0, 4);
	glVertex2f(-0.5, 4.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(0, 4);
	glVertex2f(0, 3);
	glVertex2f(0.5, 3.5);
	glVertex2f(0.5, 4.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(-0.5, 4.5);
	glVertex2f(0, 4);
	glVertex2f(0.5, 4.5);
	glVertex2f(0, 5);
	glEnd();
	glFlush();

	glColor3f(0, 0, 0);
	//border
	glBegin(GL_LINES);
	glVertex2f(-0.5, 3.5);
	glVertex2f(0.0, 3.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.0, 3.0);
	glVertex2f(0.0, 4.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.0, 4.0);
	glVertex2f(-0.5, 4.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-0.5, 4.5);
	glVertex2f(-0.5, 3.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.0, 3.0);
	glVertex2f(0.5, 3.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.5, 3.5);
	glVertex2f(0.5, 4.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.5, 4.5);
	glVertex2f(0.0, 4.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.5, 4.5);
	glVertex2f(0.0, 5.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.0, 5.0);
	glVertex2f(-0.5, 4.5);
	glEnd();
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 40000; j++); //delay

	glColor3f(0, 0, 0);
	glRasterPos2f(-9, -5);
	for (i = 0;i < strlen(str50);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str50[i]); //when someone creates a new block, each node will verify and adds the block to their own blockchain.
	glFlush();
	for (int i = 0; i < 30000; i++) for (int j = 0; j < 30000; j++); //delay

//magic is happening here :P
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);//white
	glVertex2f(-1, 2.5);
	glVertex2f(1, 2.5);
	glVertex2f(1, 5.5);
	glVertex2f(-1, 5.5);
	glEnd();

	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay


//block3 of computer1
	//left
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(-4, -0.5);
	glVertex2f(-3.5, -1);
	glVertex2f(-3.5, 0);
	glVertex2f(-4, 0.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(-3.5, 0);
	glVertex2f(-3.5, -1);
	glVertex2f(-3, -0.5);
	glVertex2f(-3, 0.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(-4, 0.5);
	glVertex2f(-3.5, 0);
	glVertex2f(-3, 0.5);
	glVertex2f(-3.5, 1);
	glEnd();
	glFlush();

	glColor3f(0, 0, 0);
	//border
	glBegin(GL_LINES);
	glVertex2f(-4, -0.5);
	glVertex2f(-3.5, -1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3.5, -1);
	glVertex2f(-3.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3.5, 0);
	glVertex2f(-4, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-4, 0.5);
	glVertex2f(-4, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3.5, -1);
	glVertex2f(-3, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3, -0.5);
	glVertex2f(-3, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3, 0.5);
	glVertex2f(-3.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3, 0.5);
	glVertex2f(-3.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3.5, 1);
	glVertex2f(-4, 0.5);
	glEnd();
	glFlush();

//block3 of computer2
	//left
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(7, -0.5);
	glVertex2f(7.5, -1);
	glVertex2f(7.5, 0);
	glVertex2f(7, 0.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(7.5, 0);
	glVertex2f(7.5, -1);
	glVertex2f(8, -0.5);
	glVertex2f(8, 0.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(7, 0.5);
	glVertex2f(7.5, 0);
	glVertex2f(8, 0.5);
	glVertex2f(7.5, 1);
	glEnd();
	glFlush();

	glColor3f(0, 0, 0);
	//border
	glBegin(GL_LINES);
	glVertex2f(7, -0.5);
	glVertex2f(7.5, -1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7.5, -1);
	glVertex2f(7.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7.5, 0);
	glVertex2f(7, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 0.5);
	glVertex2f(7, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7.5, -1);
	glVertex2f(8, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8, -0.5);
	glVertex2f(8, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8, 0.5);
	glVertex2f(7.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8, 0.5);
	glVertex2f(7.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7.5, 1);
	glVertex2f(7, 0.5);
	glEnd();
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	//line connecting block2 and block3 of computer1
	glBegin(GL_LINES);
	glVertex2f(-5, 0);
	glVertex2f(-4, 0);
	glEnd();

	//line connecting block2 and block3 of computer2
	glBegin(GL_LINES);
	glVertex2f(6, 0);
	glVertex2f(7, 0);
	glEnd();

	glFlush();
	for (int i = 0; i < 60000; i++) for (int j = 0; j < 50000; j++); //delay

	glColor3f(0, 0, 0);
	glRasterPos2f(-9, -6);
	for (i = 0;i < strlen(str51);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str51[i]); //All the nodes in this network creates consensus. They agree about what blocks are valid and which aren't
	glFlush();
	for (int i = 0; i < 70000; i++) for (int j = 0; j < 70000; j++); //delay

	glColor3f(0, 0, 0);
	glRasterPos2f(-9, -7);
	for (i = 0;i < strlen(str52);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str52[i]); //Blocks that are tampered with will be rejected by other nodes in the network.
	glFlush();

	for (int i = 0; i < 45000; i++) for (int j = 0; j < 45000; j++); //delay;;;;;;;

	glColor3f(0, 0, 0);
	glRasterPos2f(-2.5, -9);
	for (i = 0;i < strlen(str28);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str28[i]); //( Press `ENTER` to continue )
    glutKeyboardFunc(myKey1r);
	glFlush();

}

// option 3 screen dark mode
void display5New()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(0, 0, 0, 0); //background color of the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1, 1, 1);
	glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-2.25, 8);
	for (i = 0;i<strlen(str47);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str47[i]); //DISTRIBUTION OF A BLOCK
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-9, -3);
	for (i = 0;i < strlen(str48);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str48[i]); //Blockchain uses peer to peer network and everyone is allowed to join.
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay


//COMPUTER1
	//monitor
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//red
	glVertex2f(-7, 3);
	glVertex2f(-5, 3);
	glVertex2f(-5, 5.5);
	glVertex2f(-7, 5.5);
	glEnd();

	//screen
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);//black
	glVertex2f(-6.9, 3.2);
	glVertex2f(-5.1, 3.2);
	glVertex2f(-5.1, 5.3);
	glVertex2f(-6.9, 5.3);
	glEnd();

	//keyboard
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//red
	glVertex2f(-7, 2.75);
	glVertex2f(-5, 2.75);
	glVertex2f(-4.5, 2);
	glVertex2f(-7.5, 2);
	glEnd();
	glFlush();

//COMPUTER2
	//monitor
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//red
	glVertex2f(5, 3);
	glVertex2f(7, 3);
	glVertex2f(7, 5.5);
	glVertex2f(5, 5.5);
	glEnd();

	//screen
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);//black
	glVertex2f(5.1, 3.2);
	glVertex2f(6.9, 3.2);
	glVertex2f(6.9, 5.3);
	glVertex2f(5.1, 5.3);
	glEnd();

	//keyboard
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);//red
	glVertex2f(5, 2.75);
	glVertex2f(7, 2.75);
	glVertex2f(7.5, 2);
	glVertex2f(4.5, 2);
	glEnd();

	glFlush();
	for (int i = 0; i < 60000; i++) for (int j = 0; j < 60000; j++); //delay

	glColor3f(1,1,1);
	glRasterPos2f(-9, -4);
	for (i = 0;i < strlen(str49);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str49[i]); //When someone joins this network, he gets the full copy of the blockchain.
	glFlush();
	for (int i = 0; i < 30000; i++) for (int j = 0; j < 30000; j++); //delay

//block1 of computer1
	//left
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//Sky blue
	glVertex2f(-8, -0.5);
	glVertex2f(-7.5, -1);
	glVertex2f(-7.5, 0);
	glVertex2f(-8, 0.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-7.5, 0);
	glVertex2f(-7.5, -1);
	glVertex2f(-7, -0.5);
	glVertex2f(-7, 0.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(-8, 0.5);
	glVertex2f(-7.5, 0);
	glVertex2f(-7, 0.5);
	glVertex2f(-7.5, 1);
	glEnd();
	glFlush();

	glColor3f(1, 1, 1);
	//border
	glBegin(GL_LINES);
	glVertex2f(-8, -0.5);
	glVertex2f(-7.5, -1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7.5, -1);
	glVertex2f(-7.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7.5, 0);
	glVertex2f(-8, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8, 0.5);
	glVertex2f(-8, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7.5, -1);
	glVertex2f(-7, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, -0.5);
	glVertex2f(-7, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 0.5);
	glVertex2f(-7.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 0.5);
	glVertex2f(-7.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7.5, 1);
	glVertex2f(-8, 0.5);
	glEnd();
	glFlush();


//block1 of computer2
	//left
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(3, -0.5);
	glVertex2f(3.5, -1);
	glVertex2f(3.5, 0);
	glVertex2f(3, 0.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(3.5, 0);
	glVertex2f(3.5, -1);
	glVertex2f(4, -0.5);
	glVertex2f(4, 0.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0.196078, 0.6, 0.8);//skyblue
	glVertex2f(3, 0.5);
	glVertex2f(3.5, 0);
	glVertex2f(4, 0.5);
	glVertex2f(3.5, 1);
	glEnd();
	glFlush();

	glColor3f(1, 1, 1);
	//border
	glBegin(GL_LINES);
	glVertex2f(3, -0.5);
	glVertex2f(3.5, -1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(3.5, -1);
	glVertex2f(3.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(3.5, 0);
	glVertex2f(3, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(3, 0.5);
	glVertex2f(3, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(3.5, -1);
	glVertex2f(4, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(4, -0.5);
	glVertex2f(4, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(4, 0.5);
	glVertex2f(3.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(4, 0.5);
	glVertex2f(3.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(3.5, 1);
	glVertex2f(3, 0.5);
	glEnd();
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

//block2 of computer1
	//left
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-6, -0.5);
	glVertex2f(-5.5, -1);
	glVertex2f(-5.5, 0);
	glVertex2f(-6, 0.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-5.5, 0);
	glVertex2f(-5.5, -1);
	glVertex2f(-5, -0.5);
	glVertex2f(-5, 0.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(-6, 0.5);
	glVertex2f(-5.5, 0);
	glVertex2f(-5, 0.5);
	glVertex2f(-5.5, 1);
	glEnd();
	glFlush();
	glColor3f(1, 1, 1);

	//border
	glBegin(GL_LINES);
	glVertex2f(-6, -0.5);
	glVertex2f(-5.5, -1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5.5, -1);
	glVertex2f(-5.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5.5, 0);
	glVertex2f(-6, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-6, 0.5);
	glVertex2f(-6, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5.5, -1);
	glVertex2f(-5, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5, -0.5);
	glVertex2f(-5, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5, 0.5);
	glVertex2f(-5.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5, 0.5);
	glVertex2f(-5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-5.5, 1);
	glVertex2f(-6, 0.5);
	glEnd();
	glFlush();


//block2 of computer2
	//left
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(5, -0.5);
	glVertex2f(5.5, -1);
	glVertex2f(5.5, 0);
	glVertex2f(5, 0.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(5.5, 0);
	glVertex2f(5.5, -1);
	glVertex2f(6, -0.5);
	glVertex2f(6, 0.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0.96, 0.80, 0.69);//flesh
	glVertex2f(5, 0.5);
	glVertex2f(5.5, 0);
	glVertex2f(6, 0.5);
	glVertex2f(5.5, 1);
	glEnd();
	glFlush();

	glColor3f(1, 1, 1);
	//border
	glBegin(GL_LINES);
	glVertex2f(5, -0.5);
	glVertex2f(5.5, -1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5.5, -1);
	glVertex2f(5.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5.5, 0);
	glVertex2f(5, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5, 0.5);
	glVertex2f(5, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5.5, -1);
	glVertex2f(6, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(6, -0.5);
	glVertex2f(6, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(6, 0.5);
	glVertex2f(5.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(6, 0.5);
	glVertex2f(5.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5.5, 1);
	glVertex2f(5, 0.5);
	glEnd();
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

	//line connecting block1 and block2 of computer1
	glBegin(GL_LINES);
	glVertex2f(-7, 0);
	glVertex2f(-6, 0);
	glEnd();

	//line connecting block1 and block2 of computer2
	glBegin(GL_LINES);
	glVertex2f(4, 0);
	glVertex2f(5, 0);
	glEnd();

	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 15000; j++); //delay

//The BIG BLOCK
	//left
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(-0.5, 3.5);
	glVertex2f(0.0, 3);
	glVertex2f(0.0, 4);
	glVertex2f(-0.5, 4.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(0, 4);
	glVertex2f(0, 3);
	glVertex2f(0.5, 3.5);
	glVertex2f(0.5, 4.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(-0.5, 4.5);
	glVertex2f(0, 4);
	glVertex2f(0.5, 4.5);
	glVertex2f(0, 5);
	glEnd();
	glFlush();

	glColor3f(1, 1, 1);
	//border
	glBegin(GL_LINES);
	glVertex2f(-0.5, 3.5);
	glVertex2f(0.0, 3.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.0, 3.0);
	glVertex2f(0.0, 4.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.0, 4.0);
	glVertex2f(-0.5, 4.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-0.5, 4.5);
	glVertex2f(-0.5, 3.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.0, 3.0);
	glVertex2f(0.5, 3.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.5, 3.5);
	glVertex2f(0.5, 4.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.5, 4.5);
	glVertex2f(0.0, 4.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.5, 4.5);
	glVertex2f(0.0, 5.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.0, 5.0);
	glVertex2f(-0.5, 4.5);
	glEnd();
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 40000; j++); //delay

	glColor3f(1, 1, 1);
	glRasterPos2f(-9, -5);
	for (i = 0;i < strlen(str50);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str50[i]); //when someone creates a new block, each node will verify and adds the block to their own blockchain.
	glFlush();
	for (int i = 0; i < 30000; i++) for (int j = 0; j < 30000; j++); //delay

//magic is happening here :P
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);//black
	glVertex2f(-1, 2.5);
	glVertex2f(1, 2.5);
	glVertex2f(1, 5.5);
	glVertex2f(-1, 5.5);
	glEnd();

	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay


//block3 of computer1
	//left
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(-4, -0.5);
	glVertex2f(-3.5, -1);
	glVertex2f(-3.5, 0);
	glVertex2f(-4, 0.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(-3.5, 0);
	glVertex2f(-3.5, -1);
	glVertex2f(-3, -0.5);
	glVertex2f(-3, 0.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(-4, 0.5);
	glVertex2f(-3.5, 0);
	glVertex2f(-3, 0.5);
	glVertex2f(-3.5, 1);
	glEnd();
	glFlush();

	glColor3f(1, 1, 1);
	//border
	glBegin(GL_LINES);
	glVertex2f(-4, -0.5);
	glVertex2f(-3.5, -1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3.5, -1);
	glVertex2f(-3.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3.5, 0);
	glVertex2f(-4, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-4, 0.5);
	glVertex2f(-4, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3.5, -1);
	glVertex2f(-3, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3, -0.5);
	glVertex2f(-3, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3, 0.5);
	glVertex2f(-3.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3, 0.5);
	glVertex2f(-3.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-3.5, 1);
	glVertex2f(-4, 0.5);
	glEnd();
	glFlush();

//block3 of computer2
	//left
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(7, -0.5);
	glVertex2f(7.5, -1);
	glVertex2f(7.5, 0);
	glVertex2f(7, 0.5);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(7.5, 0);
	glVertex2f(7.5, -1);
	glVertex2f(8, -0.5);
	glVertex2f(8, 0.5);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);//green
	glVertex2f(7, 0.5);
	glVertex2f(7.5, 0);
	glVertex2f(8, 0.5);
	glVertex2f(7.5, 1);
	glEnd();
	glFlush();

	glColor3f(1, 1, 1);
	//border
	glBegin(GL_LINES);
	glVertex2f(7, -0.5);
	glVertex2f(7.5, -1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7.5, -1);
	glVertex2f(7.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7.5, 0);
	glVertex2f(7, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7, 0.5);
	glVertex2f(7, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7.5, -1);
	glVertex2f(8, -0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8, -0.5);
	glVertex2f(8, 0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8, 0.5);
	glVertex2f(7.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(8, 0.5);
	glVertex2f(7.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(7.5, 1);
	glVertex2f(7, 0.5);
	glEnd();
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	//line connecting block2 and block3 of computer1
	glBegin(GL_LINES);
	glVertex2f(-5, 0);
	glVertex2f(-4, 0);
	glEnd();

	//line connecting block2 and block3 of computer2
	glBegin(GL_LINES);
	glVertex2f(6, 0);
	glVertex2f(7, 0);
	glEnd();

	glFlush();
	for (int i = 0; i < 60000; i++) for (int j = 0; j < 50000; j++); //delay

	glColor3f(1, 1, 1);
	glRasterPos2f(-9, -6);
	for (i = 0;i < strlen(str51);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str51[i]); //All the nodes in this network creates consensus. They agree about what blocks are valid and which aren't
	glFlush();
	for (int i = 0; i < 70000; i++) for (int j = 0; j < 70000; j++); //delay

	glColor3f(1, 1, 1);
	glRasterPos2f(-9, -7);
	for (i = 0;i < strlen(str52);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str52[i]); //Blocks that are tampered with will be rejected by other nodes in the network.
	glFlush();

	for (int i = 0; i < 45000; i++) for (int j = 0; j < 45000; j++); //delay;;;;;;;

	glColor3f(1, 1, 1);
	glRasterPos2f(-2.5, -9);
	for (i = 0;i < strlen(str28);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str28[i]); //( Press `ENTER` to continue )
    glutKeyboardFunc(myKey1New);
	glFlush();

}

// option 4 screen
void display6()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1, 1, 1, 1); //background color of the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0, 0, 0);
	glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-2.75, 8);
	for (i = 0;i<strlen(str53);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str53[i]); //WHEN DO YOU NEED A BLOCKCHAIN?
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	//box1
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-9.25, 6.75);
	glVertex2f(-6, 6.75);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-9.25, 4.75);
	glVertex2f(-6, 4.75);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-9.25, 4.75);
	glVertex2f(-9.25, 6.75);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-6, 4.75);
	glVertex2f(-6, 6.75);
	glEnd();
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	glRasterPos2f(-8.7, 6);
	for (i = 0;i<strlen(str56);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str56[i]); //Do you need a
	glRasterPos2f(-8.45, 5.25);
	for (i = 0;i<strlen(str57);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str57[i]); //database?
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	//horizontal line
	glBegin(GL_LINES);
	glVertex2f(-6,5.75);
	glVertex2f(-2,5.75);
	glEnd();
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-4, 6);
	for (i = 0;i<strlen(str55);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str55[i]); //no
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	DrawEllipse(0, 5.75, 2, 1);
	glFlush();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);

	glRasterPos2f(-1.25, 6);
	for (i = 0;i<strlen(str64);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str64[i]); //you don't need a
	glRasterPos2f(-0.75, 5.25);
	for (i = 0;i<strlen(str65);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str65[i]); //blockchain.
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	//vertical line
	glBegin(GL_LINES);
	glVertex2f(-7.625, 4.75);
	glVertex2f(-7.625, 2.75);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	glRasterPos2f(-8.25, 3.75);
	for (i = 0;i<strlen(str54);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str54[i]); //yes

	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay

	//box2
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-9.25, 2.75);
	glVertex2f(-6, 2.75);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-9.25, 0.75);
	glVertex2f(-6, 0.75);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-9.25, 0.75);
	glVertex2f(-9.25, 2.75);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-6, 0.75);
	glVertex2f(-6, 2.75);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 30000; j++); //delay

	glRasterPos2f(-8.75, 2);
	for (i = 0;i<strlen(str58);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str58[i]); //Do many people
	glRasterPos2f(-8.9, 1.25);
	for (i = 0;i<strlen(str59);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str59[i]); //need to write to it?
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	//horizontal line
	glBegin(GL_LINES);
	glVertex2f(-6, 1.75);
	glVertex2f(-2, 1.75);
	glEnd();
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-4, 2);
	for (i = 0;i<strlen(str55);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str55[i]); //no
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	DrawEllipse(0, 1.75, 2, 1);
	glFlush();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);

	glRasterPos2f(-1.25, 2);
	for (i = 0;i<strlen(str64);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str64[i]); //you don't need a
	glRasterPos2f(-0.75, 1.25);
	for (i = 0;i<strlen(str65);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str65[i]); //blockchain.
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	//vertical line
	glBegin(GL_LINES);
	glVertex2f(-7.625, 0.75);
	glVertex2f(-7.625, -1.25);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	glRasterPos2f(-8.25, -0.25);
	for (i = 0;i<strlen(str54);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str54[i]); //yes

	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay

	//box3
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-9.25, -1.25);
	glVertex2f(-6, -1.25);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-9.25, -3.25);
	glVertex2f(-6, -3.25);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-9.25, -3.25);
	glVertex2f(-9.25, -1.25);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-6, -3.25);
	glVertex2f(-6, -1.25);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 30000; j++); //delay

	glRasterPos2f(-8.75, -2);
	for (i = 0;i<strlen(str60);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str60[i]); //Do those people
	glRasterPos2f(-8.75, -2.75);
	for (i = 0;i<strlen(str61);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str61[i]); //trust eachother?
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	//vertical line
	glBegin(GL_LINES);
	glVertex2f(-7.625, -3.25);
	glVertex2f(-7.625, -5.25);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	glRasterPos2f(-8.25, -4.25);
	for (i = 0;i<strlen(str54);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str54[i]); //yes

	glFlush();
	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	DrawEllipse(-7.625, -6.25, 2, 1);
	glFlush();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);

	glRasterPos2f(-8.875, -6);
	for (i = 0;i<strlen(str64);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str64[i]); //you don't need a
	glRasterPos2f(-8.375, -6.75);
	for (i = 0;i<strlen(str65);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str65[i]); //blockchain.
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	//horizontal line
	glBegin(GL_LINES);
	glVertex2f(-6, -2.25);
	glVertex2f(-2, -2.25);
	glEnd();
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-4, -2);
	for (i = 0;i<strlen(str55);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str55[i]); //no
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	//box3
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-2, -1.25);
	glVertex2f(2, -1.25);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-2, -3.25);
	glVertex2f(2, -3.25);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(-2, -3.25);
	glVertex2f(-2, -1.25);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);//black
	glVertex2f(2, -3.25);
	glVertex2f(2, -1.25);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 30000; j++); //delay

	glRasterPos2f(-1.75, -2);
	for (i = 0;i<strlen(str62);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str62[i]); //Do they have one person
	glRasterPos2f(-1.75, -2.75);
	for (i = 0;i<strlen(str63);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str63[i]); //in common they trust?
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	//vertical line
	glBegin(GL_LINES);
	glVertex2f(0, -3.25);
	glVertex2f(0, -5.25);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	glRasterPos2f(-0.625, -4.25);
	for (i = 0;i<strlen(str54);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str54[i]); //yes

	glFlush();
	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	DrawEllipse(0, -6.25, 2, 1);
	glFlush();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);

	glRasterPos2f(-1.25, -6);
	for (i = 0;i<strlen(str64);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str64[i]); //you don't need a
	glRasterPos2f(-0.75, -6.75);
	for (i = 0;i<strlen(str65);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str65[i]); //database.
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	//horizontal line
	glBegin(GL_LINES);
	glVertex2f(2, -2.25);
	glVertex2f(5, -2.25);
	glEnd();
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(3.5, -2);
	for (i = 0;i<strlen(str55);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str55[i]); //no
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	DrawEllipse(7, -2.25, 2, 1.25);
	glFlush();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);

	glRasterPos2f(5.75, -2);
	for (i = 0;i<strlen(str66);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str66[i]); //YOU NEED A
	glRasterPos2f(5.75, -2.75);
	for (i = 0;i<strlen(str67);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str67[i]); //BLOCKCHAIN!.
	glFlush();

	for (int i = 0; i < 100000; i++) for (int j = 0; j < 100000; j++); //delay

	glColor3f(0, 0, 0);
	glRasterPos2f(-2.5, -9);
	for (i = 0;i < strlen(str28);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str28[i]); //( Press `ENTER` to continue )
	glutKeyboardFunc(myKey1r);
	glFlush();
}

// option 4 screen dark mode
void display6New()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(0, 0, 0, 0); //background color of the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1, 1, 1);
	glRasterPos2f(-8.5, 7);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-2.75, 8);
	for (i = 0;i<strlen(str53);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str53[i]); //WHEN DO YOU NEED A BLOCKCHAIN?
	glFlush();

	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	//box1
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-9.25, 6.75);
	glVertex2f(-6, 6.75);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-9.25, 4.75);
	glVertex2f(-6, 4.75);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-9.25, 4.75);
	glVertex2f(-9.25, 6.75);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-6, 4.75);
	glVertex2f(-6, 6.75);
	glEnd();
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	glRasterPos2f(-8.7, 6);
	for (i = 0;i<strlen(str56);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str56[i]); //Do you need a
	glRasterPos2f(-8.45, 5.25);
	for (i = 0;i<strlen(str57);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str57[i]); //database?
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	//horizontal line
	glBegin(GL_LINES);
	glVertex2f(-6,5.75);
	glVertex2f(-2,5.75);
	glEnd();
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-4, 6);
	for (i = 0;i<strlen(str55);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str55[i]); //no
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	DrawEllipse(0, 5.75, 2, 1);
	glFlush();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);

	glRasterPos2f(-1.25, 6);
	for (i = 0;i<strlen(str64);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str64[i]); //you don't need a
	glRasterPos2f(-0.75, 5.25);
	for (i = 0;i<strlen(str65);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str65[i]); //blockchain.
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	//vertical line
	glBegin(GL_LINES);
	glVertex2f(-7.625, 4.75);
	glVertex2f(-7.625, 2.75);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	glRasterPos2f(-8.25, 3.75);
	for (i = 0;i<strlen(str54);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str54[i]); //yes

	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay

	//box2
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-9.25, 2.75);
	glVertex2f(-6, 2.75);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-9.25, 0.75);
	glVertex2f(-6, 0.75);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-9.25, 0.75);
	glVertex2f(-9.25, 2.75);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-6, 0.75);
	glVertex2f(-6, 2.75);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 30000; j++); //delay

	glRasterPos2f(-8.75, 2);
	for (i = 0;i<strlen(str58);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str58[i]); //Do many people
	glRasterPos2f(-8.9, 1.25);
	for (i = 0;i<strlen(str59);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str59[i]); //need to write to it?
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	//horizontal line
	glBegin(GL_LINES);
	glVertex2f(-6, 1.75);
	glVertex2f(-2, 1.75);
	glEnd();
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-4, 2);
	for (i = 0;i<strlen(str55);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str55[i]); //no
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	DrawEllipse(0, 1.75, 2, 1);
	glFlush();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);

	glRasterPos2f(-1.25, 2);
	for (i = 0;i<strlen(str64);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str64[i]); //you don't need a
	glRasterPos2f(-0.75, 1.25);
	for (i = 0;i<strlen(str65);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str65[i]); //blockchain.
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	//vertical line
	glBegin(GL_LINES);
	glVertex2f(-7.625, 0.75);
	glVertex2f(-7.625, -1.25);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	glRasterPos2f(-8.25, -0.25);
	for (i = 0;i<strlen(str54);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str54[i]); //yes

	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay

	//box3
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-9.25, -1.25);
	glVertex2f(-6, -1.25);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-9.25, -3.25);
	glVertex2f(-6, -3.25);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-9.25, -3.25);
	glVertex2f(-9.25, -1.25);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-6, -3.25);
	glVertex2f(-6, -1.25);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 30000; j++); //delay

	glRasterPos2f(-8.75, -2);
	for (i = 0;i<strlen(str60);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str60[i]); //Do those people
	glRasterPos2f(-8.75, -2.75);
	for (i = 0;i<strlen(str61);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str61[i]); //trust eachother?
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	//vertical line
	glBegin(GL_LINES);
	glVertex2f(-7.625, -3.25);
	glVertex2f(-7.625, -5.25);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	glRasterPos2f(-8.25, -4.25);
	for (i = 0;i<strlen(str54);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str54[i]); //yes

	glFlush();
	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	DrawEllipse(-7.625, -6.25, 2, 1);
	glFlush();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);

	glRasterPos2f(-8.875, -6);
	for (i = 0;i<strlen(str64);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str64[i]); //you don't need a
	glRasterPos2f(-8.375, -6.75);
	for (i = 0;i<strlen(str65);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str65[i]); //blockchain.
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	//horizontal line
	glBegin(GL_LINES);
	glVertex2f(-6, -2.25);
	glVertex2f(-2, -2.25);
	glEnd();
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(-4, -2);
	for (i = 0;i<strlen(str55);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str55[i]); //no
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	//box3
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-2, -1.25);
	glVertex2f(2, -1.25);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-2, -3.25);
	glVertex2f(2, -3.25);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(-2, -3.25);
	glVertex2f(-2, -1.25);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//black
	glVertex2f(2, -3.25);
	glVertex2f(2, -1.25);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 30000; j++); //delay

	glRasterPos2f(-1.75, -2);
	for (i = 0;i<strlen(str62);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str62[i]); //Do they have one person
	glRasterPos2f(-1.75, -2.75);
	for (i = 0;i<strlen(str63);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str63[i]); //in common they trust?
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	//vertical line
	glBegin(GL_LINES);
	glVertex2f(0, -3.25);
	glVertex2f(0, -5.25);
	glEnd();
	glFlush();

	for (int i = 0; i < 30000; i++) for (int j = 0; j < 20000; j++); //delay

	glRasterPos2f(-0.625, -4.25);
	for (i = 0;i<strlen(str54);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str54[i]); //yes

	glFlush();
	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	DrawEllipse(0, -6.25, 2, 1);
	glFlush();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);

	glRasterPos2f(-1.25, -6);
	for (i = 0;i<strlen(str64);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str64[i]); //you don't need a
	glRasterPos2f(-0.75, -6.75);
	for (i = 0;i<strlen(str65);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str65[i]); //database.
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	//horizontal line
	glBegin(GL_LINES);
	glVertex2f(2, -2.25);
	glVertex2f(5, -2.25);
	glEnd();
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(3.5, -2);
	for (i = 0;i<strlen(str55);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str55[i]); //no
	glFlush();

	for (int i = 0; i < 40000; i++) for (int j = 0; j < 30000; j++); //delay

	DrawEllipse(7, -2.25, 2, 1.25);
	glFlush();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);

	glRasterPos2f(5.75, -2);
	for (i = 0;i<strlen(str66);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str66[i]); //YOU NEED A
	glRasterPos2f(5.75, -2.75);
	for (i = 0;i<strlen(str67);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str67[i]); //BLOCKCHAIN!.
	glFlush();

	for (int i = 0; i < 100000; i++) for (int j = 0; j < 100000; j++); //delay

	glColor3f(1, 1, 1);
	glRasterPos2f(-2.5, -9);
	for (i = 0;i < strlen(str28);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str28[i]); //( Press `ENTER` to continue )
	glutKeyboardFunc(myKey1New);
	glFlush();
}

//Block in a Blockchain screen
void display7(void)
{
    glClearColor(0, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,1); // sets the current drawing (foreground) color to blue
    glPointSize(50); // sets the size of points to be drawn (in pixels)

    glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
    glLoadIdentity();//multiply the current matrix by identity matrix
    gluOrtho2D(0, 1250, 0, 750);//sets the parallel(orthographic) projection of the full frame buffer
    glColor3f(0,0,0);
    glRasterPos2f(90, 630);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
	glFlush();

	//for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(500, 670);
	for (i = 0;i<strlen(str71);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str71[i]); //BLOCK IN A BLOCKCHAIN
	glFlush();
    glRasterPos2f(510, 25);
	for (i = 0;i<strlen(str28);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str28[i]);
    glColor3f(0,0,1);

    if(check)
    {
       //glutSolidCube(size);
       glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
       glVertex2i(x,y);   // sets vertex
       glEnd();
    }
    glFlush();     // flushes the frame buffer to the screen
}

//Block in a Blockchain screen - dark mode
void display7New(void)
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,1); // sets the current drawing (foreground) color to blue
    glPointSize(50); // sets the size of points to be drawn (in pixels)

    glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
    glLoadIdentity();//multiply the current matrix by identity matrix
    gluOrtho2D(0, 1250, 0, 750);//sets the parallel(orthographic) projection of the full frame buffer
    glColor3f(1,1,1);
    glRasterPos2f(90, 630);
	for (i = 0;i<strlen(str19);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]); //********************
	glFlush();

	//for (int i = 0; i < 20000; i++) for (int j = 0; j < 10000; j++); //delay

	glRasterPos2f(500, 670);
	for (i = 0;i<strlen(str71);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str71[i]); //BLOCK IN A BLOCKCHAIN
	glFlush();
    glRasterPos2f(510, 25);
	for (i = 0;i<strlen(str28);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str28[i]);
    glColor3f(0,0,1);

    if(check)
    {
       glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
       glVertex2i(x,y);   // sets vertex
       glEnd();
    }
    glFlush();     // flushes the frame buffer to the screen
}


//main function
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Working of BlockChain");
	glutFullScreen();
	glutDisplayFunc(display1); //call first page function
	glutMainLoop();
}
