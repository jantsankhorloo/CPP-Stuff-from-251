#ifndef HULL
#define HULL

#include "point.h"

void grahamHull(Points &points, Points &hull);
void jarvisHull(Points &points, Points &hull);

// Here you choose the hull algorithm to use in plot.cpp
#define defaultHull jarvisHull

#endif
