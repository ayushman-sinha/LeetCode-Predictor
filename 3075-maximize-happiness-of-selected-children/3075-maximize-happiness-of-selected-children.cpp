class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>pq;
        for(auto i:happiness) pq.push(i);
        int c=0;
        long long ans=0LL;
        while(!pq.empty()&&k--){
            if(pq.top()-c<0) break;
            ans+=(pq.top()-c);
            pq.pop();
            c++;
         }
        return ans;
    }
};