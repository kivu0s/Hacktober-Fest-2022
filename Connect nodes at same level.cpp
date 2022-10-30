/* Iterative program to connect all the adjacent nodes at
* the same level in a binary tree*/
#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
class node {
public:
	int data;
	node* left;
	node* right;
	node* nextRight;

	/* Constructor that allocates a new node with the
	given data and NULL left and right pointers. */
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->nextRight = NULL;
	}
};
// setting right pointer to next right node
/*
			10 ----------> NULL
			/ \
		8 --->2 --------> NULL
		/
		3 ----------------> NULL
		*/
void connect(node* root)
{
	// Base condition
	if (root == NULL)
		return;
	// Create an empty queue like level order traversal
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		// size indicates no. of nodes at current level
		int size = q.size();
		// for keeping track of previous node
		node* prev = NULL;
		while (size--) {
			node* temp = q.front();
			q.pop();

			if (temp->left)
				q.push(temp->left);

			if (temp->right)
				q.push(temp->right);

			if (prev != NULL)
				prev->nextRight = temp;
			prev = temp;
		}
		prev->nextRight = NULL;
	}
}

int main()
{
	/* Constructed binary tree is
		10
		/ \
		8	 2
	/
	3
	*/
	// Let us create binary tree shown above
	node* root = new node(10);
	root->left = new node(8);
	root->right = new node(2);
	root->left->left = new node(3);
	connect(root);
	// Let us check the values
	// of nextRight pointers
	cout << "Following are populated nextRight pointers in "
			"the tree"
			" (-1 is printed if there is no nextRight)\n";
	cout << "nextRight of " << root->data << " is "
		<< (root->nextRight ? root->nextRight->data : -1)
		<< endl;
	cout << "nextRight of " << root->left->data << " is "
		<< (root->left->nextRight
				? root->left->nextRight->data
				: -1)
		<< endl;
	cout << "nextRight of " << root->right->data << " is "
		<< (root->right->nextRight
				? root->right->nextRight->data
				: -1)
		<< endl;
	cout << "nextRight of " << root->left->left->data
		<< " is "
		<< (root->left->left->nextRight
				? root->left->left->nextRight->data
				: -1)
		<< endl;
	return 0;
}
// this code is contributed by Kapil Poonia
