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
    string str="";
    void calc(TreeNode *root,string &a){
        if(!root){
            return;
        }
        a.push_back(root->val+'a');
        if(!root->left&&!root->right){
            string x=a;
            reverse(x.begin(),x.end());
            if(x<str||str=="") str=x;
        }
        calc(root->left,a);
        calc(root->right,a);
        a.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string a="";
        calc(root,a);
        return str;
    }
};