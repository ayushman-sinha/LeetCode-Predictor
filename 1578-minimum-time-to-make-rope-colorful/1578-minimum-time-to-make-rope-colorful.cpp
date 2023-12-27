class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int c=0,len=colors.length();
        int mini=neededTime[0],currSum=neededTime[0];
        for(int i=1;i<len;i++){      
                if(colors[i]!=colors[i-1]){
                    c+=currSum-mini;
                    currSum=neededTime[i];
                    mini=neededTime[i];
                }
            else{
                currSum+=neededTime[i];
                mini=max(neededTime[i],mini);
            }            
        }
        return c+=currSum-mini;
    }
};