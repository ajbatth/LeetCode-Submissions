class Solution {
    private:
void combinations(vector<vector<int>>&ans,vector<int>&stds,vector<int>& comb, int t,int i){
            if(t<=0||i==stds.size()){
                if(t==0){
                    ans.push_back(comb);
                }
                return;
            }
    t-=stds[i];
    comb.push_back(stds[i]);
    combinations(ans,stds,comb,t,i);
    comb.pop_back();
    t+=stds[i];
    combinations(ans,stds,comb,t,i+1);
        }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        combinations(ans,candidates,comb,target,0);
        return ans;
    }
};