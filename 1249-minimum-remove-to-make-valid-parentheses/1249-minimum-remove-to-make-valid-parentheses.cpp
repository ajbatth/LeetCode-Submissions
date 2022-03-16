class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        vector<char>v;
        int n=s.size();
        for(int i=0;i<n;i++){
            v.push_back(s[i]);
        }
        for(int i=0;i<n;i++){
            if(st.empty() && v[i]==')'){
                v[i]='/';
                }
            else if(v[i]=='('){
                st.push(i);
            }
            else if(v[i]==')'){
                st.pop();
            }
            
        }
        while(!st.empty()){
            v[st.top()]='/';
            st.pop();
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(v[i]!='/')ans.push_back(v[i]);
        }
        return ans;
    }
};