#include "hull.h"
#include "sort.h"
#include <iostream>
using namespace std;
using namespace std::placeholders;

// The inputs to this function are a vector of points, which is an unsorted
// array of all points in the plot, and an EMPTY vector of the hull.
// This function runs the graham hull finding algorithm, and puts the hull
// into the hull vector.

int comp(Point a, Point b, Point c) {
	int pos = (b.getX() - a.getX())*(c.getY() - a.getY()) - (b.getY() - a.getY())*(c.getX() - a.getX());
	if (pos > 0) return 1;
	else if (pos < 0) return -1;
	return 0;
	//int res = a.leftTurn(b,c);
}

int comp1(Point p, Point q, Point r) {
	int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
			(q.getX() - p.getX()) * (r.getY() - q.getY());
	if (val == 0) return 0;
	return (val > 0)? 1 : -1;
}

Point next(Points &points) {
	Point p = points.back();
	points.pop_back();
	Point res = points.back();
	points.push_back(p);
	return res;
}

int dist(Point p1, Point p2) {
	return (p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) +
		(p1.getY() - p2.getY()) * (p1.getY() - p2.getY());
}
void swap(Point &p1, Point &p2) {
	Point temp = p1;
	p1 = p2;
	p2 = temp;
}

int comp2(Point p0, Point p1, Point p2) {
	int left = comp1(p0, p1, p2);
	if (left == 0) {
		return (dist(p0, p2) >= dist(p0, p1))? -1: 1;
	}
	return (left == -1)? -1: 1;
}
void grahamHull(Points &points, Points &hull) {
  // TODO	
	int miny = points[0].getY();
	int min = 0;
	int N = points.size();	
	for (int i = 1; i < N; i++) {
		int y = points[i].getY();
		if ((y < miny) || (miny == y && points[i].getX() < points[min].getX())) {
			miny = points[i].getY(), min = i; 
		}
	}
	/*for (int i = 1; i < N; i++) {
		if (points[i].getY() < points[min].getY()) {
			min = i;
		}
	}*/
	swap(points[0], points[min]);
	Point p0 = points[0];
	//sort with respect to the first point
	//auto compare = bind(comp1, p0, _1, _2);
	auto compare = bind(comp2, p0, _1, _2);
	sort(points, 1 , N, compare);
	
	int m = 1;
	for (int i = 1; i < N; i++) {
		//while (i < N - 1 && comp(p0, points[i], points[i + 1]) == 0) {	
		while (i < N - 1 && comp1(p0, points[i], points[i + 1]) == 0) {
			i++;
		}
		points[m] = points[i];
		m++;
	}
	if (m < 3) return;
	
	hull.push_back(points[0]);
	hull.push_back(points[1]);
	hull.push_back(points[2]);
	
	for (int i = 3; i < m; i++) {
		//while (comp(next(hull), hull.back(), points[i]) != -1) 
		while (comp1(next(hull), hull.back(), points[i]) != -1)
			hull.pop_back();
		hull.push_back(points[i]);
	} 

/*	for (int i = 3; i < N; i++) {
		Point top = hull.back();
		hull.pop_back();
		while (comp(hull.back(), top, points[i]) != 1) {
			top = hull.back();
			hull.pop_back();
		}
		hull.push_back(top);
		hull.push_back(points[i]);
	}*/
}

// The inputs to this function are a vector of points, which is an unsorted
// array of all points in the plot, and an EMPTY vector of the hull.
// This function runs the jarvis hull-finding algorithm, and puts the hull
// into the hull vector.
void jarvisHull(Points &points, Points &hull) {
  // TODO
	int N = points.size();
	int left = 0;
	for (int i = 1; i < N; i++) {
		//start at left most point so take X		
		if (points[i].getX() < points[left].getX()) {
			left = i;
		}	
	}
	int t = left, q;
	do {
		hull.push_back(points[t]);
		q = (t + 1)%N;
		for (int i = 0; i < N; i++) {
			//if (points[t].leftTurn(points[i], points[q]) == -1) {
			if (comp1(points[t], points[i], points[q]) == -1) {
				q = i;
			}
		}
		t = q;
	} while (t != left); 
}
