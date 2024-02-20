class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size()==1&&nums[0]==0)
            return 1;
       
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]!=1)
            {
                return nums[i]-1;
            }
            
     }
        int dif=nums.size()-nums[nums.size()-1];
       if(dif==1)
            return nums.size();
     
        else
            return 0;
        
    }
};