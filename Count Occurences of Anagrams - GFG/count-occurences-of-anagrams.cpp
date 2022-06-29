// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    long long  p_hash=0;
	    int n=pat.size();
	    int m=txt.size();
	    for(auto it:pat){
	        long long idx=it-'a'+1;
	        p_hash+=pow(2,idx)*idx;
	    }
	    
	    long long  t_hash=0;
	    for(int i=0;i<n;i++){
	        long long idx=txt[i]-'a'+1;
	        t_hash+=(pow(2,idx)*idx);
	    }
	    int count=0;
	    if(p_hash==t_hash)count++;
	    for(int i=n;i<m;i++){
	        long long preidx=txt[i-n]-'a'+1;
	        t_hash-=pow(2,preidx)*preidx;
	        
	        long long idx=txt[i]-'a'+1;
	        t_hash+=pow(2,idx)*idx;
	        if(p_hash==t_hash)count++;
	        
	    }
	    return count;
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