#ifndef TOKEN
#define TOKEN

#include <string.h>
#include <stdio.h>

#include <stdlib.h>
#include <cctype>

enum eType { integer, identifier, operation };

class Token {
public:
	
	int _num;
	char _op;
	char _id;
	eType elementType;
	
	Token(int i) {
		_num = i;
		elementType = integer;
	};
	
	void print() {
		if(elementType == integer) fprintf(stderr, "%d", _num);
		else if(elementType == operation) fprintf(stderr, "%c", _op);
		else fprintf(stderr, "%c", _id);
	}
	
	Token(char c) {
		if(c == '^' || c == '*' || c == '/' || c == '+'
		|| c == '-' || c == '(' || c == ')') {
			_op = c;
			elementType = operation;
		} 
		/*if (isdigit(c)) {
			char str[20];
			strcpy(str, &c);
			_num = atoi(str);
			elementType = integer;
		}*/
		else {
			_id = c;
			elementType = identifier;
		}
	};
	
	Token(const Token &t) {
		this -> elementType = t.elementType;
		if(elementType == integer) this -> _num = t._num;
		else if(elementType == operation) this -> _op = t._op;
		else this -> _id = t._id;
	};
	
	~Token() {}
};

#endif
