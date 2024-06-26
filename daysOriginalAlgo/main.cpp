#include <bits/stdc++.h>
using namespace std;


/* 
    This is an implementation of the research paper:
    https://web.archive.org/web/20220406184919/https://sci-hub.hkvisa.net/10.1145/820127.820173

    Day's original algorithm which he came up with balance a binary search tree
    in O(1) space and O(N) time.
*/


/* 
    In the original Day's algorithm, the first step is to generate a sorted linked list, or "vine," 
    where each node only has a right pointer, and all left pointers are set to null. 
    This right-skewed tree is created by an in-order traversal of the BST.
*/

class TreeNode{

public:
    
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// STEP 1 : function to create a vine (a sorted linked list with all right pointers to next nodes and the left pointers set as null)

/* CORE ALGORITHM : to create a vine

    first we will create vine with rst because we know that it has to be attached at the last of the root i.e to the right pointer of the root
    so we will perform the traversal like this -> process the RST (create vine for it)
    -> connect it with the root
    -> flatten (create vine) the LST
    connect LST end to the root
    we will keep sending previous pointers after processing each node
    so this is kind of a reversed inorder (Right, Root, Left)
*/

// Function to perform single left rotation
TreeNode* rotateLeft(TreeNode* root) {
    TreeNode* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

// Function to perform single right rotation
TreeNode* rotateRight(TreeNode* root) {
    TreeNode* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

// function to create a vine
TreeNode* createVine(TreeNode* root){

    // base case(s)
    if(!root) return nullptr;

    // recursive cases(s)

    // convert the lst to vine
    root->left = createVine(root->left);

    // perform right rotation to make the tree a vine
    while(root->left){
        root = rotateRight(root);
    }

    // convert the rst to vine
    root->right = createVine(root->right);

    return root;

}

void printVine(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Constructing an example BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(20);

    // Flatten the BST to a vine using recursive Day's algorithm
    root = createVine(root);

    // Print the vine (linked list)
    cout << "Flattened vine (linked list): ";
    printVine(root);

    return 0;
    
}