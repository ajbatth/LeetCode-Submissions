class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        int ans=0,diff=nums[1]-nums[0],count=1;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==diff)count++;
            else{
                if(count>=2)ans+=(count*(count-1))/2;
                
                diff=nums[i]-nums[i-1];
                count=1;
            }
        }
        if(count>=2)ans+=(count*(count-1))/2;
        return ans;
    }
};