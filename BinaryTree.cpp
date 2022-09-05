using namespace std;
#include<iostream>
#include<climits>





struct TreeNode
{
    // data member ,, as a class
    int val { };
   TreeNode* left { };
   TreeNode* right { }; 
   // special methods , constructors
   TreeNode(int val , TreeNode* right , TreeNode* left) : val{val} , right{right} , left{left} { }; 
   TreeNode(int val) : val{val} { }; 
   TreeNode() : val{0} , left{NULL} , right{NULL} { };  // useless ... automatically called if not provided/defined
};
    

//Time O(n)    Aux. Space (H+2) -> O(H)        -> +1 for the  null call (L or R) .. one then the other ... +1 for the H zero-based 
// if H is 2 (3 nodes)... at most (4) stack calls (recursion)
void inorder(TreeNode* root) {
    if(!root)
        return;
    inorder(root->left);
        cout << root->val << " ";
    inorder(root->right);    
}

void preorder(TreeNode* root) {
     if(!root)
        return;
    cout << root->val << " ";
         preorder(root->left);
    preorder(root->right);  
}

void postorder(TreeNode* root) {
    if(!root)   // RTE
        return;
    postorder(root->left);
    postorder(root->right);  
    cout << root->val << " ";
}

// Time O(n)  Aux Space O(H)
int tree_max(TreeNode* root) {

    if(!root)  
      return INT_MIN;

    int mL = tree_max(root->left);  // Left-subtree
    int mR = tree_max(root->right); // Right-subtree 
    // compare 3 values , root left right
    return max(root->val, max(mL,mR));// V  L  R
}

int tree_min(TreeNode* root) {
    if(!root)
        return INT_MAX;
    return min( root->val , min(tree_min(root->left) , tree_min(root->right)));    
}
// T O(n)       Aux S O(H)
int tree_height(TreeNode* root) {   
    if(!root)  
        return -1; // zero based
    return  1 + max(tree_height(root->right) , tree_height(root->left));
}

// T O(n)       Aux. S O(H)
int total_nodes(TreeNode* root) { // Size
    if(!root)   
        return 0;
    return 1 + total_nodes(root->left) + total_nodes(root->right);    
}

int tree_size(TreeNode* root) {

    int counter {0}; 
    
    if(root->left)  // RTE
        counter += tree_size(root->left);       

     if(root->right)  
        counter += tree_size(root->right);  

    return counter + 1;      
}


int total_leaves(TreeNode* root) {

    int counter { };            // int -> int variable

    if(root->left)  // RTE
        counter += total_leaves(root->left);        // 0 or 1

     if(root->right)  
        counter += total_leaves(root->right);  

    return counter + (!root->left && !root->right);      
}

bool is_exist(int value , TreeNode* root) { // bool -> bool variable

    bool result = (value == root->val); // base-case

        if(!result && root->left)  // T no entre in if        // ! false
            result = is_exist(value , root->left);

         if(!result && root->right) // false
            result = is_exist(value , root->right);

    return result; // T      // false
}

bool is_prefect(TreeNode* root) {



}



















////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main () {
      
    TreeNode* root { };
   // pointer  to a dynamic allocated memory       
    root = new TreeNode{10};  // creation                   //     10
    root->left = new TreeNode(20 , NULL,NULL);          //  20           -50
    root->right = new TreeNode(-50,NULL,NULL);       //40      60
    root->left->left = new TreeNode(40);            //      0   
    root->left->right = new TreeNode(60);
    root->left->right->left = new TreeNode(0);




/*
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
*/

/* 
     cout << tree_max(root) << endl;
    cout << tree_min(root) << endl;
*/
    //cout << tree_height(root) << endl;
   // cout << total_nodes(root) << endl;
   // cout << tree_size(root) << endl;
   // cout << total_leaves(root) << endl;

    cout << is_exist(160 , root) << endl;







    return 0;
}





/*


class BinaryTree {

private:
struct Node
{
    Node* left { };
    Node* right { };
    int data { };

    Node(int data) : data(data) { }
};

Node* root { };

public:

BinaryTree(int root_value) : root(new Node(root_value)) { }























*/