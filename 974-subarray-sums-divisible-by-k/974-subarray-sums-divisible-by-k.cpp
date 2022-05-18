class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> arr(k,0);
        arr[0]=1;
        int ans=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int r=sum%k;
            if(r<0)r+=k;
            ans+=arr[r];
            arr[r]++;
        }
        return ans;
        
    }
};