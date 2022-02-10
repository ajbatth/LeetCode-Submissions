class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count =0, n= nums.size(),sum=0;
        unordered_map<int,int>mp;
        mp[0]++;
        
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            count+=mp[sum-k];
            mp[sum]++;
            
        }
            
        
    return count;
        
    }
};