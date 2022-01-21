class Solution {
private:
    int minpath(vector<vector<int>>& grid,int m,int n,vector<vector<int>>&dp){
        if(m<0 || n<0) return 999999;
        if(m==0 && n==0) return grid[0][0];
        
        if(dp[m][n]!=-1)return dp[m][n];
        
        int left=999999,up=999999;
        left=grid[m][n] + minpath(grid,m,n-1,dp);
        up=grid[m][n] + minpath(grid,m-1,n,dp);
        return dp[m][n]=min(left,up);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return minpath(grid,m-1,n-1,dp);
    }
};