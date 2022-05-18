class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int it=0;it<n;it++){
            int target=-nums[it];
            int i=it+1;
            int j=n-1;
            if(target<0)break;
            while(i<j){
                if(nums[i]+nums[j]<target){
                    i++;
                }
                else if(nums[i]+nums[j]>target)j--;
                else{
                    vector<int>triplet={nums[it],nums[i],nums[j]};
                    ans.push_back(triplet);
                    
                    while(i<j && nums[i]==triplet[1])i++;
                    while(i<j && nums[j]==triplet[2])j--;
                    
                }
            }
            while(it+1 < n && nums[it+1]==nums[it] )it++;
        }
        return ans;
    }
};