class Solution {
public:        
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;//LEft Pointer
        unordered_map<int,int>m;
        int ans=0,n=nums.size();
        for(int j=0;j<n;j++){
            m[nums[j]]++;
            while(i<n&&m[nums[j]]>k){
                m[nums[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};