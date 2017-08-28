#include <iostream>
#include "stack.h"

using namespace std;

void read_part_1()
{
    //Read the number of commands to execute
    int n;
    cin >> n;
    
    // Initialize your stack here...
    Stack stack;
    
    char command1;
    int value1,value2;
    
    while (n--) 
    {
        cin >> command1;
        if (command1 == 'i')
        {
            cin >> value1 >> value2;
            
            // push the values in your stack here.
	    stack.push(pair<int, int>(value1, value2));
        }
        if (command1 == 'p')
        {
            // Call Pop here, and print the values.
            pair<int,int>value = stack.pop();
	    cout <<  value.first << " " << value.second << endl;
	}
    }
}

void read_part_2()
{
	int num_rows,num_cols;
	//Read in the number of rows and cols in the puzzle
	cin >> num_rows >> num_cols;
	//cout << num_rows << num_cols;
	//Declare the word search array	
	char wordsearch[num_rows][num_cols];
	//Fill in the array
	char letter;		
	for (int i = 0; num_rows > i; i++) {
	    for (int j = 0; num_cols > j; j++) {
		cin >> letter;
		wordsearch[i][j] = letter; 
	    }
	}
	//Read in the word we're looking for
	int targetlength = 0;
	char targetword[100], n; 
	while (cin >> n) {
	    targetword[targetlength] = n; 
	    targetlength++;
	}
	
	//TODO: Part 1b: Run the word search
	Stack stack;
	int k = 0, i = 0, tempj = 0;   
	
	//bool flag = false;
	//int j = 0;
	//for (;num_rows > i; i++) {
	/*while (i < num_rows) {
	    if (flag) {j = tempj; flag = false;}
	    else {j = 0;}
	    //for (; num_cols > j; j++) {
		while (j < num_cols) {
			if (targetword[k] == wordsearch[i][j]) {
			    //cout << targetword[k] << wordsearch[i][j];
		 	    //out << i << j << endl;
			    //stack.push(pair<int,int>(i,j)); k++;
			    
			    if (k == 0) {
			        stack.push(pair<int,int>(i,j)); k++; i = 0; j = 0;
			    //cout << k << endl;
			    }
			    else if (i == stack.peekfirst() + 1 && j == stack.peeksecond() - 1) {
			        stack.push(pair<int,int>(i,j)); k++; i = i - 2; j = - 2;
			    }
			    else if (i = stack.peekfirst() + 1 && j == stack.peeksecond()) {
			        stack.push(pair<int,int>(i,j)); k++; i = i - 2; j = j - 2;
			    }
			    else if (i == stack.peekfirst() + 1 && j == stack.peeksecond() + 1) {
			        stack.push(pair<int,int>(i,j)); k++; i = i - 2; j = j - 2;
			    }
			    else if (i == stack.peekfirst() && j == stack.peeksecond() - 1) {
			     	stack.push(pair<int,int>(i,j)); k++; i = i - 2; j = j - 2;  
			    }
			    else if (i == stack.peekfirst() && j == stack.peeksecond() + 1) {
			    	stack.push(pair<int,int>(i,j)); k++; i = i - 2; j = j - 2;
			    }
			    else if (i == stack.peekfirst() - 1 && j == stack.peeksecond() - 1) {
			    	stack.push(pair<int,int>(i,j)); k++; i = i - 2; j = j - 2;
			    }
			    else if (i == stack.peekfirst() - 1 && j == stack.peeksecond()) {
			    	stack.push(pair<int,int>(i,j)); k++; i = i - 2; j = j - 2;
			    }
			    else if (i == stack.peekfirst() - 1 && j == stack.peeksecond() + 1) {
			        stack.push(pair<int,int>(i,j)); k++; i = i - 2; j =  j - 2;
			    }
			    else {
			        i = stack.peekfirst(); tempj = stack.peeksecond() + 1; flag = true;
					stack.pop();
					k--; ;
			    }
			}
		//if ((i == num_rows - 1) && (j == num_cols - 1) && (k != (targetlength))) {
		//    i = 0;
		//    i = stack.peekfirst() - 2;
	 	//}		
	    	j++;
	    }   
		i++;
	}*/
	

	for (; i < num_rows; i++) {
		for (int j = 0; j < num_cols; j++) {
			if (targetword[k] == wordsearch[i][j]) {
			    stack.push(pair<int,int>(i,j)); k++;
			}
			if ((i == num_rows - 1) && (j == num_cols - 1) && (k != (targetlength))) {
			  	//i = 0;
				i = stack.peekfirst() - 2;
	 		}	
		}
	}
	
	
	int count1= stack.length;
	Stack stack1;
	while (count1--) {
	    pair<int,int> value = stack.pop();
	    stack1.push(value);
	}
	int count2 = stack1.length;
	while (count2--) {
	    pair<int,int> value = stack1.pop();
	    cout << value.first << " " << value.second << endl;
	}

}

void read_input()
{
	int project_part;
	//Read the first line of the test case
	cin >> project_part;
	
	switch(project_part)
	{
		case 1:
			read_part_1();
			break;
		case 2:
			read_part_2();
			break;
	}
}

int main()
{
	// Read in the test case
	read_input();
	return 0;
}
