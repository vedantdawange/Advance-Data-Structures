//Code By Vedant Dawange

#include <iostream>
#include <cstdlib>
using namespace std;

class node
{
public:
	int value;
	node *left, *right;
};
node *root = NULL;

int insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *Delet(node *, int);
node *FindMin(node *);
void level_trav(node *ptr);

node *search(node *, int);

void inorder_nonrec(node *root);
void preorder_nonrec(node *root);
void postorder_nonrec(node *root);

int main()
{

	int ch, v, value;

	do
	{
		cout << "------Binary Search Tree Operations------" << endl;
		cout << "1. Insert Element \n2. InOrder Traversal(Recursive)\n3. Preorder Traversal(Recursive)\n4. Postorder Traversal(Recursive)";
		cout << "\n5. All Traversal Methods(Recursive)\n6. Delete a Value\n7. Inorder Traversal(Non-Recursive)\n8. Preorder Traversal(Non-Recursive)";
		cout << "\n9. Postorder Traversal(Non-Recursive)\n10. All Traversal Methods(Non-Recursive)\n11. Search For an Element\n12. Level Traversal";
		cout << "\n13. Exit";
		cout << "\nEnter Your Choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			node *temp;
			temp = new node;
			cout << "\nEnter the Value to be Inserted : ";
			cin >> temp->value;
			if (root == NULL)
			{
				root = new node;
				root->value = temp->value;
				root->left = NULL;
				root->right = NULL;
				cout << "\nNode Added as Root Node" << endl;
			}
			else
			{
				v = insert(root, temp);
				if (v == 3)
					cout << "\nNode Already Exists!" << endl;
			}
			break;

		case 2:
			if (root == NULL)
			{
				cout << "\nTree is Empty!";
			}
			else
			{
				cout << "\nInorder Traversal Of the Tree: ";
				inorder(root);
			}
			break;

		case 3:
			if (root == NULL)
			{
				cout << "\nTree is Empty!";
			}
			else
			{
				cout << "\nPreorder Traversal Of the Tree: ";
				preorder(root);
			}
			break;

		case 4:
			if (root == NULL)
			{
				cout << "\nTree is Empty!";
			}
			else
			{
				cout << "\nPostorder Traversal Of the Tree: ";
				postorder(root);
			}
			break;

		case 5:
			if (root == NULL)
			{
				cout << "\nTree is Empty!";
			}
			else
			{
				cout << "\nInorder Traversal Of the Tree: ";
				inorder(root);
				cout << "\nPreorder Traversal Of the Tree: ";
				preorder(root);
				cout << "\nPostorder Traversal Of the Tree: ";
				postorder(root);
			}
			break;

		case 6:
			if (root == NULL)
			{
				cout << "\nTree is Empty! Nothing to Delete" << endl;
			}
			cout << "Enter the value to be deleated : ";
			cin >> value;
			Delet(root, value);
			break;

		case 7:
			if (root == NULL)
			{
				cout << "\nTree is Empty!";
			}
			else
			{
				cout << "\nInorder Traversal Of the Tree(Non-Recursive): ";
				inorder_nonrec(root);
			}
			break;

		case 8:
			if (root == NULL)
			{
				cout << "\nTree is Empty!";
			}
			else
			{
				cout << "\nPreorder Traversal Of the Tree(Non-Recursive): ";
				preorder_nonrec(root);
			}
			break;

		case 9:
			if (root == NULL)
			{
				cout << "\nTree is Empty!";
			}
			else
			{
				cout << "\nPostOrder Traversal Of the Tree(Non-Recursive): ";
				postorder_nonrec(root);
			}
			break;

		case 10:
			if (root == NULL)
			{
				cout << "\nTree is Empty!";
			}
			else
			{
				cout << "\nInorder Traversal Of the Tree(Non-Recursive): ";
				inorder_nonrec(root);
				cout << "\nPreorder Traversal Of the Tree(Non-Recursive): ";
				preorder_nonrec(root);
				cout << "\nPostOrder Traversal Of the Tree(Non-Recursive): ";
				postorder_nonrec(root);
			}
			break;

		case 11:
			if (root == NULL)
			{
				cout << "\nTree is Empty!";
			}
			else
			{
				int data;
				cout << "\nEnter Value to be Searched : ";
				cin >> data;

				if (search(root, data) != NULL)
				{
					cout << "\nElement " << data << " Found In the BST";
				}
				else
				{
					cout << "\nElement " << data << " not Present in the BST";
				}
			}
			break;

		case 12:
			if (root == NULL)
			{
				cout << "\nTree is Empty!";
			}
			else
			{
				void level_trav(root);
			}
			break;

		case 13:
			exit(0);
		default:
			cout << "Wrong Choice! Try again!" << endl;
			break;

		} //switch Closed

		cout << "\n\n";
	} while (ch != 13);
	return 0;
}

