/*
  In this file you are to implement one of the O(nlog(n)) algorithms you learned
  about in class.
  The algorithm can be one of:
    - quicksort
    - mergesort
    - heapsort

  You are responsible for figuring out the data structures you want to use
  during implementation. You are free to use the C++ standard library,
  but you are NOT permitted to use any existing sorting code.
*/

#include "sort.h"

// sort takes a vector of Points, and a compare function. The
// compare function returns:
//  1 when a > b
//  0 when a == b
// -1 when a < b
//
// The comparison function is to be used when sorting. After sorting is
// finished, the points vector should have the points from index start to index end sorted least-to-greatest
// according to the compare function.
//
// HINT: Look at std::bind to give your compare function extra arguments.
void sort(Points &points, int start, int end, function<int(Point, Point)> compare) {
	int i = start, j = end - 1;
	Point pivot = points[(start + end) / 2];
	while (i <= j) {
		while (compare(points[i], pivot) == -1) i++;
		while (compare(points[j], pivot) == 1) j--;
		if (i <= j) {
			Point temp = points[i];
			points[i] = points[j];
			points[j] = temp;
			i++; j--;
		}
	};
	if (start < j) sort(points, start, j, compare);
	if (i < end) sort(points, i, end, compare);
}
