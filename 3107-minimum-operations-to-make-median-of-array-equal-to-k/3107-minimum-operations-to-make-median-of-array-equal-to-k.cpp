class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=n/2;
            
        long long ans=0LL+abs(nums[mid]-k); 
        nums[mid]=k;
        for(int i=mid;i>0;i--){
            if(nums[i-1]>nums[i]){
                ans+=abs(nums[i]-nums[i-1]);
                nums[i-1]=nums[i];
            }
        }    
        for(int i=mid+1;i<n;i++){
            if(nums[i-1]>nums[i]){
                ans+=abs(nums[i]-nums[i-1]);
                nums[i]=nums[i-1];
            }
        }
        return ans;
            
    }
};
/*
    nums = [2,5,6,8,5], k = 7
    sorted = [2,5,5,6,8]
*/