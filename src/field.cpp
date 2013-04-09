#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include "Player.h"
#include "math.h"

void init();
void display();
void drawField();
void drawPlayer(Player* p);

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640,480);
  glutInitWindowPosition(100,100);
  glutCreateWindow("hello");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
}

void init() {
  glEnableClientState(GL_VERTEX_ARRAY); 
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 320.0, 0.0, 240.0, -1.0, 1.0);
}

void display() {
  //intialize objects... extract coords of objects... 

  //create vertex array

  GLint vertices[] = {//the entire field borders.
		      16,100,
		      16,220,
		      304,220,
		      304,100,
		      //the endzone front borders
		      76,100,
		      76,220,
		      244,100,
		      244,220
		     };
  glVertexPointer(2, GL_INT, 0, vertices);
  glClear(GL_COLOR_BUFFER_BIT);  // clear all pixels
  glColor3f(1.0, 1.0, 1.0); // r g b
  drawField();
  Player* test = new Player();
  drawPlayer(test);
  glFlush();
}

void drawField() {
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor3f(0.0,1.0,0.0);
  glDrawArrays(GL_QUADS,0,4);
  glColor3f(1.0,1.0,1.0);
  glLineWidth(4);
  glEnable(GL_LINE_SMOOTH);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
  glDrawArrays(GL_QUADS,0,4);
  glDrawArrays(GL_LINES,4,8);
}

void drawPlayer(Player* p) {
  //takes an x and y location ON THE FIELD in METERS.  
  double xCenter = p->getX();
  double yCenter = p->getY();
  //convert co-ords to actual screen coordinates.  
  xCenter = (xCenter*2)+16;  
  yCenter = (yCenter*2)+100;
  double radius = 1;
  double PI = 3.14159265;
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xCenter, yCenter);
    for(int i = 0; i<18; i++) {
      glVertex2f(xCenter+radius*cos((2*PI*i)/18),yCenter+radius*sin((2*PI*i)/18)); 
    }
    glVertex2f(xCenter+radius,yCenter);
  glEnd();
}


