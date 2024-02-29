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
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode *,int>>q;
        q.push({root,0});

        while(!q.empty()){
            int size=q.size();
            vector<int>t;
            int lev=-1;
            while(size--){
                auto x=q.front();
                q.pop();
                t.push_back(x.first->val);
                lev=x.second;
                if(x.first->left) q.push({x.first->left,x.second+1});
                if(x.first->right) q.push({x.first->right,x.second+1});
            }
            if(lev%2==0){
                if(t.size()==1&&t[0]%2==0) return false;
                for(int i=1;i<t.size();i++){
                    if(t[i]%2==0) return false;
                    if(t[i-1]>=t[i]) return false;
                }
            }
            else{
                if(t.size()==1&&t[0]%2!=0) return false;
                for(int i=1;i<t.size();i++){
                    if(t[i]%2!=0) return false;
                    if(t[i-1]<=t[i]) return false;
                } 
            }
        }
        return true;
    }
};