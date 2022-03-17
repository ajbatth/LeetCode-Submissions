class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(0);
            }
            else{
                int tp=st.top();
                st.pop();
                int tp2=st.top();
                st.pop();
                st.push(tp2+max(2*tp,1));
            }
        }
        return st.top();
    }
};