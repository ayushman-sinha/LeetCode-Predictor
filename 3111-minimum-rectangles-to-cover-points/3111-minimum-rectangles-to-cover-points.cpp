class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int ans=1;
        sort(points.begin(),points.end());
        int prev=0;
        for(int i=1;i<points.size();i++){
            if(abs(points[prev][0]-points[i][0])>w){
                prev=i;
                ans++;
            }
        }
        return ans;
    }
};