class Solution {
private:
    int minpath(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>&dp){
        int n= matrix.size();
        int m=matrix[0].size();
        
        if(col<0 || col>=m) return 99999;
        
        if(row==0){
            return matrix[row][col];
        }
        if(dp[row][col]!=-1)return dp[row][col];
        
        int up=99999,left_dia=99999,right_dia=99999;
        
        up=matrix[row][col]+minpath(matrix,row-1,col,dp);
        
        left_dia=matrix[row][col]+minpath(matrix,row-1,col-1,dp);
        
        right_dia=matrix[row][col]+minpath(matrix,row-1,col+1,dp);
        
        return dp[row][col]= min(up,min(left_dia,right_dia));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini=999999;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<m;i++){
            mini=min(mini,minpath(matrix,n-1,i,dp));
            
        }
        return mini;
    }
};