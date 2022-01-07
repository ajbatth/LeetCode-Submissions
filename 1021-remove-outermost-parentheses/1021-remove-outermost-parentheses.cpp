class Solution {
public:
    string removeOuterParentheses(string s) {
       stack<char>st;
        string ans;
        int count=0;
        int size=s.length();
       int i=0,l=0,r=size-1;
        while(i<size){
            if(s[i]=='('){
                st.push('(');
                i++;
            }
            if(s[i]==')'){
                st.pop();
                i++;
            }
            if(st.empty()){
                for(l=l+1;l<i-1;l++){
                    ans.push_back(s[l]);
                }
                l=i;
            }
        }
        
        
       
        return ans;
    }
};