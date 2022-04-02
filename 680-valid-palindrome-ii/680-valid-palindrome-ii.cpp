class Solution {
public:
    bool checkpalin(string s,int i,int j){
        
        while(i<=j){
            if(s[i]!=s[j])return false;
            j--;
            i++;
        }
        return true;
    }
        
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return checkpalin(s,i+1,j)||checkpalin(s,i,j-1);
            }            
            i++;
            j--;
        }
        return true;
    }
};