#include <iostream>

using namespace std;

class Deque
{
	public:
		Deque();
		void enqueue_front(int);
		void enqueue_back(int);
		int dequeue_front();
		int dequeue_back();
		int get_array_size();
		
	private:
		void reallocate();
		bool is_full();
		int size;
		int elements;
		int * array;
		int front;
		int rear;
};
