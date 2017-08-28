#include <iostream>
#include "cuckoo.h"

using namespace std;
Cuckoo::Cuckoo(int len, int maxIter) {
	r = len;
	maxLoop = maxIter;
	T1 = new int[r];
	T2 = new int[r];
}

int Cuckoo::getr() {
	return r;
}

int Cuckoo::h1(int x) {
	return (x % r);
}

int Cuckoo::h2(int x) {
	return (x % (r - 1));
}

bool Cuckoo::lookup(int x) {
	return ((T1[h1(x)] == x) || (T2[h2(x)] == x));
}

int Cuckoo::whichtable(int x) {
	for (int i = 0; i < r; i++) {
		if (T1[i] == x){ return 1;}
		else if (T2[i] == x) { return 2;}
	}
	return 0;
}

int Cuckoo::where(int x) {
	for (int i = 0; i < r; i++) {
		if (T1[i] == x) { return i;}
	}
	for (int j = 0; j < r; j++) {
		if (T2[j] == x) { return j;}
	}
	return 0;
}

void Cuckoo::rehash() {
	int * temp1 = new int[r];
	int * temp2 = new int[r];

	for (int i = 0; i < r; i++) {
		temp1[i] = T1[i];
		temp2[i] = T2[i];
	}
	int newsize = r * 2;
	int oldsize = r;
	
	int * newarray1 = new int[newsize];
	int * newarray2 = new int[newsize];
	delete[] T1;
	delete[] T2;
	T1 = newarray1, T2 = newarray2;
	r = newsize;

	for (int j = 0; j < oldsize; j++) {
		insert(temp1[j]);
		insert(temp2[j]);
	}
}

void Cuckoo::insert(int x) {
	if (lookup(x)) {return;}
	int i = 0;
	for (; i < maxLoop; i++) {
		if (T1[h1(x)] == 0) {
			T1[h1(x)] = x; 
			//cout << "x === "  << x << endl;
			cout << x << " in T1[" << where(x) << "]!" << endl;
			return;
		}

		int tempt1 = T1[h1(x)];
		int tempx1 = x;
		T1[h1(x)] = x;
		//cout << "x === "  << x << endl;
		cout << x << " in T1[" << where(x) << "]" << endl;
		x = tempt1;

		if (T2[h2(x)] == 0) {
			T2[h2(x)] = x; 
			//cout << "x === "  << x << endl;
			cout << x << " in T2[" << where(x) << "]!" << endl; 
			return;
		}

		int tempt2 = T2[h2(x)];
		int tempx2 = x;
		T2[h2(x)] = x;
		//cout << "x === "  << x << endl;
		cout << x << " in T2[" << where(x) << "]" << endl;
		x = tempt2;
	}
	if (i == maxLoop) {
		cout << "maxloop reached" << endl;
		rehash();
		insert(x);
	}
}

void Cuckoo::remove(int x) {
	if (T1[h1(x)] == x) {
		T1[h1(x)] = 0;
		cout << x << " out T1[" << h1(x) << "]" << endl; 
	}
	else if (T2[h2(x)] == x) {
        T2[h2(x)] = 0;
        cout << x << " out T2[" << h2(x) << "]" << endl;
	}
	else {cout << "no out " << x << endl;}
}