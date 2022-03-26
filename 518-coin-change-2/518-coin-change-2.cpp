class Solution {
private:
    int coin(vector<int>&coins,int i,int amount,vector<vector<int>>&dp){
        if(i==0){
            return amount%coins[i]==0;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int take=0,nottake=0;
        nottake=coin(coins,i-1,amount,dp);
        if(coins[i]<=amount)
            take=coin(coins,i,amount-coins[i],dp);
        return dp[i][amount]= take + nottake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int a=0;a<=amount;a++){
            if(a%coins[0]==0)dp[0][a]=1;
            }
    
    for(int i=1;i<n;i++){
        for(int a=0;a<=amount;a++){
            int take=0,nottake=0;
        nottake=dp[i-1][a];
        if(coins[i]<=a)
            take=dp[i][a-coins[i]];
         dp[i][a]= take + nottake;
        }
    }
    return dp[n-1][amount];
    }
};