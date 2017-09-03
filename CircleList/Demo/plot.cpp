#include "plot.h"

int window1;
Points inpoints;
bool connect = false;

//window configurations and registering callbacks
void graphicsInit (int argc, char **argv, int wsize, int linewidth, 
		   float pointsize)
{
  glutInit(&argc, argv);
  glutInitWindowSize(wsize, wsize);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  window1 = glutCreateWindow("OpenGlut Demo");
  glutMouseFunc(mouse);
  glutDisplayFunc(display);//callback function invoked on redisplaying window
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
  glutAddMenuEntry("connect/ unconnect points", 4);
  glutAddMenuEntry("exit", 5);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menu (int value)
{
  switch (value) {
  case 1:
    inpoints.clear();
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
      if(connect == true)
	connect = false;
      else
        connect = true;  
    glutPostRedisplay();
    break;
  case 5:
    exit(0);
  }
}

void display ()
{
  float white[3] = {1.0f, 1.0f, 1.0f};
  clearScreen(white);
  glColor3f(1.0f, 0.0f, 0.0f);
  drawPoints(inpoints);
  if (connect) {
    glColor3f(0.0f, 0.0f, 0.0f);
    drawLoop(inpoints);
  }
  glFlush();
}

//controls mouse events i.e., left click pushes point to list 
//right-click displays context menu
void mouse (int button, int buttonState, int x, int y)
{
  mouseGeneric(button, buttonState, x, y, inpoints);
  glutPostRedisplay();
}

void mouseGeneric (int button, int buttonState, int x, int y,
		   Points &inpoints)
{
  Point oldp(-1, -1);
  if (button == GLUT_LEFT_BUTTON && buttonState == GLUT_UP)
    return;
  Point p = point(x, y);

  if (button == GLUT_LEFT_BUTTON)
    inpoints.push_back(p);
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
  for (int i = 0; i < points.size(); ++i)
    glVertex(points[i]);
  glEnd();
}

void drawLineStrip (const Points &points)
{
  glBegin(GL_LINE_STRIP);
  for (int i = 0; i < points.size(); ++i)
    glVertex(points[i]);
  glEnd();
}

void drawLoop (const Points &points)
{
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < points.size(); ++i)
    glVertex(points[i]);
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
  pts.push_back(Point(x, y));
  }
}
// print out points
void writePoints (ostream &ostr, const Points &pts)
{
  ostr << pts.size() << endl;
  for (Points::const_iterator p = pts.begin(); p != pts.end(); ++p)
    ostr << p->getX() << " " << p->getY() << endl;
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
