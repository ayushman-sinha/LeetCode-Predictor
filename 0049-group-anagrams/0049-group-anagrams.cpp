class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        
        map<map<char,int>,vector<string>>m;
        for(auto i:strs){
            map<char,int>tmp;
            for(auto j:i)
                tmp[j]++;
            m[tmp].push_back(i);
        }
        for(auto i:m)
            ans.push_back(i.second);
        
        return ans;
    }
};