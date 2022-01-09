class Solution {
public:
    int solve(int n,vector<int> &v){
        if(n<=1)return 1;
        if(v[n]!=-1){
            return v[n];
        }
        int first=solve(n-1,v);
        int second=solve(n-2,v);
        v[n]=first+second;
        
        return v[n];
    }
    int climbStairs(int n) {
        vector<int>v(n+1,-1);
        return solve(n,v);
        
    }
};