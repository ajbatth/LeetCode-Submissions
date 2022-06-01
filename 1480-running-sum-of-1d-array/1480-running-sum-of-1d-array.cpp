class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size());
        int num=0;
        for(int i=0;i<nums.size();i++){
            num+=nums[i];
            ans[i]=num;
        }
        return ans;
        
    }
};