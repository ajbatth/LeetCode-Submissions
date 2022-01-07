class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push('(');
            ans=ans>st.size()?ans:st.size();
            if(s[i]==')' && !st.empty()) st.pop();
            
        }
        return ans;
        
    }
};