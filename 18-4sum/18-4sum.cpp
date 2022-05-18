class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int t=target-(nums[i]+nums[j]);
                int l=j+1,r=n-1;
                while(l<r){
                    if(nums[l]+nums[r]<t)l++;
                    else if(nums[l]+nums[r]>t)r--;
                    else{
                        vector<int>quad={nums[i],nums[j],nums[l],nums[r]};
                        ans.push_back(quad);
                        while(l<r && nums[l]==quad[2])l++;
                        while(l<r && nums[r]==quad[3])r--;
                    }
                }
                while(j+1<n-2 && nums[j+1]==nums[j])j++;
            }
            while(i+1<n-3 && nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};