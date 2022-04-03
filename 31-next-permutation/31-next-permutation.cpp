class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx1,idx2,idx3;
        bool flag=0;
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                 idx1=i-1;
                 idx2=i;
                flag=1;
                break;
            }
            }
        if(flag)
        {
            for(int i=idx2;i<n;i++){
            if(nums[i]>nums[idx1]){
                 idx3=i;
            }
        }
        
        int temp=nums[idx1];
        nums[idx1]=nums[idx3];
        nums[idx3]=temp;
        
        reverse((nums.begin()+idx2),nums.end());
            }
        
        if(flag==0)
        sort(nums.begin(),nums.end());
            
        
    }
};

