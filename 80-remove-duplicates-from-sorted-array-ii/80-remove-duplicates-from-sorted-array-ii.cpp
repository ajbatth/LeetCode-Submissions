class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=1,j=1;
        int pre=nums[0],count=1;
        while(j<n){
            if(nums[j]==pre)count++;
            else{
                count=1;
                pre=nums[j];
            }
            if(count>2){
                while(j<n && nums[j]==pre)j++;
                count=1;
                if(j<n)
                pre=nums[j];
            }
           if(j<n){
                swap(nums[i],nums[j]);
            i++;
            j++;
           }
        }
        return i;
    }
};