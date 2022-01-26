class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk,st;
        vector<int>left,right;
        int n=heights.size();
        
        //nearest smallest number to the left
        for(int i=0;i<n;i++){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty()){
                left.push_back(-1);
                stk.push(i);
                continue;
            }
            left.push_back(stk.top());
            stk.push(i);
            
        } 
        
        // Nearesr smallest number to the right
        for(int i=n-1;i>=0;i--){
             while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                right.push_back(n);
                st.push(i);
                continue;
            }
            right.push_back(st.top());
            st.push(i);
        }
        reverse(right.begin(),right.end());
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,(right[i]-left[i]-1)*heights[i]);
        }
        return maxi;
        
    }
};



