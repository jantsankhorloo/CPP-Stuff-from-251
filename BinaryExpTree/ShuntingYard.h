#include <stack>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "Token.h"

const int precedence[5][3] = {
	{'^', 4, 0},
	{'*', 3, 1},
	{'/', 3, 1},
	{'+', 2, 1},
	{'-', 2, 1}
};



class Shuntingyard {
public:
	char * _string;
	
	Shuntingyard(char * s) {
		_string = strdup(s);
	}
	
	~Shuntingyard() {
		delete _string;
	}
	
	std::vector<Token> infixToPostfix() {
		string ops = "-+/*^";
		stack<char> s;
		vector<Token> output;
		int length = strlen(_string);
		for (int i = 0; i < length; i++) {
			char token = _string[i];
			int idx = ops.find(token);
			if (token == ' ') continue;
			if (idx != -1) {
				if (s.empty()) {
					s.push(idx);
				}
				else {
					while (!s.empty()) {
						int prec2 = s.top() / 2;
						int prec1 = idx / 2;
						if (prec2 > prec1 || (prec2 == prec1 && token != '^')
							) {
							int index = s.top(); s.pop();
							char temp = ops[index];
							Token op(temp);
							output.push_back(op);
						} else break;
					}
					s.push(idx);
				}
			}
			else if (token == '(') {
				s.push(-2); //-2 stands for "("
			}
			else if (token == ')') {
				while (s.top() != -2) {
					int index = s.top(); s.pop();
					char temp = ops[index];
					Token op(temp);
					output.push_back(op);
				}
				s.pop();
			}
			else {
				Token temp(token);
				output.push_back(temp);
			}
		}
		while (!s.empty()) {
			int index = s.top(); s.pop();
			char temp = ops[index];
			Token op(temp);
			output.push_back(op);
		}
		return output;
	
	}
};
