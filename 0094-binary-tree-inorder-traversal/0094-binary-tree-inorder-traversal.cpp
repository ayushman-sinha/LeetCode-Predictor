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
   void inOrder(TreeNode *root,vector <int> &ar1)
   {
       if(root==nullptr)
           return;
       inOrder(root->left,ar1);
       ar1.push_back(root->val);
       inOrder(root->right,ar1);
           
   }
    vector<int> inorderTraversal(TreeNode* root)
    {
       vector <int> ar1;
        inOrder(root,ar1);
        return ar1;
    }
};