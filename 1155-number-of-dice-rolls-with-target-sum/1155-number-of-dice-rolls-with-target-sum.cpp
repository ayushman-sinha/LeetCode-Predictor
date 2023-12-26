class Solution {
public:
    int mod=1e9+7;
    int calc(int n,int k,int target, vector<vector<int>>&dp){           
        if(n==0&&target==0)
            return 1;
        if(n==0||target<0)
            return 0;
        if(dp[n][target]!=-1)
            return dp[n][target];
         int ans=0;
       for(int j=1;j<=k;j++){
           ans=(ans%mod+calc(n-1,k,target-j,dp)%mod)%mod;           
       }
        dp[n][target]=ans;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
       vector<vector<int>>dp(31,vector<int>(1001,-1));
        return calc(n,k,target,dp);
    }
};