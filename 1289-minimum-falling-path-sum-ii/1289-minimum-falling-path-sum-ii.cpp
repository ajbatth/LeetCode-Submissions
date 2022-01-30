class Solution {
private:
    int minpath(vector<vector<int>>&grid,int row, int last,vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(row==0){
            int mini=99999;
            for(int i=0;i<m;i++){
                if(i!=last){
                    mini=min(mini,grid[0][i]);
                }
            }
            return mini;
        }
        if(dp[row][last]!=-1)return dp[row][last];
        int mini=9999999;
        for(int i=0;i<m;i++){
            if(i!=last){
                int path=grid[row][i]+minpath(grid,row-1,i,dp);
                mini=min(mini,path);
            }
        }
        return dp[row][last]= mini;
        
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return minpath(grid,n-1,m,dp);
        
    }
};