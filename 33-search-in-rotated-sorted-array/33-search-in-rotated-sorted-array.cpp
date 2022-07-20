class Solution {
public:
    int pivot(vector<int>&nums){
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[(mid+1)%n]>=nums[mid] && nums[(mid-1+n)%n]>=nums[mid])return mid;
            if(nums[mid]<nums[low] || nums[mid]<nums[high])high=mid-1;
	        else low=mid+1;
        }
        return low;
    }
    int binarySearch(vector<int>&v, int low,int high,int target){
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(v[mid]==target)ans=mid;
            if(v[mid]<target)low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int pt=pivot(nums);
        int n=nums.size();
        if(target<=nums[n-1]){
            return binarySearch(nums,pt,n-1,target);
        }
        else{
            return binarySearch(nums,0,pt,target);
        }
        
    }
};