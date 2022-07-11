// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minTime(int S1, int S2, int N){
        long long time=min(S1,S2);
        long long high= (N*time), low=1;
        while(high>low){
            long long mid=low+((high-low)/2);
            int copies=(mid/S1)+(mid/S2);
            if(copies>=N){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return high;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S1, S2, N;
        cin>>S1>>S2>>N;
        
        Solution ob;
        cout<<ob.minTime(S1, S2, N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends