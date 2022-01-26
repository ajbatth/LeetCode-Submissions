class Solution {
public:
    int fib(int n) {
        int first=0;
        int second=1;
        int fib=0;
        
        if(n==1) return 1;
        
        for(int i=2;i<=n;i++){
            fib=first+second;
            first=second;
            second=fib;
            
        }
        return fib;
    }
};