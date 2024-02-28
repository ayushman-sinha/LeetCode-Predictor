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
  int bfs(TreeNode *root)
    {
        queue<TreeNode *>q;     
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>a;
            while(size--)
            {
                TreeNode *tmp=q.front();
                a.push_back(tmp->val);
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            if(q.empty())
                return a[0];          
        }
      return 0;     
    }
    int findBottomLeftValue(TreeNode* root) {
     return bfs(root);       
    }
};