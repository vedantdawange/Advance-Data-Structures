#include <iostream> 
using namespace std; 
  
class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};  
  

node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
  
    return(Node);  
}  
  

int identicalTrees(node* a, node* b)  
{  
   
    if (a == NULL && b == NULL)  
        return 1;  
  
    if (a != NULL && b != NULL)  
    {  
        return
        (  
            a->data == b->data &&  
            identicalTrees(a->left, b->left) &&  
            identicalTrees(a->right, b->right)  
        );  
    }  
    
    return 0;  
}  
  
/* Driver code*/
int main()  
{  
	//Defining First Tree
    node *root1 = newNode(3);  
    root1->left = newNode(4);  
    root1->right = newNode(5);  
    root1->left->left = newNode(10);  
    root1->left->right = newNode(6);  
    root1->left->left->right = newNode(22);  
    root1->left->right->right = newNode(12); 
	root1->right->left = newNode(8);
	root1->right->right = newNode(9); 
	root1->right->left->left = newNode(13);
	root1->right->right->left = newNode(17); 
			
	//Defining Second Tree
	node *root2 = newNode(3);  
    root2->left = newNode(4);  
    root2->right = newNode(5);  
    root2->left->left = newNode(10);  
    root2->left->right = newNode(6);  
    root2->left->left->right = newNode(22);  
    root2->left->right->right = newNode(12); 
	root2->right->left = newNode(8);
	root2->right->right = newNode(9); 
	root2->right->left->left = newNode(13);
	root2->right->right->left = newNode(117); 
  
    if(identicalTrees(root1, root2))  
        cout << "Both tree are identical.";  
    else
        cout << "Trees are not identical.";  
  
return 0;  
}
