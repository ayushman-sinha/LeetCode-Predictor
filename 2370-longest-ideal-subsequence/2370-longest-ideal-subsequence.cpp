class Solution {
public:
    int calc(string &s,int  k,int n,char prev ,vector<vector<int>>&dp){
        int x=0,y=0;
        if(n<0)
            return 0;
        if(dp[prev][n]!=-1)
            return dp[prev][n];
        if(abs(s[n]-prev)<=k||prev=='*')
            x= 1+calc(s,k,n-1,s[n],dp);
       
           y=calc(s,k,n-1,prev,dp);
        return dp[prev][n]=max(x,y);
    }
    int longestIdealString(string s, int k) {
        vector<vector<int>>dp(123,vector<int>(s.length(),-1));
        return calc(s,k,s.length()-1,'*',dp);
    }
};
/*
ukdb

*/