class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
       
        int oneR=0,zeroR=0,oneC=0,zeroC=0;
        vector<int>a,b,c,d;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                    zeroR++;
                if(grid[i][j]==1)
                    oneR++;
            }     
            a.push_back(zeroR);
            b.push_back(oneR);
            oneR=0,zeroR=0;            
        }
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==0)
                    zeroC++;
                if(grid[j][i]==1)
                    oneC++;
            }
            c.push_back(zeroC);
            d.push_back(oneC);
            zeroC=0,oneC=0;
        }
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=b[i]+d[j]-a[i]-c[j];
            }
         }
        return grid;
    }
};