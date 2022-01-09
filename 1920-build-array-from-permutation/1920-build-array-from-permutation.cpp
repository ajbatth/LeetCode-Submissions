class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[nums[i]]);
        }
        
        nums.erase(nums.begin(),nums.begin()+n);
        return nums;
    }
};