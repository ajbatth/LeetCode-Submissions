class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        int n=size(columnTitle);
        int p=n-1;
        for(int i=0;i<n;i++){
            int temp=pow(26,p);
            int sum=columnTitle[i]-'A'+1;
            ans+=(temp*sum);
            p--;
        }
        return ans;
        
    }
};