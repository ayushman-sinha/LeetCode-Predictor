class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0,c=0;
        //vector<int>size;
        for(auto i:s){
            if(i!=' ')
                c++;
            else{
                if(c!=0)
                    ans=c;
                c=0;
            }
        }
        if(c!=0)
            ans=c;
        return ans;
    }
};