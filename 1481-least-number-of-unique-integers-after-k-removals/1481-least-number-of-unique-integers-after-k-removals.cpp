class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        if(k>=arr.size())return 0;
        unordered_map<int,int>m;
        for(auto i:arr)
            m[i]++;
        vector<pair<int,int>>ar;
        for(auto i:m)
            ar.push_back({i.second,i.first});
        sort(ar.begin(),ar.end());        
        for(int i=0;i<ar.size();i++){
            if(k==0) break;
            if(k-ar[i].first>=0){ 
                k-=ar[i].first;
                ar[i].first=0;
            }
            else k--;
        }
        int c=0;
        // for(auto i:ar)
        //     cout<<i.first<<" "<<i.second<<endl;
        for(int i=0;i<ar.size();i++) c+=(ar[i].first!=0);
        return c;
        
    }
};
/*
    1,1,2,3,3,3,4
    
    1,1,2,3,3,4,5
    
    1->2
    2->1
    3->2
    4->1
    5->1
    8->1

*/