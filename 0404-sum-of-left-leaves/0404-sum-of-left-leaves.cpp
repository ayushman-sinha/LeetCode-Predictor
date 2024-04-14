/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum=0;
   
    void calc(TreeNode *root){        
        if(root==nullptr)
            return;   
        calc(root->left);
        if(root->left!=nullptr&&root->left->left==nullptr&&root->left->right==nullptr)        
            sum+=root->left->val;
        calc(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {      
        if(root==nullptr)
            return 0;
        calc(root);
        return sum;    
    }
};