class Solution {
private:
    // DP
    int path(vector<vector<int>>&tri,int i,int j,vector<vector<int>>&dp){
        int n=tri.size();
        if(i==n-1){
            return tri[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        int down=tri[i][j]+path(tri,i+1,j,dp);
        int dia=tri[i][j]+path(tri,i+1,j+1,dp);
       return dp[i][j]=min(down,dia);
    }
    
    //tabular
    int minpath(vector<vector<int>>& tri){
        int n=tri.size();
        vector<int>next;
        for(int i=0;i<tri[n-1].size();i++){
            next.push_back(tri[n-1][i]);
        }
        vector<int>curr(next.size());
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down=tri[i][j]+next[j];
            int dia=tri[i][j]+next[j+1];
            curr[j]=min(down,dia);
            }
            next.swap(curr);
        }
        return next[0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return minpath(triangle);
        
    }
};