class Solution {
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        int pre3=0;
        int pre2=1;
        int pre=1;
        for(int i=3;i<=n;i++){
            int curr=pre+pre2+pre3;
            pre3=pre2;
            pre2=pre;
            pre=curr;
        }
        return pre;
    }
};