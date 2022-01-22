class Solution {
private:
    int paths(vector<vector<int>>& grid,pair<int,int>&end,vector<vector<int>>&taken,int i,int j,int blks){
        blks--;
       int m=grid.size(), n=grid[0].size();
        //if(i<0 || j<0 || i>=m || j>=n) return 0;
        if(end.first==i && end.second==j){
            if(blks==0) return 1;
            return 0;
        }
        
        taken[i][j]=4;
        int d=0,l=0,r=0,u=0;
        if(i+1<m && taken[i+1][j]==3 && grid[i+1][j]!=-1) d=paths(grid,end,taken,i+1,j,blks);
        
        if(j-1>=0 && taken[i][j-1]==3 && grid[i][j-1]!=-1) l=paths(grid,end,taken,i,j-1,blks);
        
        if(j+1<n && taken[i][j+1]==3 && grid[i][j+1]!=-1) r=paths(grid,end,taken,i,j+1,blks);
        
        if(i-1>=0 && taken[i-1][j]==3 && grid[i-1][j]!=-1) u=paths(grid,end,taken,i-1,j,blks);
        taken[i][j]=3;
        return d+l+r+u;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int,int>start,end;
        int m=grid.size(), n=grid[0].size();
        int obs=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)start={i,j};
                if(grid[i][j]==2)end={i,j};
                if(grid[i][j]==-1)obs++;
            }
        }
        int blks=m*n-obs;
        vector<vector<int>>taken(m,vector<int>(n,3));
        return paths(grid,end,taken,start.first,start.second,blks);
    }
};