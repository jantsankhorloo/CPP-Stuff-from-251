#ifndef	PLOT
#define PLOT

#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <vector>

#include "point.h"
#include "clist.h"

using namespace std;

typedef CircleList Points;

void graphicsInit (int argc, char **argv, int wsize, int linewidth, 
		   float pointsize);
void menuInit ();

void menu (int value);

void mouse (int button, int buttonState, int x, int y);

Point point (int x, int y);

void display ();

void clearScreen (float *color);

void drawPoints (const Points &pts);

void drawLoop (const Points &pts);

void glVertex (const Point &p);

void readPoints (Points &inpoints);

void readPoints (istream &istr, Points &pts);

void writePoints (ostream &ostr, const Points &pts);

int closestPoint (const Point &p, const Points &pts);

void addPoint (const Point &p, Points &pts); //TODO 2

void removePoint (const Point &p, Points &pts); //TODO 3

void updatePointLocation(const Point &p, Points &pts); //TODO 4

void plot_test1();
void tester();

void plot_test2();

void plot_test3();

void plot_test4();

#endif
