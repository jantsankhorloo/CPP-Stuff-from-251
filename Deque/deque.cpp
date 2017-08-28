#include <iostream>
#include "deque.h"

using namespace std;

Deque::Deque()
{
	//TODO: Write the Deque constructor
	//NOTE: Start with an array of size 10!
	size = 10;
	elements = 0;
	array = new int[size];

}

int Deque::get_array_size() {
	return size;
}

void Deque::enqueue_front(int n)
{
	//TODO: Front enqueue method
	
	if (elements == 0) {
	    array[0] = n;
	    elements++;
	    return;
	}
	int temp[size];
	for (int i = 0; i < size; i++) {
	   temp[i] = array[i];
	    //cout << array[i] << endl;
	}
	if (is_full()) {
	    reallocate();
	    for (int i = 0; i < size; i++) {
	        array[i + 1] = temp[i];
	    }
	    array[0] = n; 
	    elements++;
	    return;
	}
	//cout << "size: " << size << endl;
	for (int i = 0; i < size; i++) {
	    array[i + 1] = temp[i];
	    //cout << "ef list" << array[i] << endl;
	}
	array[0] = n;
	//cout << "ef value " <<array[0]<< endl;;
	elements++;

	/*if (is_full()) {
	    reallocate();
	}
	if (front == 0) {
	    front = size - 1;
	}
	else {front--;}
	array[front] = n;
	elements++;*/

}

void Deque::enqueue_back(int n)
{
	//TODO: Back enqueue
	//if (elements == 0) {
	//    array[0] = n;
	//    elements++;
	//    return;
	//}
	if (is_full()) {
	    reallocate();
	    array[elements] = n;
	    elements++;
	    return;
	}
	array[elements] = n;
	//cout << "eb elem"<<array[elements] << endl;
	elements++;
}

int Deque::dequeue_front()
{
	//TODO: front dequeue
	int temp = array[0];
	//cout << "df" << temp << endl;
	for (int i = 0; i < size; i++) {
	    array[i] = array[i + 1];
	}
	elements--;
	return temp;
}

int Deque::dequeue_back()
{
	//TODO: back dequeue
	int temp = array[elements - 1];
	elements--;
	return temp;
}

bool Deque::is_full()
{
	//TODO: Determine if you need to double the array
	if (elements >= size ) {
	    return true;
	}
	return false;
}

void Deque::reallocate()
{
	//TODO: Correctly reallocate memory for the deque. Use the doubling strategy.
	int newsize = size * 2;
	int * newarray = new int[newsize];
	for (int i = 0; i < size; i++) {
	    newarray[i] = array[i];
	}
	size = newsize;
	delete[] array;
	array = newarray;
}
