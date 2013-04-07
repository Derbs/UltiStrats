#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

void init();
void display();
void drawField();

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


