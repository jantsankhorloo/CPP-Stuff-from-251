 #include "stack.h"
 #include <utility>
 
 Stack::Stack()
 {
	 top = NULL;
	 length = 0;
 }
 
 void Stack::push(pair<int,int> d)
 {
	struct node * newnode;
	newnode = new node;
	newnode->data = d;
	newnode->next = top;
	//if (top != NULL) {
	//    ptr->next = top;
	//}
	top = newnode;
	length++;
	
 }
 
int Stack::peekfirst() {
        return top->data.first;
}

int Stack::peeksecond() {
	return top->data.second;
}

pair<int,int> Stack::pop()
 {
	 struct node * temp;
	 if (top == NULL) {
	     cout << "Empty" << endl;
	     exit(0);
	 }
	 temp = top;
	 top = top->next;
	 pair<int, int> tempdata = temp->data;
	 delete temp;
	 length--;
	 return tempdata;;
	 
	 //return pair<int,int>(0,0);
 }
