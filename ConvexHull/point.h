#ifndef POINT
#define POINT

#include <vector>
#include <cmath>
using namespace std;

inline int sign(int i) { return i > 0 ? 1 : (i == 0 ? 0 : -1); }

class Point {
  int x, y;

public:
  Point(int x, int y) : x(x), y(y) {}
  int getX() const { return x; }
  int getY() const { return y; }
  bool operator==(const Point &a) const { return x == a.x && y == a.y; }
  bool operator<(const Point &a) const {
    return x < a.x || (x == a.x && y < a.y);
  }
  Point operator-(const Point &a) const { return Point(x - a.x, y - a.y); }

  // dot returns the dot product between the current Point (this) and the passed
  // in Point (a)
  int dot(const Point &a) const {
    // TODO
    return (this->x)*a.x + (this->y)*a.y;
  }

  // cross returns the cross product between the current Point (this) and the
  // passed in Point (a)
  int cross(const Point &a) const {
    // TODO
    return (this->x)*a.y - (this->y)*a.x;
  }
  // distanceSquared returns the square of the distance between this and a
  int distanceSquared(const Point &a) const {
    // TODO
    return pow(this->x - a.x, 2) + pow(this->y - a.y, 2);
  }
  // leftTurn returns 1 if the point c would turn left from the line of this to
  // b.
  int leftTurn(const Point &b, const Point &c) const {
    // TODO
    int position = (b.x - this->x)*(c.y - this->y) - (b.y - this->y)*(c.x - this->x);
    if (position > 0) return 1;
    else if (position < 0) return -1;
    return 0;
  }
};

typedef vector<Point> Points;

#endif
