class Solution {
public:
    int bits(int n){
        if(n==0)return 0;
        int count =0;
        double l=log2(n);
        count ++;
        while(l-(int)l>0){
            n=n-pow(2,(int)l);
            l=log2(n);
            count++;
        }
        return count;        
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(bits(i));
        }
        return ans;
    }
};