#include<bits/stdc++.h>
class Solution {
public:
    void cmbns(vector<vector<int>>&ans,vector<int>&stds,vector<int>&com, int t,int i){
        int n=stds.size();
       
            if(t==0){
                ans.push_back(com);            
            return;
        }
        
        for(int j=i;j<n;j++){
            
            if( j>i && stds[j]==stds[j-1]) continue;
            if(t<stds[j])break;
        com.push_back(stds[j]);
        cmbns(ans,stds,com,t-stds[j],j+1);       
        com.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>com;
        
        
        
        cmbns(ans,candidates ,com, target,0);
        
        
        return ans;
    }
};