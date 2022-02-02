#define mod 1000000007
typedef long long int ll;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>hs(26,0),hp(26,0);
        int n=s.length();
        int m=p.length();
        vector<int>v;
        for(int i=0;i<m;i++){
            hp[p[i]-'a']++;
        }
        
        for(int i=0;i<m && i<n;i++){
            hs[s[i]-'a']++;
        }
        bool flag=1;
        for(int j=0;j<26;j++){
            if(hs[j]!=hp[j])flag=0;
        }
        if(flag)v.push_back(0);
        
        for(int i=1;i<=n-m;i++){
            hs[s[i-1]-'a']--;
            hs[s[i+m-1]-'a']++;
            
            bool flg=1;
        for(int j=0;j<26;j++){
            if(hs[j]!=hp[j])flg=0;
        }
        if(flg)v.push_back(i);
        }
        return v;
        
        
    }
};