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
        //vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<int>pre(n,0),curr(n,0);
        if(obstacleGrid[0][0]!=1) curr[0]=1;
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                if(obstacleGrid[i][j]==1){
                    curr[j]=0;
                    continue;
                }
                int right=0,down=0;
                if(j>0)right=curr[j-1];
                if(i>0)down=pre[j];
                
                curr[j]=right+down;
                
            }
            curr.swap(pre);
        }
        
        return pre[n-1];
    }
};