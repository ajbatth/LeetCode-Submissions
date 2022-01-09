class Solution {
public:
    int solve(int i,vector<int>& v,vector<int>&dp){
        if(i>=v.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int first=solve(i+1,v,dp);
        int second=solve(i+2,v,dp);
        dp[i]=min(first,second)+v[i];
        return dp[i] ;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
    
        return min(solve(0,cost,dp),solve(1,cost,dp));
       
    }
};