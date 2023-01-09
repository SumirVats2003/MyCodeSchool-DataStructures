#include <iostream>
using namespace std;

struct BstNode
{
	int data;
	BstNode *left;
	BstNode *right;
};
BstNode *root = NULL;

BstNode *getNewNode(int data)
{
	BstNode *temp = new BstNode();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

BstNode *insert(BstNode *root, int data)
{
	if (root == NULL)
	{
		root = getNewNode(data);
	}
	else if (data <= root->data)
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
	}
	return root;
}

bool search(BstNode *root, int data)
{
	if (root == NULL)
		return false;
	if (root->data == data)
		return true;
	else if (data < root->data)
		search(root->left, data);
	else
		search(root->right, data);
}

int bstMin(BstNode *node)
{
	if (node == NULL)
	{
		cout << "Empty tree";
		return -1;
	}
	// if (root->left == NULL)
	// 	return root->data;
	// return bstMin(root->left);
	while (node->left != NULL)
	{
		node = node->left;
	}
	return node->data;
}

int bstMax(BstNode *node)
{
	if (node == NULL)
	{
		cout << "Empty tree";
		return -1;
	}
	// if (root->right == NULL)
	// 	return root->data;
	// return bstMax(root->right);
	while (node->right != NULL)
	{
		node = node->right;
	}
	return node->data;
}

int height(BstNode *root)
{
	if (root == NULL)
		return -1;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	return max(leftHeight, rightHeight) + 1;
}

void display(BstNode *root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	display(root->left);
	display(root->right);
}

int main()
{
	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 8);
	root = insert(root, 12);
	root = insert(root, 20);
	root = insert(root, 17);
	root = insert(root, 25);
	root = insert(root, 87);
	root = insert(root, 2);
	display(root);
	cout << "\n";
	cout << bstMin(root) << " " << bstMax(root);
	return 0;
}
