class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int>st;
        int n=stones.size();
        for(int i=0;i<n;i++){
            st.insert(stones[i]);
        }
        while(st.size()>1){
            int y=*(--st.end());
            st.erase(--st.end());
            int x=*(--st.end());
            st.erase(--st.end());
            if(x<y){
                st.insert(y-x);
            }
        }
        return *st.begin();
    }
};