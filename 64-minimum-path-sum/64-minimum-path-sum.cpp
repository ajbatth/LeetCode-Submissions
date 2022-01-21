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
        
        // vector<vector<int>>dp(m,vector<int>(n,-1));        
        // return minpath(grid,m-1,n-1,dp);
        
        vector<int>pre(n),curr(n);
        curr[0]=grid[0][0];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int right=999999,down=999999;
                right=grid[i][j]+ (j>0? curr[j-1]:999999);
                down=grid[i][j] + (i>0?pre[j]:999999);

                curr[j]=min(right,down);
            }
            curr.swap(pre);
            //swap(curr,pre);
        }
        return pre[n-1];
    }
};