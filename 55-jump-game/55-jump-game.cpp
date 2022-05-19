class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return true;
        int req_jump=0;
        for(int i=n-2;i>=0;i--){
            req_jump++;
            if(nums[i]>=req_jump)req_jump=0;
            
        }
        if(req_jump==0)return true;
        return false;
    }
};