class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        st.insert(nums);
        while(next_permutation(nums.begin(),nums.end())){
            st.insert(nums);
        }
        vector<vector<int>>ans;
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
    }
};