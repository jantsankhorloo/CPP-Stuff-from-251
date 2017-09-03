/*
        This file will not be included when grading.
*/

#ifndef PLOT
#define PLOT

#include "hull.h"
#include <GL/glut.h>
#include <fstream>
#include <iostream>

void graphicsInit(int argc, char **argv, int wsize, int linewidth,
                  float pointsize);

void menuInit();

void menu(int value);

void mouse(int button, int buttonState, int x, int y);

void mouseGeneric(int button, int buttonState, int x, int y, Points &inpoints);

Point point(int x, int y);

void display();

void clearScreen(float *color);

void drawPoints(const Points &pts);

void drawLoop(const Points &pts);

void glVertex(const Point &p);

void removePoint(const Point &p, Points &pts);

int closestPoint(const Point &p, const Points &pts);

void readPoints(Points &inpoints);

void readPoints(istream &istr, Points &pts);

void writePoints(ostream &ostr, const Points &pts);

#endif
