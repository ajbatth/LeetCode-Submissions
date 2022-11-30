class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto x:arr){
            m[x]++;
        }
        unordered_set<int>st;
        for(auto x:m){
            st.insert(x.second);
        }
        return m.size()==st.size();
    }
};