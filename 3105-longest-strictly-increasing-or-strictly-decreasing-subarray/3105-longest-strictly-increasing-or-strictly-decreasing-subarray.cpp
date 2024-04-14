class Solution {
public:
    int checkIncreasing(vector<int>&nums,int i,int j){
        int ans=0;
        for(int k=i;k<j;k++)
            if(nums[k]>nums[k+1]) ans++;
        else
            return -1;
        return ans+1;
    }
    int checkDecreasing(vector<int>&nums,int i,int j){
        int ans=0;
        for(int k=i;k<j;k++)
            if(nums[k]<nums[k+1]) ans++;
        else
            return -1;
        return ans+1;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){                
                    ans=max({ans,checkIncreasing(nums,i,j),checkDecreasing(nums,i,j)});
            }
        }
        return ans;
    }
};