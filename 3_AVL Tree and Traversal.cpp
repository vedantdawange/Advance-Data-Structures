//Code By Vedant Dawange

#include <iostream>
#include <algorithm>

using namespace std;

class node
{
public:
   int data;
   node *left;
   node *right;
} * root;

class avlTree
{
public:
   int height(node *);
   int diff(node *);
   node *rr_rotation(node *);
   node *ll_rotation(node *);
   node *lr_rotation(node *);
   node *rl_rotation(node *);
   node *balance(node *);
   node *insert(node *, int);
   void display(node *, int);

   void inorder(node *);
   void preorder(node *);
   void postorder(node *);

   void inorder_nonrec(node *);
   void preorder_nonrec(node *);
   void postorder_nonrec(node *);

   avlTree()
   {
      root = NULL;
   }
};

int main()
{
   int ch, val;
   avlTree avl;
   while (1)
   {
      cout << " AVL Tree Implementation Program " << endl;
      cout << " 1.Insert Element into the tree\n 2.Display AVL Tree\n 3.InOrder traversal\n 4.PreOrder traversal" << endl;
      cout << " 5.PostOrder traversal \n 6.InOrder traversal(Non-Recursive)\n 7.PreOrder traversal(Non-Recursive)" << endl;
      cout << " 8. Post order Traversal (Non-Recursive)" << endl;
      cout << " 0.Exit" << endl;
      cout << " Enter your Choice: ";
      cin >> ch;
      switch (ch)
      {

      case 0:
         exit(1);

      case 1:
         cout << " Enter the node value to be inserted: ";
         cin >> val;
         root = avl.insert(root, val);
         break;

      case 2:
         if (root == NULL)
         {
            cout << " Tree is Empty" << endl;
            continue;
         }
         cout << " Balanced AVL Tree:" << endl;
         avl.display(root, 1);
         break;

      case 3:
         cout << " Inorder Traversal:";
         avl.inorder(root);
         cout << endl;
         break;

      case 4:
         cout << " Preorder Traversal:";
         avl.preorder(root);
         cout << endl;
         break;

      case 5:
         cout << " Postorder Traversal:";
         avl.postorder(root);
         cout << endl;
         break;

      case 6:
         cout << " Inorder Traversal (Non-Recursive):";
         avl.inorder_nonrec(root);
         cout << endl;
         break;

      case 7:
         cout << " Preorder Traversal (Non-Recursive):";
         avl.preorder_nonrec(root);
         cout << endl;
         break;

      case 8:
         cout << " Postorder Traversal (Non-Recursive):";
         avl.postorder_nonrec(root);
         cout << endl;
         break;

      default:
         cout << " Invalid Option! Try again!";
      }
      cout << "\n\n*******************************************\n\n";
   }
   return 0;
}

int avlTree::height(node *temp)
{
   int h = 0;
   if (temp != NULL)
   {
      int l_height = height(temp->left);
      int r_height = height(temp->right);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}

int avlTree::diff(node *temp)
{
   int l_height = height(temp->left);
   int r_height = height(temp->right);
   int b_factor = l_height - r_height;
   return b_factor;
}

node *avlTree::ll_rotation(node *parent)

{
   node *temp;
   temp = parent->right;
   parent->right = temp->left;
   temp->left = parent;
   return temp;
}

node *avlTree::rr_rotation(node *parent)
{
   node *temp;
   temp = parent->left;
   parent->left = temp->right;
   temp->right = parent;
   return temp;
}

node *avlTree::lr_rotation(node *parent)
{
   node *temp;
   temp = parent->left;
   parent->left = rr_rotation(temp);
   return ll_rotation(parent);
}

node *avlTree::rl_rotation(node *parent)
{
   node *temp;
   temp = parent->right;
   parent->right = ll_rotation(temp);
   return rr_rotation(parent);
}

node *avlTree::balance(node *temp)
{
   int bal_factor = diff(temp);
   if (bal_factor > 1)
   {
      if (diff(temp->left) > 0)
         temp = rr_rotation(temp);
      else
         temp = lr_rotation(temp);
   }
   else if (bal_factor < -1)
   {
      if (diff(temp->right) > 0)
         temp = rl_rotation(temp);
      else
         temp = ll_rotation(temp);
   }
   return temp;
}

node *avlTree::insert(node *root, int value)
{
   if (root == NULL)
   {
      root = new node;
      root->data = value;
      root->left = NULL;
      root->right = NULL;
      return root;
   }
   else if (value < root->data)
   {
      root->left = insert(root->left, value);
      root = balance(root);
   }
   else if (value > root->data)
   {
      root->right = insert(root->right, value);
      root = balance(root);
   }
   else
      cout << " The Element Already Exists\n";
   return root;
}

void avlTree::display(node *ptr, int level)
{
   int i;
   if (ptr != NULL)
   {
      display(ptr->right, level + 1);
      cout << "\n";
      if (ptr == root)
         cout << "Root -> ";
      for (i = 0; i < level && ptr != root; i++)
         cout << " ";
      cout << ptr->data;
      display(ptr->left, level + 1);
   }
}

void avlTree::inorder(node *tree)
{
   if (tree == NULL)
      return;
   inorder(tree->left);
   cout << tree->data << " ";
   inorder(tree->right);
}

void avlTree::preorder(node *tree)
{
   if (tree == NULL)
      return;
   cout << tree->data << " ";
   preorder(tree->left);
   preorder(tree->right);
}

void avlTree::postorder(node *tree)
{
   if (tree == NULL)
      return;
   postorder(tree->left);
   postorder(tree->right);
   cout << tree->data << " ";
}

//Stack Declaration For Non-Recursive Traversals
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

//Non-Recursive Traversals
void avlTree::inorder_nonrec(node *c_root)
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
            cout << "	" << temp->data;
            temp = temp->right;
         }
         else
            break;
      } while (1);
   }
   else
      cout << " The tree is empty ";
}

void avlTree::preorder_nonrec(node *c_root)
{
   stack stk;
   node *temp = root;

   stk.push(temp);

   while (!stk.empty())
   {
      temp = stk.pop();
      if (temp != NULL)
      {
         cout << temp->data << "	";
         stk.push(temp->right);
         stk.push(temp->left);
      }
   }
}

void avlTree::postorder_nonrec(node *c_root)
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
         cout << ptr->data << "	";
         top_prev = top;
         ptr = stkarr[top--];
      }
   } while (ptr != NULL);
}
