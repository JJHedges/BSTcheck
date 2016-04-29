#include <iostream>
#include <limits.h>

//Code for verification of a binary search tree (BST)

using namespace std;

//Class for each node of BST, with left and right child
class TreeNode
{
	public:
		int key;
		TreeNode *left = 0;
		TreeNode *right = 0;
};

//Function to check if it is a valid BST
bool isBST(TreeNode *node, int minKey, int maxKey)
{
	if(node == 0) return true;
	if(node->key < minKey || node->key > maxKey) return false;
	
	return isBST(node->left, minKey, node->key) && isBST(node->right, node->key, maxKey);
}

//Test on a good BST
void test1()
{
	TreeNode tn1, tn2, tn3, tn4, tn5;
	
	tn1.key = 20;
	tn1.left = &tn2;
	tn1.right = &tn3;
	
	tn2.key = 10;
	
	tn3.key = 30;
	tn3.left = &tn4;
	tn3.right = &tn5;
	
	tn4.key = 29;
	
	tn5.key = 40;
	
	if(isBST(&tn1, INT_MIN, INT_MAX)) cout << "is a BST" << endl;
}

//Test on a height 1 BST
void test2()
{
	TreeNode tn1;
	tn1.key = 20;
	if(isBST(&tn1, INT_MIN, INT_MAX)) cout << "is a BST" << endl;
}

//Test on a invalid BST
void test3()
{
	TreeNode tn1, tn2, tn3;
	
	tn1.key = 20;
	tn1.left = &tn2;
	tn1.right = &tn3;
	
	tn2.key = 21;
	
	tn3.key = 30;
	
	if(!isBST(&tn1, INT_MIN, INT_MAX)) cout << "is not a BST" << endl;
}

int main(int argc, char **argv)
{
	test1();
	test2();
	test3();
}
