class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m1,m2;
        for(int i=0;i<s.length();i++){
            m1[s[i]]=t[i];
            m2[t[i]]=s[i];
        }
    string a="",b="";
        for(int i=0;i<s.length();i++){
            a+=m1[s[i]];
            b+=m2[t[i]];
        }
        return a==t&&b==s;
    }
};