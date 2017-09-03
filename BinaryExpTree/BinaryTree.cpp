#include "BinaryTree.h"

BinaryTree::BinaryTree() {
	_root = NULL;
}


void destroy(TreeNode * root) {
	if (root == NULL) return;
	if (root->_left != NULL) destroy(root->_left);
	if (root->_right != NULL) destroy(root->_right);
	delete root; return; 

}
BinaryTree::~BinaryTree() {
	//TODO 2
	destroy(_root);
}

void printTree(TreeNode * root) {
	if(root == NULL) return;
	if(root -> t -> elementType == operation) {
		putchar('(');
		fflush(stdout);
	}
	printTree(root -> _left);
	root -> t -> print();
	printTree(root -> _right);
	if(root -> t -> elementType == operation) {
		putchar(')');
		fflush(stdout);
	}
}

void
BinaryTree::print() {
	printTree(_root);
	putchar('\n');
}
