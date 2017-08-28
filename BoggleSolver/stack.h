 #include <iostream>
 #include <utility>
 
 using namespace std;
 
 struct node {
 	pair<int,int> data;
	struct node * next;
 };
 
 class Stack
 {
	struct node * top;
	public:
		int peekfirst();
		int peeksecond();
		Stack();
		void push(pair<int,int>);
		pair<int,int> pop();
		int length;
 };
