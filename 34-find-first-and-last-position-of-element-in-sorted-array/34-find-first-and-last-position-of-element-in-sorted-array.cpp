class Solution {
private:
    int lowerBound(vector<int>& nums, int target){
        int n=nums.size();
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)ans=mid;
            if(nums[mid]<target)low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
    int upperBound(vector<int>&nums,int target){
        int n=nums.size();
        int ans=-1;
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)ans=mid;
            if(nums[mid]>target)high=mid-1;
            else{
                low=mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        res.push_back(lowerBound(nums,target));
        res.push_back(upperBound(nums,target));
        return res;
    }
};