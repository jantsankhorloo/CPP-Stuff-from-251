/*
  You are expected to implement one of the O(nlog(n)) sorting algorithms you
  learned about in class. Feel free to add any helper functions to this header
  file.
*/

#ifndef SORT
#define SORT

#include <functional>

#include "point.h"

void sort(Points &points, int start, int end,
          function<int(Point, Point)> compare);

#endif
