class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto i:arr) m[i]++;
        for(auto i:m) if(i.second>(0.25*arr.size())) return i.first;
        return 0;
        
    }
};