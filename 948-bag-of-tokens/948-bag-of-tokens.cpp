class Solution {
public:
    
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        if(n==0)return 0;
        sort(tokens.begin(),tokens.end());
        if(tokens[0]>power )return 0;
        int i=0,j=n-1,ans=0,s=0;
        while(i<=j){
            if(power>=tokens[i]){
                s++;
                power-=tokens[i];
                i++;
            }
            else if(s>=1){
                s--;
                power+=tokens[j];
                j--;
            }
            ans=max(ans,s);
            
        }
        return ans;
    }
};