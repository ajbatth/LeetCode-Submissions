class Solution {
private:
    // using 2 data structures.
    void perm(vector<int>& nums,vector<vector<int>>&ans,int idx,vector<int>&p,vector<int>&map){
        if(p.size()==nums.size()){
            ans.push_back(p);
            return;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(map[i]==1)continue;
            p.push_back(nums[i]);
            map[i]=1;
            perm(nums,ans,i-1,p,map);
            map[i]=0;
            p.pop_back();
        }
    }
    // without using any additional DS
void permutation(vector<int>& nums,vector<vector<int>>&ans,int idx){
    int n=nums.size();
    if(idx==n){
        ans.push_back(nums);
        return;
    }
    for(int i=idx;i<n;i++){
        swap(nums[i],nums[idx]);
        permutation(nums,ans,idx+1);
        swap(nums[i],nums[idx]);
    }
}
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>p,map(nums.size(),0);
        vector<vector<int>>ans;
        permutation(nums,ans,0);
        return ans;
    }
};