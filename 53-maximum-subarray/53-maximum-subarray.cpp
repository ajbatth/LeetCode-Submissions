class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0],sum=0,n=nums.size();
        bool flag=0;
        
        
        for(int i=0;i<n;i++){
            if(sum+nums[i]>=nums[i])
                sum+=nums[i];
            
            else{
                sum=nums[i];
            }
            maxsum=max(maxsum,sum);
        }
        return maxsum;
        
    }
};