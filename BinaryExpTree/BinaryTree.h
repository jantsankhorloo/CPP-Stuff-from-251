#include <string.h>
#include "Token.h"

class TreeNode {
public:
	Token * t;	
	TreeNode * _parent;
	TreeNode * _left;
	TreeNode * _right;
	
	TreeNode(Token &t) {
		this -> t = new Token(t);
		_parent = NULL;
		_left = NULL;
		_right = NULL;
	}
	~TreeNode() { }
};
void printTree(TreeNode * root);
class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();
	TreeNode * _root;
	void print();
};
