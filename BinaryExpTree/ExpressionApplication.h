#include "BinaryTree.h"
#include <vector>
#include <stdio.h>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class ExpressionApplication {
public:
	BinaryTree * _expression;// = new BinaryTree;

	ExpressionApplication(vector<Token> &v);
	~ExpressionApplication();
	TreeNode * differentiate(bool isPowerOp, char target);
	BinaryTree * differentiate(char target);
	BinaryTree * simplify();
	BinaryTree * buildExpressionTree(vector<Token> &v);

};
