class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        vector<string>v;
        s.push_back(' ');
        string st="";
        for(int i=0;i<=n;i++){
            if(s[i]==' '){
                if(st.size()>0){
                    v.push_back(st);
                    st="";
                }                
            }
            else{
                st.push_back(s[i]);
            }            
        }
        
        st="";
        for(int i=v.size()-1;i>=0;i--){
            st+=v[i];
            st.push_back(' ');
        }
        st.pop_back();
        return st;
    }
};