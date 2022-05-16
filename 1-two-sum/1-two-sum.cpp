class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
        vector<int>ans(2);
        for(int i=0;i<n;i++){
            int fnd=target-nums[i];
            if(mp.find(fnd)!=mp.end()){
                ans[0]=i;
                ans[1]=mp[fnd];
                return ans;
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return ans;
    }
};