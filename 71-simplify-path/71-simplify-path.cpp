class Solution {
public:
    string simplifyPath(string s) {
        vector<string>v;
       
        int n=s.size();
        string fol="";
        for(int i=0;i<=n;i++){
            if((s[i]=='/'&& i!=0&&s[i-1]!='/')||i==n){
                if(fol==".."&& v.size()!=0)v.pop_back();
                else if(fol.size()!=0 && fol!=".")
                v.push_back(fol);
                fol="";
            }
            if(s[i]!='/')fol.push_back(s[i]);
        }
        n=v.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(v[i]!=".."){
                ans.push_back('/');
                ans.append(v[i]);
            }
        }
        if(ans.size()==0)ans.push_back('/');
        return ans;
    }
};