int insert(node *c_root, node *newnode)
{

	if (c_root->value == newnode->value) //If already Exists
		return 3;

	if (newnode->value < c_root->value)
	{ //If Smaller than Current root Node
		if (c_root->left != NULL)
			insert(c_root->left, newnode);
		else
		{
			cout << "Node Added as the Left Child of : " << c_root->value;
			c_root->left = newnode;
			(c_root->left)->left = NULL;
			(c_root->left)->right = NULL;

			return 1;
		}
	}

	if (newnode->value > c_root->value)
	{ //If Greater than Current root Node
		if (c_root->right != NULL)
			insert(c_root->right, newnode);
		else
		{
			cout << "Node Added as the Right Child of : " << c_root->value;
			c_root->right = newnode;
			(c_root->right)->left = NULL;
			(c_root->right)->right = NULL;
			return 2;
		}
	}
}

node *search(node *root, int key)
{
	if (root == NULL || root->value == key)
		return root;

	// Key is greater than root's data
	if (key > root->value)
		return search(root->right, key);

	// Key is smaller than root's data
	return search(root->left, key);
}

void level_trav(node *ptr)
{
	node *que[20];
	int front = 0, rear = 0;
	que[rear] = ptr;

	while (front <= rear)
	{
		ptr = que[front++];
		if (ptr != NULL)
		{
			cout << "  " << ptr->value << "  ";
			que[++rear] = ptr->left;
			que[++rear] = ptr->right;
		}
	}
}

void inorder(node *c_root)
{

	if (c_root == NULL)
	{
		cout << "Tree Empty!";
		return;
	}
	else
	{
		if (c_root->left != NULL)
			inorder(c_root->left);
		cout << c_root->value << "  ";
		if (c_root->right != NULL)
			inorder(c_root->right);
	}
}

void preorder(node *c_root)
{

	if (c_root == NULL)
	{
		cout << "Tree Empty!";
		return;
	}
	else
	{
		cout << c_root->value << "  ";
		if (c_root->left != NULL)
			preorder(c_root->left);

		if (c_root->right != NULL)
			preorder(c_root->right);
	}
}

void postorder(node *c_root)
{

	if (c_root == NULL)
	{
		cout << "Tree Empty!";
		return;
	}
	else
	{
		if (c_root->left != NULL)
			inorder(c_root->left);
		if (c_root->right != NULL)
			inorder(c_root->right);
		cout << c_root->value << "  ";
	}
}

node *Delet(node *tempnode, int d)
{
	node *temp;
	if (tempnode == NULL)
	{
		cout << "Element Not Found!";
	}
	else if (d < tempnode->value)
	{
		tempnode->left = Delet(tempnode->left, d);
	}
	else if (d > tempnode->value)
	{
		tempnode->right = Delet(tempnode->right, d);
	}
	else
	{ //condition for 2 Childs
		if (tempnode->right && tempnode->left)
		{
			temp = FindMin(tempnode->right); //replacing with inorder Successor
			tempnode->value = temp->value;
			tempnode->right = Delet(tempnode->right, temp->value);
		}
		else
		{ //Condition for one child or no child

			temp = tempnode;
			if (tempnode->left == NULL)
				tempnode = tempnode->right;
			else if (tempnode->right == NULL)
				tempnode = tempnode->left;
			free(temp);
			cout << "Element deleted Succesfully! " << endl;
		}
	}
	return tempnode;
}

node *FindMin(node *temp1)
{
	if (temp1 == NULL)
		return NULL;
	if (temp1->left)
		return FindMin(temp1->left);
	else
		return temp1;
}

// Non-recursive Traversals

class stack
{
public:
	int top;
	node *stack_nodes[20];

public:
	stack()
	{
		top = -1;
	}
	void push(node *);
	node *pop();
	int empty()
	{
		if (top == -1)
			return (1);
		return (0);
	}
};

void stack::push(node *node)
{
	stack_nodes[++top] = node;
}

node *stack::pop()
{
	return (stack_nodes[top--]);
}

void inorder_nonrec(node *c_root)
{
	stack stk;
	node *temp;
	if (c_root != NULL)
	{
		temp = c_root;
		do
		{
			while (temp != NULL)
			{
				stk.push(temp);
				temp = temp->left;
			}
			if (!stk.empty())
			{
				temp = stk.pop();
				cout << "	" << temp->value;
				temp = temp->right;
			}
			else
				break;
		} while (1);
	}
	else
		cout << "The tree is empty ";
}

void preorder_nonrec(node *c_root)
{
	stack stk;
	node *temp = root;

	stk.push(temp);

	while (!stk.empty())
	{
		temp = stk.pop();
		if (temp != NULL)
		{
			cout << temp->value << "	";
			stk.push(temp->right);
			stk.push(temp->left);
		}
	}
}

void postorder_nonrec(node *c_root)
{
	int flag[50];
	node *ptr = c_root;
	int top_prev;
	node *stkarr[50];
	int top = 1;
	stkarr[++top] = NULL;
	do
	{
		while (ptr != NULL)
		{
			stkarr[++top] = ptr;
			flag[top] = 1;
			if (ptr->right != NULL)
			{
				stkarr[++top] = ptr->right;
				flag[top] = -1;
			}
			ptr = ptr->left;
		}
		top_prev = top;
		ptr = stkarr[top--];

		while (flag[top_prev] == 1)
		{
			cout << ptr->value << "	";
			top_prev = top;
			ptr = stkarr[top--];
		}
	} while (ptr != NULL);
}
