class Solution {
private:
    int coin(vector<int>&coins, int am,int idx,vector<vector<int>>&dp){
        
        if(idx==0){
            if(am%coins[idx]==0)return am/coins[idx];
            return 1e9;
        }
        if(dp[idx][am]!=-1)return dp[idx][am];
        int nottake=0+coin(coins,am,idx-1,dp);
        int take=1e9;
        if(coins[idx]<=am)
        take=1+coin(coins,am-coins[idx],idx,dp);
        return dp[idx][am]= min(take,nottake);
    }
public: 
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans= coin(coins,amount,coins.size()-1,dp);
        return ans>=1e9?-1:ans;
    }
};