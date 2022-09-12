class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int>v;
        int n=s.size();
        string st="";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(s[i-1]<='9'&& s[i-1]>='0')v.push_back(stoi(st));
                st="";
            }
            else{
                st.push_back(s[i]);
            }
        }
        if(st.back()<='9'&& st.back()>='0')v.push_back(stoi(st));
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1]){
                return false;
            }
        }
        return true;
    }
};