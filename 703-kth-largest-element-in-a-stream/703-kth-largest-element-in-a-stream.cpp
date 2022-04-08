class KthLargest {
public:
    multiset<int>st;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
    }
    
    int add(int val) {
        st.insert(val);
        auto it=st.end();
        for(int i=0;i<K;i++){
            it--;
        }
        return *it;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */