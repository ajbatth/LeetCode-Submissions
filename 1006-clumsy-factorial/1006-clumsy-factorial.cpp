class Solution {
public:
    int clumsy(int n) {
        if(n==1)return 1;
        vector<long long>v;
        for(long long i=n;i>0;i-=4){
            long long x=i;
            if(x==1)v.push_back(-1);
            if(x-1>=1){
                long long p=x*(x-1);
                p*=(i==n?1:-1);
                x--;
                if(x-1>=1)p/=x-1;
                x--;
                if(x-1>=1){
                   p+=x-1;
                }
                v.push_back(p);
            }
            
            
        }
        int N=v.size();
        long long ans=v[0];
        for(int i=1;i<N;i++){
            ans+=v[i];
        }
        return ans;
        
    }
};