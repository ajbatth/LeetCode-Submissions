class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>mst;
        int n=nums.size();
        for(int i=0;i<k;i++){
            mst.insert(nums[i]);
        }
        vector<int>ans;
        ans.push_back(*(--mst.end()));
        for(int i=k;i<n;i++){
            auto it=mst.find(nums[i-k]);
            mst.erase(it);
            mst.insert(nums[i]);
            ans.push_back(*(--mst.end()));
        }
        return ans;
    }
};