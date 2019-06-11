#include <iostream>

using namespace std;

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
struct node *travelingPrevious = NULL;
struct node *traveling = NULL;
struct node *temp = NULL;

void insert(int value) 
{
    if (root == NULL)  // FIRST CREATE FOR ROOT NODE
    {
        root = new node();
        root->key = value;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    
    temp = new node();  // TEMP NODE WHICH WILL BE USED LATER. THIS STATETEMNT PREVENT REPEAT CODE
    temp->key = value;
    temp->left = NULL;
    temp->right = NULL;
    
    travelingPrevious = root; // PARENT OF TRAVELING POINTER
    
    if ( value < travelingPrevious->key )
        traveling = travelingPrevious->left;

    else
        traveling = travelingPrevious->right;

    while ( traveling != NULL ) 
    {
        if ( value < traveling->key )
        {
            travelingPrevious = traveling;
            traveling = traveling->left;
        }
            
        else
        {
            travelingPrevious = traveling;
            traveling = traveling->right; 
        }
    }

    if ( value < travelingPrevious->key )
    {
        travelingPrevious->left = temp;
    }
            
    else
    {
        travelingPrevious->right = temp;
    } 
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
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(45);
    insert(60);
    insert(80);

    inorder(root);
    cout << endl;
    inorder(root);

    return 0;
}
