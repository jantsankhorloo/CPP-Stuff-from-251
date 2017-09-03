/*
        This file will NOT be included when grading.

  The tests given here are very basic. The grading will be much more
  comprehensive, so make sure to test your code beyond what we have here!
*/

#include "hull.h"
#include "point.h"
#include "sort.h"

#include <iostream>
using namespace std;

void test1() {
  cout << "Test 1" << endl;

  // Test the basics
  Point p(10, 20);
  Point a(4, 5);
  if (p.dot(a) != 140) {
    cout << "Failed dot product" << endl;
    return;
  }

  if (p.cross(a) != -30) {
    cout << "Failed cross product" << endl;
    return;
  }

  if (p.distanceSquared(a) != 261) {
    cout << "Failed distance squared" << endl;
    return;
  }

  Point c(10, 21);
  if (a.leftTurn(p, c) != 1) {
    cout << "Failed left turn" << endl;
    return;
  }

  cout << "Test Passed" << endl;
}

// sort comparison functions
int compareX(Point a, Point b) {
  return (a.getX() > b.getX() ? 1 : (a.getX() == b.getX() ? 0 : -1));
}
int compareY(Point a, Point b) {
  return (a.getY() > b.getY() ? 1 : (a.getY() == b.getY() ? 0 : -1));
}

void test2() {
  cout << "Test 2: sorting" << endl;

  
  Points points(
      {Point(1, 4), Point(2, 3), Point(3, 2), Point(4, 1), Point(4, 4)});

  sort(points, 0, points.size(), compareY);	

  // Should be sorted by Y coordinate
  for (int i = 0; i < 4; i++) {
    if (points[i].getY() != i + 1) {
      cout << "YSORTING FAILED AT " << i << endl;
      return;
    }
  }
  if (points[4].getY() != 4) {
    cout << "YSORTING FAILED AT 4" << endl;
    return;
  }

  sort(points, 0, points.size(), compareX);

  // Should be sorted by X coordinate
  for (int i = 0; i < 4; i++) {
    if (points[i].getX() != i + 1) {
      cout << "XSORTING FAILED AT " << i << endl;
      return;
    }
  }
  if (points[4].getX() != 4) {
    cout << "XSORTING FAILED AT 4" << endl;
    return;
  }

  cout << "Test Passed" << endl;
}

bool cmpPoints(Points &p1, Points &p2) {
  if (p1.size() != p2.size())
    return false;

  for (unsigned int i = 0; i < p1.size(); i++) {
    if (!(p1[i] == p2[i])) {
      return false;
    }
  }

  return true;
}

void test3() {
  cout << "Test 3" << endl;

  // Test hull algorithms - make sure the hulls returned are correct
  Points points({Point(1, 1), Point(1, 5), Point(4, 5)});

  Points hull;

  grahamHull(points, hull);
  if (!cmpPoints(points, hull)) {
    cout << "grahamHull fail" << endl;
    return;
  }

  hull.clear();
  jarvisHull(points, hull);
  if (!cmpPoints(points, hull)) {
    cout << "jarvisHull fail" << endl;
    return;
  }

  // Note how this test was super basic. Don't rely on this test to tell you if
  // your implementation is correct. Write your own tests.
  // Because that's what we will do when grading.

  cout << "Test Passed" << endl;
}
