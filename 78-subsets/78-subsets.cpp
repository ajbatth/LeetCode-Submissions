class Solution {
private:
    void subs(vector<int>& nums,int idx,vector<vector<int>>&v,vector<int>& set){
        int n=nums.size();
        if(idx==n){
            v.push_back(set);
            return;
        }
        set.push_back(nums[idx]);
        subs(nums,idx+1,v,set);
        set.pop_back();
        
        subs(nums,idx+1,v,set);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        unordered_set<int>st;
        vector<vector<int>>v;
        vector<int>set;
        subs(nums,0,v,set);
        return v;
        
    }
};