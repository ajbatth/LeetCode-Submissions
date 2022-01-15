class Solution {
private:
    void subsets(vector<vector<int>>&ps,vector<int>&nums,int i,vector<int>&ss){
        
                ps.push_back(ss);
           
        for(int j=i;j<nums.size();j++){
            if(j!=i && nums[j]==nums[j-1] )continue;
            ss.push_back(nums[j]);
            subsets(ps,nums,j+1,ss);
            ss.pop_back();
        }
        return;
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ps;
        vector<int>ss;
        sort(nums.begin(),nums.end());
        subsets(ps,nums,0,ss);
        return ps;
        
    }
};