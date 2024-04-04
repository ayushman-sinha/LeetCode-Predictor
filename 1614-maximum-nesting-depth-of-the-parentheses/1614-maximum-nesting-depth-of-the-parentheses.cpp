class Solution {
public:
    int maxDepth(string s) {
        stack<pair<char,int >>stk;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') {
                if(stk.empty())
                    stk.push({'(',1});
                else 
                    stk.push({'(',stk.top().second+1});
            }
             if(s[i]==')')
                 stk.pop();
            if(!stk.empty())
                ans=max(ans,stk.top().second);
        }
        return ans;
    }
};
/*

((((  g))))
*/