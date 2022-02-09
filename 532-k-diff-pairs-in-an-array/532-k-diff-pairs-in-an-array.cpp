class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        if(k==0){
           
            for(auto it:m){
                
                if(m[it.first]>1)count++;
            }
        }
        else{
            for(auto it:m){
            if(m.find(it.first+k)!=m.end())count++;
        }
        }
       
        
        return count;
    }
};