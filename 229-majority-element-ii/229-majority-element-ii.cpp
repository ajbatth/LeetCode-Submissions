class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int>ans;
        int n=size(nums);
        int req=n/3+1;
        int count=0;
        int target=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]!=target){
                count =0;
            }
            if(count==0)target=nums[i];
            if(nums[i]==target)count++;
            
            if(count==req)ans.push_back(nums[i]);
        }
        return ans;
    }
};