#include "clist.h"
#include <iostream>
using namespace std;

CircleList::CircleList() {
	//TODO 1
	header = new CNode;
	header->next = header;
	header->prev = header;
	_size = 0;
}

CircleList::~CircleList() {
	//TODO 1
	CNode * t = new CNode;
	t = header->next;
	while (t->next != header) {
		CNode * temp = new CNode;
		temp = t->next;
		delete t;
		t = temp;
	}
	_size = 0;
	delete t->next;
}

bool
CircleList::empty() const {
	//TODO 1
	return header == NULL;
}

const Elem&
CircleList::front() const {
	//TODO 1
	return header->next->elem;
}

const Elem&
CircleList::back() const {
	//TODO 1
	return header->elem;
}

void 
CircleList::add(CNode * v, const Elem& e) {
	//TODO 1
	v->elem = e;
	_size++;
	if (header == NULL) {
		v->next = v;
		v->prev = v;
		header = v;
	}
	else {
		v->next = header->next;
		v->prev = header;
		//head->next->prev = v;
		//head->next = v;
		v->next->prev = v;
		v->prev->next = v;
	}
}

void
CircleList::addFront(const Elem& e) {
	//TODO 1
	//add(header->next, e);
	CNode *v = new CNode;
	v->elem = e;
	v->next = header->next;
	v->prev = header;
	v->next->prev = v;
	v->prev->next = v;
	_size++;
}

void
CircleList::addBack(const Elem& e) {
	//TODO 1
	CNode *v = new CNode;
	v->elem = e;
	v->next = header;
	header->prev->next = v;
	v->prev = header->prev;
	header->prev = v;
	_size++;
}

void
CircleList::remove(CNode * v) {
	//TODO 1
	if (v == NULL) return;
	CNode * u = v->prev;
	CNode * w = v->next;
	u->next = w;
	w->prev = u;
	_size--;
	delete v;
}

void
CircleList::removeFront() {
	//TODO 1
	remove(header->next);
}

void
CircleList::removeBack() {
	//TODO 1
	remove(header->prev);
}

void
CircleList::clear() {
	//TODO 1
	CNode * t = new CNode;
	t = header->next; //header
	while (t != header) { //t->next
		CNode * temp = new CNode;
		temp = t->next;
		delete t;
		t = temp;
	}
	_size = 0;

}

Elem&
CircleList::operator [] (int i) const{
	//TODO 1
	CNode * t = new CNode;
	t = header;
	int counter = 0;
	if (i > _size) {
		i = i % _size;
	}
	while (t->next != header) {
		t = t->next;
		if (counter == i) {
			return t->elem;
		}
		counter++;
	}
}

void
CircleList::setElemAt (int i, const Elem newElem) const{
	//TODO 1
	CNode * t = new CNode;
	t = header;
	int counter = 0;
	while (t->next != header) {
		if (counter == i) {
			t->elem = newElem;
		}
		t = t->next;
	}
}

void
CircleList::print() const {
	//TODO 1
	CNode * t = header->next; //header->next
	while (t != header) { //t!=header
		cout << t->elem.getX() << " " << t->elem.getY() << endl;
		t = t->next;
	}
}

void
CircleList::addAt(int i, const Elem& e) {
	//TODO 1
	CNode * t = new CNode;
	t = header;
	int counter = 0;
	while (t->next != header) {
		//t = t->next;
		if (counter == i) {
			CNode * v = new CNode;
			v->elem = e;
			
			t->next->prev = v;
			v->next = t->next;
			t->next = v;
			v->prev = t;
		}
		t = t->next;
		counter++;
	}
	_size++;
}

void
CircleList::removeAt(int i) {
	//TODO 1
	CNode * t = new CNode;
	t = header;
	int counter = 0;
	while (t->next != header) {
		if (counter == i) {
			remove(t->next);
		}
		t = t->next;
		counter++;
	}
	_size--;
}
