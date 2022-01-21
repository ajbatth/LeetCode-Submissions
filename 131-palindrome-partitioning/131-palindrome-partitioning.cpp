class Solution {
private:
    bool check_palin(string s,int start,int end){
            int i=start,j=end;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    
    void part(string s,int st,vector<string>&pp,vector<vector<string>>&ans,vector<vector<int>>&dp){
        int n=s.length();
        if(st==n){
            ans.push_back(pp);
            return;
        }
        
        for(int i=st;i<n;i++){
            
            bool check=0;
            if(dp[st][i]!=-1)check=dp[st][i];
            else{
                dp[st][i]=check=check_palin(s,st,i);
            }
            if(check){
                string s1=s.substr(st,i-st+1);
                
                pp.push_back(s1);
                part(s,i+1,pp,ans,dp);
                pp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<string>pp;
        vector<vector<string>>ans;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        part(s,0,pp,ans,dp);
        return ans;
    }
};