class Solution {
    
    int merge(vector<int>&nums,int l, int mid, int r){
        vector<int>v;
        int pairs=0;
        int i=l,j=mid;
        while(i<mid){
            while(j<=r && nums[i]>nums[j]*2LL){
                j++;
            }
            pairs+=j-mid;
            i++;
        }
        i=l,j=mid;
        while(i<mid && j<=r){
            if(nums[i]<nums[j]){
                v.push_back(nums[i]);
                i++;
            }
            else{
                v.push_back(nums[j]);
                j++;
            }
        }
        while(i<mid){
            v.push_back(nums[i]);
                i++;
        }
        while(j<=r){
            v.push_back(nums[j]);
                j++;
        }
        
        int n=v.size();
        for(i=0;i<n;i++){
            nums[l+i]=v[i];
        }
        
        
        
        return pairs;
    }
    
    
    int mergesort(vector<int>&nums,int l,int r){
        if(l==r)return 0;
        int pairs=0;
        int mid=(l+r+1)/2;
       pairs+= mergesort(nums,l,mid-1);
       pairs+= mergesort(nums,mid,r);
        
        pairs+=merge(nums,l,mid,r);
        return pairs;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,(int)nums.size()-1);
    }
};