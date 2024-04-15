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
    int ans=0;
    void calc(TreeNode *root,int sum)
    {
        if(!root)
            return;
        sum=(sum*10)+root->val;
        if(!root->left&&!root->right)        
            ans+=sum;        
        calc(root->left,sum);
        calc(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        calc(root,0);
        return ans;
    }
};