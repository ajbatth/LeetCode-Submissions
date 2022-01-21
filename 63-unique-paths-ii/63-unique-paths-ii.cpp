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
        if(obstacleGrid[0][0]!=1) dp[0][0]=1;
        else dp[0][0]=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                int right=0,down=0;
                if(j>0)right=dp[i][j-1];
                if(i>0)down=dp[i-1][j];
                
                dp[i][j]=right+down;
                
            }
        }
        
        return dp[m-1][n-1];
    }
};