class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0 || n==1)return n;
        int st=0,maxi=1;
        unordered_map<char,int>m;
        
        for(int i=0;i<n;i++){
            if(m.find(s[i])!=m.end())
            st=max(st,m[s[i]]+1);
            maxi=max(maxi,i-st+1);
            m[s[i]] =i;
        }
        return maxi;
    }
};