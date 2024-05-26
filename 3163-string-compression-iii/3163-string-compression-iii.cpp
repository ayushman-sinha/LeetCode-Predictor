class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int n=word.size();
        for(int i=0;i<n;i++){
            int j=i+1;
            int c=1;
            while(j<n&&word[i]==word[j]&&c<9){
                j++;
                c++;
            }
            i=j-1;
            ans+=to_string(c)+word[i];
        }
        return ans;
    }
};