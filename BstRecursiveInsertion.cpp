#include <iostream>

using namespace std;

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

node * insertRecursive ( node *insertPtr, int value )
{
    if ( insertPtr == NULL )
    {
        insertPtr = new node();  
        insertPtr->key = value;
        insertPtr->left = NULL;
        insertPtr->right = NULL;
        return insertPtr;
    }
  
    if ( value < insertPtr->key ) 
        insertPtr->left  = insertRecursive( insertPtr->left,  value ); 
    else 
        insertPtr->right = insertRecursive( insertPtr->right, value ); 
   
    return insertPtr;  
}

void inorder(struct node *ptrNode) 
{
    if (ptrNode != NULL) 
    {
        inorder(ptrNode->left);
        cout << ptrNode->key << " ";
        inorder(ptrNode->right);
    }
}

int main() 
{
    
    root = insertRecursive( root, 50 );
    insertRecursive( root, 30 );
    insertRecursive( root, 70 ); 
    insertRecursive( root, 20 );
    insertRecursive( root, 45 );
    insertRecursive( root, 60 );
    insertRecursive( root, 80 );
        
    inorder(root);
    cout << endl;
    inorder(root);

    return 0;
}
