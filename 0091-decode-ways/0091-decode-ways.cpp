class Solution {
public:
    int dp[101];
    int calc(string &s,int i){
        if(i==s.length()) return 1;
        if(i>s.length())
            return 0;
        int ans=0;
        if(dp[i]!=-1) return dp[i];
        if(s[i]!='0'){
            if(i+1<s.length()&&(((s[i]-'0')*10+(s[i+1]-'0'))<=26))
                ans+=calc(s,i+1)+calc(s,i+2);    
            else 
                 ans+=calc(s,i+1);
       }
        //ans+=calc(s,i+1);
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return calc(s,0);
    }
};