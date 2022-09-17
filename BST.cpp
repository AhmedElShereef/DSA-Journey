#include <iostream>

#include <vector>
#include <queue>
#include <stack>

#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

/*
   set map multi-set multi-map
   Log N    -> balanced BST

*/

struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }


    bool search_Recursively(Node *root, int x)
    {
        if (!root)
            return false;

         if (x == root->key)            //2 base cases
            return true;

        if (x < root->key)
             return search_Recursively(root->left, x);  // step
        
         return search_Recursively(root->right, x);
    }

    bool search_iteratively(Node *root, int x) {

            while(root) {

                if(root->key == x) 
                    return true;

                if(root->key < x) 
                    root = root->right;

                else    
                    root = root->right;
             }

    return false;

    }


};

int main()
{
    Node *tree = new Node(15);
    tree->left = new Node(5);
    tree->left->left = new Node(3);

    tree->right = new Node(20);

    tree->right->left = new Node(18);
    tree->right->right = new Node(80);

    tree->right->left->left = new Node(16);

    cout << tree->search_Recursively(tree, 20) << endl;
    cout << tree->search_iteratively(tree, 20) << endl;

    return 0;
}