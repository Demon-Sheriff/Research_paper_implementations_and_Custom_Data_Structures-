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


int main(){


}