#ifndef	POINT
#define POINT

class Point {
  int x, y;
 public:
  Point (int x, int y) : x(x), y(y) {}
  Point () : x(-1), y(-1) {}
  int getX () const { return x; }
  int getY () const { return y; }
  bool operator < (const Point &a) const { return x < a.x || x == a.x && y < a.y; }
  Point operator - (const Point &a) const { return Point(x - a.x, y - a.y); }
  int dot (const Point &a) const { return x*a.x + y*a.y; }
  int distanceSquared (const Point &a) const {
    Point u = a - *this;
    return u.dot(u);
  }
};

#endif
