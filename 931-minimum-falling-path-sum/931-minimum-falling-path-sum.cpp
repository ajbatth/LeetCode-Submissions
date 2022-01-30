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
    
    int min_path(vector<vector<int>>&matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>pre=matrix[0],curr(m);
        for(int i=1;i<n;i++){
            for(int col=0;col<m;col++){
                int down=99999,left_dia=99999,right_dia=99999;
        
                down=matrix[i][col]+pre[col];
                if(col>0)
                left_dia=matrix[i][col]+pre[col-1];
                if(col<m-1)
                right_dia=matrix[i][col]+pre[col+1];

                curr[col]= min(down,min(left_dia,right_dia));
            }
            pre.swap(curr);
        }
        return *min_element(pre.begin(),pre.end());
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int mini=999999;
        // int n=matrix.size();
        // int m=matrix[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         for(int i=0;i<m;i++){
//             mini=min(mini,minpath(matrix,n-1,i,dp));
            
//         }
        return min_path(matrix);
    }
};