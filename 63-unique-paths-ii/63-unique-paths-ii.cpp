class Solution {
private:
    int paths(vector<vector<int>>& obstacleGrid,int m,int n,vector<vector<int>>&dp){
        
        if(n<0 || m<0) return 0;
        if(obstacleGrid[m][n]==1)return 0;
        if(n==0 && m==0 && !obstacleGrid[0][0]) return 1;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        int up=0,left=0;
        up=paths(obstacleGrid,m-1,n,dp);
        left=paths(obstacleGrid,m,n-1,dp);
        
        return dp[m][n]=left+up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=(int)obstacleGrid.size();
        int n=(int)obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return paths(obstacleGrid,m-1,n-1,dp);
    }
};