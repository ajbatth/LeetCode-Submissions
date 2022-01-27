class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(v.size()==0 || v.back()<nums[i]){
                v.push_back(nums[i]);
            }
            
            else{
                auto lw=lower_bound(v.begin(),v.end(),nums[i]);
                *lw=nums[i];
            }
            
        }
        return v.size();
    }
};