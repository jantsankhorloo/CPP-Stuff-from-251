/*
        This file will NOT be included when grading.
*/

#include "plot.h"
#include <string.h>

int window1;
Points inpoints, hull;

// These tests are implemented in test.cpp
void test1();
void test2();
void test3();

void graphicsInit(int argc, char **argv, int wsize, int linewidth,
                  float pointsize) {
  glutInit(&argc, argv);
  glutInitWindowSize(wsize, wsize);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  window1 = glutCreateWindow("convex hull");
  glutMouseFunc(mouse);
  glutDisplayFunc(display);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, wsize, 0, wsize);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glLineWidth(linewidth);
  glPointSize(pointsize);
  menuInit();
  glutMainLoop();
}

void menuInit() {
  glutCreateMenu(menu);
  glutAddMenuEntry("clear", 1);
  glutAddMenuEntry("read points", 2);
  glutAddMenuEntry("write points", 3);
  glutAddMenuEntry("exit", 4);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menu(int value) {
  switch (value) {
  case 1:
    inpoints.clear();
    hull.clear();
    break;
  case 2:
    readPoints(inpoints);
    hull.clear();
    defaultHull(inpoints, hull);
    break;
  case 3:
    // Write the points to cerr
    writePoints(cerr, inpoints);
    break;
  case 4:
    // Unfortunately, most versions of GLUT can't actually clean up after
    // themselves :(
    // This means that there will be a memory leak whenever the program exits.
    exit(0);
  }
  glutPostRedisplay();
}

void display() {
  float white[3] = {1.0f, 1.0f, 1.0f};
  clearScreen(white);
  glColor3f(1.0f, 0.0f, 0.0f);
  drawPoints(inpoints);
  glColor3f(0.0f, 0.0f, 0.0f);
  drawLoop(hull);
  drawPoints(hull);
  glFlush();
}

void mouse(int button, int buttonState, int x, int y) {
  mouseGeneric(button, buttonState, x, y, inpoints);
  if (buttonState == GLUT_UP) {
    hull.clear();
    if (!inpoints.empty())
      defaultHull(inpoints, hull);
  }
  glutPostRedisplay();
}

void mouseGeneric(int button, int buttonState, int x, int y, Points &inpoints) {
  Point oldp(-1, -1);
  if (button == GLUT_LEFT_BUTTON && buttonState == GLUT_UP)
    return;
  Point p = point(x, y);
  if (glutGetModifiers() == GLUT_ACTIVE_CTRL)
    removePoint(p, inpoints);
  else if (button == GLUT_LEFT_BUTTON)
    inpoints.push_back(p);
  else if (buttonState == GLUT_DOWN)
    oldp = p;
  else {
    int i = closestPoint(oldp, inpoints);
    if (i != -1)
      inpoints[i] = p;
  }
}

Point point(int x, int y) { return Point(x, glutGet(GLUT_WINDOW_WIDTH) - y); }

void clearScreen(float *color) {
  glClearColor(color[0], color[1], color[2], color[3]);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void drawPoints(const Points &points) {
  glBegin(GL_POINTS);
  for (unsigned int i = 0; i < points.size(); ++i)
    glVertex(points[i]);
  glEnd();
}

void drawLoop(const Points &pts) {
  glBegin(GL_LINE_LOOP);
  for (unsigned int i = 0; i < pts.size(); ++i)
    glVertex(pts[i]);
  glEnd();
}

void glVertex(const Point &p) { glVertex2d(p.getX(), p.getY()); }

void removePoint(const Point &p, Points &pts) {
  int i = closestPoint(p, pts);
  if (i == -1)
    return;
  pts[i] = *(pts.end() - 1);
  pts.pop_back();
}

int closestPoint(const Point &p, const Points &pts) {
  if (pts.empty())
    return -1;
  int d = p.distanceSquared(pts[0]);
  int nd = 0;
  for (unsigned int i = 1; i < pts.size(); ++i) {
    double di = p.distanceSquared(pts[i]);
    if (di < d) {
      d = di;
      nd = i;
    }
  }
  return nd;
}

void readPoints(Points &inpoints) {
  cerr << "Enter filename: ";
  string name;
  cin >> name;
  ifstream istr(name.c_str());
  if (!istr.good())
    return;
  inpoints.clear();
  readPoints(istr, inpoints);
}

void readPoints(istream &istr, Points &pts) {
  int n;
  istr >> n;
  for (int i = 0; i < n; ++i) {
    double x, y;
    istr >> x >> y;
    pts.push_back(Point(x, y));
  }
}

// Writes the X and Y coordinates of the points to the given stream
void writePoints(ostream &ostr, const Points &pts) {
  ostr << pts.size() << endl;
  for (Points::const_iterator p = pts.begin(); p != pts.end(); ++p)
    ostr << p->getX() << " " << p->getY() << endl;
}

int main(int argc, char **argv) {

  // If given an argument, tries to run the test given
  if (argc > 1) {
    if (!strcmp(argv[1], "test1")) {
      test1();
    } else if (!strcmp(argv[1], "test2")) {
      test2();
    } else if (!strcmp(argv[1], "test3")) {
      test3();
    } else {
      cout << argv[0] << ": Unrecognized argument " << argv[1] << endl;
      cout << "Only arguments recognized are test1 through test3" << endl;
    }

    return 0;
  }

  int wsize = 500;
  int linewidth = 1;
  float pointsize = 5.0f;
  graphicsInit(argc, argv, wsize, linewidth, pointsize);
  return 0;
}
