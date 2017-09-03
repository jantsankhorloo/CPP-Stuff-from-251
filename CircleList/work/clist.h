#include "point.h"
#include <stdlib.h>
#include <stdio.h>

typedef Point Elem;
class CNode{
private:
	Elem elem;
	CNode * next;
	CNode * prev;

	friend class CircleList;
};

class CircleList {
public:
	CircleList();
	~CircleList();
	bool empty() const;
	const Elem& front() const;
	const Elem& back() const;
	void addFront(const Elem& e);
	void addBack(const Elem& e);
	void removeFront();
	void removeBack();
	void clear();
	
	//[] operator
	Elem& operator [] (int i) const;
		void setElemAt (int i, const Elem newElem) const;

	void print() const;
	
	int size() const { return _size;}
	
	void addAt(int i, const Elem& e);//TODO 2
	void removeAt(int i); //TODO 3


private:
	CNode * header;
	int _size;
protected:
	void add(CNode * v, const Elem& e);
	void remove(CNode * v);
};
