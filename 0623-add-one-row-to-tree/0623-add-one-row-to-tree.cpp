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
     TreeNode* newNode(int val){
         TreeNode *tmp=new TreeNode(val);
         tmp->left=nullptr;
         tmp->right=nullptr;
         return tmp;
     }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *tmp=newNode(val);
            tmp->left=root;
           
            return tmp;
        }
            
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>tmp;
        
        while(!q.empty()){
            int size=q.size();           
              depth--;
            if(depth!=0)
                tmp.clear();
            while(depth!=0&&size--){                
                TreeNode *k=q.front();
                q.pop();
                tmp.push_back(k);
                if(k->left)
                    q.push(k->left);
                if(k->right)
                    q.push(k->right);
                
            }
           // cout<<depth<<endl;
            if(depth==1&&q.empty()){
                for(int i=0;i<tmp.size();i++){                   
                    TreeNode *tmp2=newNode(val);
                    TreeNode *tmp4=newNode(val);                   
                        tmp[i]->left=tmp2;                   
                        tmp[i]->right=tmp4;                              
                    }
                 break; 
                }
               
            
            if(depth==0){                   
                for(int i=0;i<tmp.size();i++){                   
                    TreeNode *tmp2=newNode(val);
                    TreeNode *tmp4=newNode(val);
                    if(tmp[i]&&tmp[i]->left){
                        TreeNode *tmp3=tmp[i]->left;
                        tmp[i]->left=tmp2;
                        tmp2->left=tmp3;
                    }
                    else{
                        if(!tmp[i]->left)
                            tmp[i]->left=tmp2;      
                    }
                    if(tmp[i]&&tmp[i]->right){
                        TreeNode *tmp3=tmp[i]->right;
                        tmp[i]->right=tmp4;
                        tmp4->right=tmp3;                        
                    }
                    else{
                         if(!tmp[i]->right)
                         tmp[i]->right=tmp4;         
                    }
                }
                break;
            }
          
           
            
        }
        return root;
        
    }
};