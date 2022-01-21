class Solution {
private:
    bool check_palin(string s){
            int i=0,j=(s.length()-1);
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    
    void part(string s,vector<string>&pp,vector<vector<string>>&ans){
        int n=s.length();
        if(n==0){
            ans.push_back(pp);
            return;
        }
        
        for(int i=0;i<n;i++){
            string s1=s.substr(0,i+1);
            string s2=s.substr(i+1);
            if(check_palin(s1)){
                pp.push_back(s1);
                part(s2,pp,ans);
                pp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>pp;
        vector<vector<string>>ans;
        part(s,pp,ans);
        return ans;
    }
};