class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        for(auto x:arr){
            m[x]++;
        }
        set<int>st;
        for(auto x:m){
            st.insert(x.second);
        }
        return m.size()==st.size();
    }
};