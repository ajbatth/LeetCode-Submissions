class Solution {
public:
    vector<int> lps(string p){
        vector<int>pi(p.size(),0);
        int j=1;
        for(int i=1;i<p.size();i++){
            j=pi[i-1];
            
           while(j>0 && p[i]!=p[j]){
               j=pi[j-1];
           } 
            
            if(p[i]==p[j])
                j++;
            
            pi[i]=j;
        }
        return pi;
    }
    
    int strStr(string haystack, string needle) {
        if(needle=="")return 0;
        int pos=-1;
       vector<int>pi=lps(needle);
        int i=0,j=0;
        while(i<haystack.size()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j=pi[j-1];
                }
                else{
                    i++;
                }
            }
            
            if(j==needle.size()){
                pos=i-needle.size();
                break;
            }
        }
        return pos;
    }
};