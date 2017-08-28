#include <iostream>
#include "stack.h"
#include "deque.h"

using namespace std;

void read_part_3()
{
	//Read in the number of commands to execute
	int n;
	cin >> n;
	char command1,command2;
	Deque deque;
	int value;
	while(n--)
	{
		cin >> command1 >> command2;
		
		// process command1 and command2
		
		//cout << command1 << command2 << value << endl;
		if (command1 == 'e') {
		    cin >> value;
		    if (command2 == 'f') {         	
			//cout << command1 << command2 << value << endl;
			deque.enqueue_front(value);
		    }
		    else if (command2 == 'b') {
			//cout << command1 << command2 << value << endl;
			deque.enqueue_back(value);
		    }
		}
		else if (command1 == 'd') {
		    if (command2 == 'f') {
		        //cout << "in de fron" << endl;
		        
			int number = deque.dequeue_front();
		     	cout << number << endl;
		    }
		    else if (command2 == 'b') {
		        //cout << "in de back" << endl;
			int number1 = deque.dequeue_back();
		    	cout << number1 << endl;
		    }
		}
		else if (command1 == 's') {
		    int numbers = deque.get_array_size();
		    cout << numbers << endl;
		}
	}
}

void read_input()
{
	int project_part;
	//Read the first line of the test case
	cin >> project_part;
	
	switch(project_part)
	{
		case 3:
			read_part_3();
			break;
	}
}

int main()
{
	// Read in the test case
	read_input();
	return 0;
}
