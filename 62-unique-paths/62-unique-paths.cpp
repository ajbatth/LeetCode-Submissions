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
        return paths(m-1,n-1,dp);
    }
};