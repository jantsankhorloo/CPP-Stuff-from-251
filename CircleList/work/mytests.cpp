#include "clist.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <iostream>
using namespace std;
typedef CircleList Points;


void test1(){
printf("test1 insert into list\n");
Points pts;
pts.addBack(Point(69, 274));
pts.addBack(Point(198, 381));
pts.addBack(Point(437, 354));
pts.addBack(Point(315, 256));

assert(pts[0].getX() == 69 && pts[0].getY() == 274);
assert(pts[1].getX() == 198 && pts[1].getY() == 381);
assert(pts[2].getX() == 437 && pts[2].getY() == 354);
assert(pts[3].getX() == 315 && pts[3].getY() == 256);
printf("test1 passed\n");

}

void test2(){
printf("test2 insert into list\n");
Points pts;
pts.addBack(Point(69, 274));
pts.addBack(Point(198, 381));
pts.addBack(Point(437, 354));
pts.addFront(Point(315, 256));

assert(pts[0].getX() == 315 && pts[0].getY() == 256);
assert(pts[1].getX() == 69 && pts[1].getY() == 274);
assert(pts[2].getX() == 198 && pts[2].getY() == 381);
assert(pts[3].getX() == 437 && pts[3].getY() == 354);
printf("test2 passed\n");

}


void test3(){
printf("test3 insert at position = 2 \n");
Points pts;
pts.addBack(Point(69, 274));
pts.addBack(Point(198, 381));
pts.addBack(Point(437, 354));
pts.addBack(Point(315, 256));
pts.addAt(2,Point(-1, -1));

assert(pts[2].getX() == -1 && pts[2].getY() == -1);
printf("test3 passed\n");

}


void test4(){
printf("test4 remove at position = 2 \n");
Points pts;
pts.addBack(Point(69, 274));
pts.addBack(Point(198, 381));
pts.addBack(Point(437, 354));
pts.addBack(Point(315, 256));
pts.removeAt(2);

assert(pts[0].getX() == 69 && pts[0].getY() == 274);
assert(pts[1].getX() == 198 && pts[1].getY() == 381);
assert(pts[2].getX() == 315 && pts[2].getY() == 256);
printf("test4 passed\n");

}

void test5(){
printf("test5 [] and circularity \n");
Points pts;
pts.addBack(Point(69, 274));
pts.addBack(Point(198, 381));
pts.addBack(Point(437, 354));
pts.addBack(Point(315, 256));


assert(pts[5].getX() == 198 && pts[5].getY() == 381);

printf("test5 passed\n");

}
void
usage()
{
  // Print usage
  fprintf(stderr, "TestMyString test1|test2|....|test5\n");
}

int
main( int argc, char ** argv) {
if (argc == 1) {
    usage();
    return 1;
  }

  if ( !strcmp(argv[1], "test1")) {
    test1();
  }
  else if ( !strcmp(argv[1], "test2")) {
    test2();
  }
  else if ( !strcmp(argv[1], "test3")) {
    test3();
  }
  else if ( !strcmp(argv[1], "test4")) {
    test4();
  }
  else if ( !strcmp(argv[1], "test5")) {
    test5();
  }
  else {
    usage();
    exit(1);
  }

}
