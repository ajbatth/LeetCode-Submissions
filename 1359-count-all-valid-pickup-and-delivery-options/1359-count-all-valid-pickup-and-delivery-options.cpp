#define ll long long
class Solution {
public:
    int countOrders(int n) {
        if(n==1)return 1;
        ll N=2*n;
        ll sum=1;
        for(ll i=4;i<=N;i+=2){
            sum=(sum*(i*(i-1))/2)%1000000007;
        }
        return sum;
        
    }
};