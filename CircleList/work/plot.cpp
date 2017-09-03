#include "plot.h"
#include <assert.h>

#include <iostream>
using namespace std;


int window1;
Points inpoints;
Points intersectionPoints;

//window configurations and registering callbacks
void graphicsInit (int argc, char **argv, int wsize, int linewidth, 
		   float pointsize)
{
  glutInit(&argc, argv);
  glutInitWindowSize(wsize, wsize);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  window1 = glutCreateWindow("OpenGlut Demo");
  glutMouseFunc(mouse);
  glutDisplayFunc(display);//callback function invoked to refresh window
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, wsize, 0, wsize);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glLineWidth(linewidth);
  glPointSize(pointsize);
  menuInit();// menu displayed on right-click
  glutMainLoop();
}

void menuInit ()
{
  glutCreateMenu(menu);
  glutAddMenuEntry("clear", 1);
  glutAddMenuEntry("read points", 2);
  glutAddMenuEntry("write points", 3);
  glutAddMenuEntry("testing", 4);
  glutAddMenuEntry("exit", 5);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menu (int value)
{
  string name;
  switch (value) {
  case 1:
    inpoints.clear();
    intersectionPoints.clear();
    glutPostRedisplay(); // marks the current window as needing to be redisplayed.
    break;
  case 2:
    readPoints(inpoints);
    glutPostRedisplay();
    break;
  case 3:
    writePoints(cerr, inpoints);
    glutPostRedisplay();
    break;
  case 4:
  {
    cout <<"Enter test1 | test2 | test3| test4\n";
    string name;
    cin >> name;

    if(name == "test1"){
     plot_test1();
      //tester();
    }
    else if(name == "test2")
      plot_test2();
    else if(name == "test3")
      plot_test3();
    else if(name == "test4")
      plot_test4();
    else
      cerr<<"unknown input"<<endl;

     glutPostRedisplay();
  }
break;

  case 5:
    exit(0);
  }
}


void display ()
{
  float white[3] = {1.0f, 1.0f, 1.0f};
  clearScreen(white);
  glColor3f(1.0f, 0.0f, 0.0f); // red
  drawPoints(inpoints);
  glColor3f(0.0f, 0.0f, 0.0f); // black
  drawLoop(inpoints);
  glColor3f(0.0f, 1.0f, 0.0f); // green
  drawPoints(intersectionPoints);

  glFlush();
}

// left click adds point to (global list) inpoints
// shift + left click removes point from inpoints
// alt + left click moves the closest point to the click location
// right click displays context menu

void mouse (int button, int buttonState, int x, int y)
{
  static Point oldp;
  Point p = point(x, y);
  if (button == GLUT_LEFT_BUTTON && buttonState == GLUT_UP)
    return;
  
  if (glutGetModifiers() == GLUT_ACTIVE_SHIFT) {
    if (inpoints.size() != 0);{
      removePoint(p, inpoints);
    }
  }
  else if (button == GLUT_LEFT_BUTTON){
    if(inpoints.size() < 3) inpoints.addBack(p);
    else if (inpoints.size() != 0)
      addPoint(p,inpoints);
  }
  
 else if (buttonState == GLUT_DOWN)
    oldp = p;

  else{
   if (inpoints.size() != 0){
    updatePointLocation(p, inpoints);
  }
}
  
  glutPostRedisplay();
}

Point point (int x, int y)
{
  return Point(x, glutGet(GLUT_WINDOW_WIDTH) - y);
}

void clearScreen (float *color)
{
  glClearColor(color[0], color[1], color[2], color[3]);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void drawPoints (const Points &points)
{
  glBegin(GL_POINTS);
  
  for(int i = 0; i < points.size(); i++) {
  	glVertex(points[i]);
  }
  
  glEnd();
}

void drawLoop (const Points &points)
{
  glBegin(GL_LINE_LOOP);
  
  for(int i = 0; i < points.size(); i++) {
  	glVertex(points[i]);
  }
  
  glEnd();
}

void glVertex (const Point &p)
{
  glVertex2d(p.getX(), p.getY());
}

// read points from file
void readPoints (Points &inpoints)
{
  cerr << "Enter filename: ";
  string name;
  cin >> name;
  ifstream istr(name.c_str());
  if (!istr.good()) return;
  inpoints.clear();
  readPoints(istr, inpoints);
}

void readPoints (istream &istr, Points &pts)
{
  int n;
  istr >> n;
  for (int i = 0; i < n; ++i) {
  double x, y;
  istr >> x >> y;
  pts.addBack(Point(x, y));
  }
}
// print out points
void writePoints (ostream &ostr, const Points &pts)
{
  ostr << pts.size() << endl;
  for (int i = 0; i < pts.size(); i++) {
  	Point p = pts[i];
    ostr << p.getX() << " " << p.getY() << endl;
  }
}

int closestPoint (const Point &p, const Points &pts)
{
  if (pts.size() ==0){
    cerr<<"function called with empty list\n";
    exit(1);
  }

  Point q =  pts[0];
  int ret = 0;
  for (int i = 1; i < pts.size(); ++i) {
    if (p.distanceSquared(pts[i]) < p.distanceSquared(q)){
      q = pts[i];
      ret = i;
    }
  }

  return ret;
}

bool boolint(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
  int x1 = p1.getX(), x2 = p2.getX(), x3 = p3.getX(), x4 = p4.getX();
  int y1 = p1.getY(), y2 = p2.getY(), y3 = p3.getY(), y4 = p4.getY();
  int d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
  if (d == 0) return false; //no intersection
  int pre = (x1 * y2 - y1 * x2), post = (x3 * y4 - y3 * x4);
  int x = (pre * (x3 - x4) - (x1 - x2) * post) / d;
  int y = (pre * (y3 - y4) - (y1 - y2) * post) / d;

  if (x < min(x1, x2) || x > max(x1, x2) ||
    x < min(x3, x4) || x > max(x3, x4)) {
    return false;
  }
  if (y < min(y1, y2) || y > max(y1, y2) ||
    y < min(y3, y4) || y > max(y3, y4)) {
    return false;
  }
  return true;

}

Point intersection1(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
  int x1 = p1.getX(), x2 = p2.getX(), x3 = p3.getX(), x4 = p4.getX();
  int y1 = p1.getY(), y2 = p2.getY(), y3 = p3.getY(), y4 = p4.getY();
  int d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

  int pre = (x1 * y2 - y1 * x2), post = (x3 * y4 - y3 * x4);
  int x = (pre * (x3 - x4) - (x1 - x2) * post) / d;
  int y = (pre * (y3 - y4) - (y1 - y2) * post) / d;

  Point ret(x, y);
  return ret;
}

void addPoint (const Point &p, Points &pts)
{
//TODO 2
  int indexOfClosest = closestPoint(p, pts);
  int prev = p.distanceSquared(pts[indexOfClosest - 1]);
  int next = p.distanceSquared(pts[indexOfClosest + 1]);
  //if (prev > next) {
  //    pts.addAt(indexOfClosest - 1, p);
  //}
  //pts.addAt(indexOfClosest + 1, p);
  pts.addAt(indexOfClosest, p);

  for (int i = 0; i < pts.size() - 1; i++) {
    if (boolint(pts[i + 1], pts[indexOfClosest + 1], pts[0], p) == true) {
      Point intersect = intersection1(pts[i + 1], pts[indexOfClosest + 1], pts[0], p); //lineIntersect
      intersectionPoints.addBack(intersect);
    }
    //else if (boolint(pts[i], pts[i + 1], p, pts[0]) == true) {
    //  Point intersect = intersection1(pts[i], pts[i + 2], p, pts[0]);//lineIntersect
    //  intersectionPoints.addBack(intersect);
    //}
  }
}


void removePoint (const Point &p, Points &pts)
{
  //TODO 3
  int indexOfClosest = closestPoint(p, pts);
  pts.removeAt(indexOfClosest);
}

void updatePointLocation(const Point &p, Points &pts)
{
//TODO 4
  int indexOfClosest = closestPoint(p, pts);
  Point old = pts[indexOfClosest];
  pts.removeAt(indexOfClosest);
  pts.addAt(indexOfClosest, p);
}


void plot_test1(){
  inpoints.clear();
  intersectionPoints.clear();
  cerr<<"test1 inserting without self intersection\n ";

  inpoints.addBack(Point(213, 369));
  inpoints.addBack(Point(346, 149));
  inpoints.addBack(Point(65, 146 ));
  addPoint(Point(342, 272),inpoints);
  addPoint(Point(139, 302),inpoints);
  addPoint(Point(174, 119),inpoints);

  assert(inpoints[0].getX() == 139 && inpoints[0].getY() == 302);
  assert(inpoints[1].getX() ==  213 && inpoints[1].getY() == 369);
  assert(inpoints[2].getX() ==  342 && inpoints[2].getY() == 272);
  assert(inpoints[3].getX() ==  346&& inpoints[3].getY() == 149);
  assert(inpoints[4].getX() == 174 && inpoints[4].getY() == 119 );
  assert(inpoints[5].getX() == 65 && inpoints[5].getY() == 146 );

  cerr<<"test1 passed\n";

}

void plot_test2(){
  inpoints.clear();
  intersectionPoints.clear();

  cerr<<"test2 inserting with self intersection\n ";
  inpoints.addBack(Point(214, 399 ));
  inpoints.addBack(Point(348, 232 ));
  inpoints.addBack(Point(128, 238 ));
  addPoint(Point(159, 225),inpoints);

  intersectionPoints.print();

  assert(intersectionPoints[0].getX() == 162 && intersectionPoints[0].getY()== 237);
  cerr<<"test2 passed\n";


}

void plot_test3(){

  inpoints.clear();
  intersectionPoints.clear();

  cerr<<"test3 delete closest point\n ";
  inpoints.addBack(Point(208, 400 ));
  inpoints.addBack(Point(421, 190  ));
  inpoints.addBack(Point(71, 169));

  removePoint(Point(249, 455), inpoints);
  assert(inpoints[0].getX() ==  421 && inpoints[0].getY() == 190);
  assert(inpoints[1].getX() == 71  && inpoints[1].getY() == 169);

  cerr<<"test3 passed\n";


}

void plot_test4(){

  inpoints.clear();
  intersectionPoints.clear();

  cerr<<"test4 update one point\n ";
  inpoints.addBack(Point(93, 411));
  inpoints.addBack(Point(402, 359 ));
  inpoints.addBack(Point(87, 235));

  updatePointLocation(Point(392,54), inpoints);


  assert(inpoints[0].getX() ==  93 && inpoints[0].getY() == 411);
  assert(inpoints[1].getX() ==  392 && inpoints[1].getY() == 54);
  assert(inpoints[2].getX() ==  87 && inpoints[2].getY() == 235);

  cerr<<"test4 passed\n";

}

int main (int argc, char **argv)
{
  //launch GUI
  int wsize = 500; 
  int linewidth = 1;
  float pointsize = 5.0f;

  graphicsInit(argc, argv, wsize, linewidth, pointsize);

  return 0;
}
