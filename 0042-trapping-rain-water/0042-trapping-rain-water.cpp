class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>suf(n),pref(n);
        int ans=0;
        pref[0]=height[0];
        suf[n-1]=height[n-1];
        for(int i=1;i<n;i++)
            pref[i]=max(pref[i-1],height[i]);
        for(int i=n-2;i>=0;i--)
            suf[i]=max(suf[i+1],height[i]);
        for(int i=0;i<n;i++)
            ans+=min(pref[i],suf[i])-height[i];
        return ans;
    }
};