//Code By Vedant Dawange

#include <iostream>
#include <stack>

using namespace std;
class node
{
public:
	int data;
	int lth;
	int rth;
	node *left;
	node *right;
};

class tree
{
public:
	node *root, *thread;
	void create();
	void insert(node *root, node *temp);

	void inorder(node *root);
	void preorder(node *root);
	void postorder(node *root);

	void non_rec_inorder(node *root);
	void non_rec_preorder(node *root);
	void non_rec_postorder(node *root);

	node *inorderSuccessor(node *ptr);
};

node *tree::inorderSuccessor(node *ptr)
{
	if (ptr->rth == 0)
		return ptr->right;

	ptr = ptr->right;
	while (ptr->lth == 1)
		ptr = ptr->left;
	return ptr;
}

void tree::non_rec_inorder(node *root)
{
	if (root == NULL)
		cout << endl
			 << "\t Tree is empty";

	//traverse to the Left most node
	node *ptr = root;
	while (ptr->lth == 1)
		ptr = ptr->left;

	// One by one print successors
	while (ptr != NULL)
	{
		if (ptr->data != -1111)
			cout << " " << ptr->data;
		ptr = inorderSuccessor(ptr);
	}
}

void tree::non_rec_preorder(node *root)
{
	node *ptr;
	if (root == NULL)
	{
		cout << "Tree is empty";
		return;
	}
	ptr = root;
	while (ptr != NULL)
	{
		cout << ptr->data << "    ";
		if (ptr->lth == 1)
			ptr = ptr->left;
		else if (ptr->rth == 1)
			ptr = ptr->right;
		else
		{
			while (ptr != NULL && ptr->rth == 0)
				ptr = ptr->right;
			if (ptr != NULL)
				ptr = ptr->right;
		}
	}
}

void tree::create()
{
	node *temp;
	int ch;
	do
	{
		temp = new node;
		cout << "\n Enter The Element to be inserted in TBT: ";
		cin >> temp->data;
		temp->left = NULL;
		temp->right = NULL;
		temp->lth = 0;
		temp->rth = 0;
		if (root == NULL)
		{
			root = temp;

			thread = new node;
			thread->left = root;
			thread->right = NULL;
			thread->data = -1111;
			thread->lth = 0;
			thread->rth = 0;

			root->left = thread;
			root->right = thread;
		}
		else
			insert(root, temp);
		cout << "\n Do U want to add more elements?(y=1/n=0): ";
		cin >> ch;
	} while (ch == 1);
}

void tree::insert(node *root, node *temp)
{
	if (temp->data < root->data)
	{
		if (root->lth == 0)
		{
			temp->left = root->left;
			temp->right = root;
			root->left = temp;
			root->lth = 1;
		}
		else
			insert(root->left, temp);
	}
	else
	{
		if (root->rth == 0)
		{
			temp->right = root->right;
			temp->left = root;
			root->right = temp;
			root->rth = 1;
		}
		else
			insert(root->right, temp);
	}
}

void tree ::inorder(node *root)
{
	if (root->lth == 1)
		inorder(root->left);
	cout << root->data << "\t";
	if (root->rth == 1)
		inorder(root->right);
}

void tree ::preorder(node *root)
{
	cout << root->data << "\t";
	if (root->lth == 1)
		preorder(root->left);
	if (root->rth == 1)
		preorder(root->right);
}

void tree ::postorder(node *root)
{
	if (root->lth == 1)
		postorder(root->left);
	if (root->rth == 1)
		postorder(root->right);
	cout << root->data << "\t";
}

void tree ::non_rec_postorder(node *root) //Non Recursive Postorder
{
	stack<node *> S1;
	stack<node *> S2;
	S1.push(root);
	while (!S1.empty())
	{
		S2.push(S1.top());
		node *temp = S1.top();
		S1.pop();
		if (temp->lth == 0)
			S1.push(temp->left);
		if (temp->rth == 0)
			S1.push(temp->right);
	}
	while (!S2.empty())
	{
		node *temp = S2.top();
		S2.pop();
		cout << temp->data << " ";
	}
	cout << "\n";
}

int main()
{
	int choice;
	tree t;
	t.root = NULL;

	do
	{
		cout << " Program For Threaded Binary Tree";
		cout << "\n 1. Create/Insert \n 2. Inorder\n 3. Preorder\n 4. Postorder\n 5. Non-recursive In-order";
		cout << "\n 6. Non-recursive Pre-order \n 7. Non-recursive Post-order ";
		cout << "\n 0. Exit";
		cout << "\n Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			exit(0);
			break;
		case 1:
			t.create();
			break;
		case 2:
			cout << "Inorder Traversal of TBT : ";
			t.inorder(t.root);
			break;
		case 3:
			cout << "Preorder Traversal of TBT : ";
			t.preorder(t.root);
			break;
		case 4:
			cout << "Postorder Traversal of TBT : ";
			t.postorder(t.root);
			break;
		case 5:
			cout << "Inorder (Non-Recursive) Traversal of TBT : ";
			t.non_rec_inorder(t.root);
			break;
		case 6:
			cout << "Preorder (Non-Recursive) Traversal of TBT : ";
			t.non_rec_preorder(t.root);
			break;

		case 7:
			cout << "Post order (Non-Recursive) Traversal of TBT : ";
			t.non_rec_postorder(t.root);
			break;

		default:
			cout
				<< "\nWrong Choice Try Again!!";
			break;
		}
		cout << "\n********************************\n";
	} while (choice != 0);
	return 0;
}
