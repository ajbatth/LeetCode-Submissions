class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=INT_MIN;
        stack<int>st;
        st.push(-1);
        heights.push_back(0);
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(st.size()>1 && heights[i]<=heights[st.top()]){
                int ht=heights[st.top()];
                st.pop();
                int left=st.top();
                ans=max(ans,ht*(i-left-1));
            }
            st.push(i);
        }
        return ans;
    }
};