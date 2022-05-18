class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>had;
        had[0]=1;
        int sum=0,n=nums.size(),count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(had.find(sum-k)!=had.end())
                count+=had[sum-k];
            had[sum]++;
            
        }
        return count;
    }
};