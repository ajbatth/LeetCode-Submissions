class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),s=0,e=n-1;
        bool flag=1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                flag=0;
                break;
            }
            if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        if(flag)return -1;
        return (s+e)/2;
    }
};