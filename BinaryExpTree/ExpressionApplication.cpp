#include "ExpressionApplication.h"
#include "ShuntingYard.h"
using namespace std;

TreeNode * newNode(Token &v) {
	TreeNode * temp = new TreeNode(v);
	return temp;
}

BinaryTree *
ExpressionApplication::buildExpressionTree(vector<Token> &v) {
	//TODO 3
	stack<TreeNode *> st;
	TreeNode *t, *t1, *t2;
	for (int i = 0; i < v.size(); i++) {
		if (!(v[i].elementType == operation)) {
			t = newNode(v[i]);
			st.push(t);
		}
		else {
			t = newNode(v[i]);
			t1 = st.top(); st.pop(); 
			t2 = st.top(); st.pop();
			t->_right = t1;
			t->_left = t2;
			st.push(t);
		}
	}
	t = st.top(); st.pop();
	_expression->_root = t;
	return _expression;
}


ExpressionApplication::ExpressionApplication(vector<Token> &v) {
	//TODO 2
	_expression = new BinaryTree;
	buildExpressionTree(v);
}

void chop(TreeNode * root) {
	/**if (root == NULL) return;
	chop(root->_left);
	chop(root->_right);
	chop(root->_parent);
	delete root;**/
	if (root == NULL) return;
	if (root->_left != NULL) chop(root->_left);
	if (root->_right != NULL) chop(root->_right);
	delete root; return; 
	
}

ExpressionApplication::~ExpressionApplication() {
	//TODO 2
	chop(_expression->_root);
}



TreeNode * ExpressionApplication::differentiate(bool isPowerOp, char target) {
	//TODO 5
	return NULL;
}

BinaryTree * ExpressionApplication::differentiate(char target) {
	//TODO 5
	return NULL;
}

BinaryTree *
ExpressionApplication::simplify() {
	//TODO 4
	return NULL;
}


