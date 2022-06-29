// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string p, string s) {
	    // code here
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
        return v.size();
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends