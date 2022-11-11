class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int empty_idx=0,count=0,n=nums.size();
        if(n==0) return 0;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[empty_idx++]=nums[i];
                count++;
            }
           
        }
        nums[empty_idx]=nums[n-1];
        count++;
        
        return count;
    }
};