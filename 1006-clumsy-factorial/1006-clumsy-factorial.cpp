class Solution {
public:
    int clumsy(int n) {
        if(n==1)return 1;
        long long ans=0;
        for(long long i=n;i>0;i-=4){
            long long x=i;
            if(x==1)ans+=(-1);
            if(x-1>=1){
                long long p=x*(x-1);
                p*=(i==n?1:-1);
                x--;
                if(x-1>=1)p/=x-1;
                x--;
                if(x-1>=1){
                   p+=x-1;
                }
                ans+=(p);
            }
            
            
        }
        
        return ans;
        
    }
};