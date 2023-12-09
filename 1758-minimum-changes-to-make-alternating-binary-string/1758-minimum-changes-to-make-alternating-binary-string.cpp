class Solution {
public:
    int calc(string &s,int c){
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]-'0'!=c) ans++;
            c=!c;
        }
        return ans;
    }
    int minOperations(string s) {
       return min(calc(s,0),calc(s,1));
    }
};