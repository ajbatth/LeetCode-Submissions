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
        int n=coins.size();
        vector<int>pre(amount+1,1e9),curr;
        
        for(int am=0;am<=amount;am++){
            if(am%coins[0]==0 ) pre[am]=am/coins[0];
        }
        pre[0]=0;
        curr=pre;
        for(int idx=1;idx<n;idx++){
            for(int am=1;am<=amount;am++){
                
                int nottake=0+pre[am];
                int take=1e9;
                if(coins[idx]<=am)
                take=1+curr[am-coins[idx]];
                curr[am]= min(take,nottake);
            }
            curr.swap(pre);
        }
        
        int ans= pre[amount];
        return ans>=1e9?-1:ans;
    }
};