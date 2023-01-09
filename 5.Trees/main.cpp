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

BstNode *bstMin(BstNode *node)
{
	if (node == NULL)
	{
		cout << "Empty tree";
		return NULL;
	}
	// if (root->left == NULL)
	// 	return root->data;
	// return bstMin(root->left);
	while (node->left != NULL)
	{
		node = node->left;
	}
	return node;
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

BstNode *drop(BstNode *root, int data)
{
	if (root == NULL)
		return NULL;
	if (data < root->data)
		root->left = drop(root->left, data);
	else if (data > root->data)
		root->right = drop(root->right, data);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}

		else if (root->right == NULL)
		{
			BstNode *temp = root;
			root = root->left;
			delete temp;
		}
		else if (root->left == NULL)
		{
			BstNode *temp = root;
			root = root->right;
			delete temp;
		}

		else
		{
			BstNode *temp = bstMin(root->right);
			root->data = temp->data;
			root->right = drop(root->right, temp->data);
		}
	}
	return root;
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
	// cout << bstMin(root) << " " << bstMax(root);
	return 0;
}
