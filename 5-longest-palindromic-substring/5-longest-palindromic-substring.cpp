class Solution {

public:
    string longestPalindrome(string s) {
        int n=s.length();
        pair<int,int> ans={0,0};
        int best_len=1;
        
        bool dp[n][n];
        
        for(int d=0;d<n;d++){
            for(int i=0,j=d; j<n; i++,j++){
                if(d==0)dp[i][j]=1;
                
                else if(d==1){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                        if(best_len<j-i+1){
                            ans={i,j};
                            best_len=j-i+1;
                        }
                    }
                    else dp[i][j]=0;                    
                }
                
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=1;
                        if(best_len<j-i+1){
                            ans={i,j};
                            best_len=j-i+1;
                        }
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
            }
        }
        
        return s.substr(ans.first,best_len);
        
    }
};