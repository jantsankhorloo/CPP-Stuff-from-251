#ifndef	PLOT
#define PLOT

#include <GLUT/glut.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

inline int sign (int i)
{
  return i > 0 ? 1 : (i == 0 ? 0 : -1);
}

class Point {
  int x, y;
 public:
  Point (int x, int y) : x(x), y(y) {}
  int getX () const { return x; }
  int getY () const { return y; }
  bool operator< (const Point &a) const { return x < a.x || x == a.x && y < a.y; }
  Point operator- (const Point &a) const { return Point(x - a.x, y - a.y); }
  int dot (const Point &a) const { return x*a.x + y*a.y; }
  int cross (const Point &a) const { return x*a.y - y*a.x; }
  int distanceSquared (const Point &a) const {
    Point u = a - *this;
    return u.dot(u);
  }
  int leftTurn (const Point &b, const Point &c) const {
    return sign((c - b).cross(*this - b));
  }
};


typedef vector<Point> Points;

void graphicsInit (int argc, char **argv, int wsize, int linewidth, 
		   float pointsize);

void menuInit ();

void menu (int value);

void mouse (int button, int buttonState, int x, int y);

void mouseGeneric (int button, int buttonState, int x, int y,
		   Points &inpoints);

Point point (int x, int y);

void display ();

void clearScreen (float *color);

void drawPoints (const Points &pts);

void drawLoop (const Points &points);

void glVertex (const Point &p);

void removePoint (const Point &p, Points &pts);

void readPoints (Points &inpoints);

void readPoints (istream &istr, Points &pts);

void writePoints (ostream &ostr, const Points &pts);

#endif
