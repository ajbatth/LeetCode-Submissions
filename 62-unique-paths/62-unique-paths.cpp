class Solution {
private:
    int paths(int m,int n, vector<vector<int>> &dp){
        if(m<0 || n<0) return 0;
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int left=0,up=0;
        left=paths(m,n-1,dp);
        up=paths(m-1,n,dp);
        return dp[m][n]=left+up;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
                int right=0,down=0;
                if(i>0) down=dp[i-1][j];
                if(j>0) right=dp[i][j-1];
                dp[i][j]=right+down;
                
            }
        }
        
        return dp[m-1][n-1];
    }
};