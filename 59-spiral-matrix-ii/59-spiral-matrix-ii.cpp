class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int rs=0,re=n-1,cs=0,ce=n-1,count=1;
        while(cs<=ce && rs<=re){
            for(int i=cs;i<=ce;i++){
                ans[rs][i]=count;
                count++;
            }rs++;
            
            for(int i=rs;i<=re;i++){
                ans[i][ce]=count;
                count++;
            }ce--;
            
            for(int i=ce;i>=cs;i--){
                ans[re][i]=count;
                count++;
            }re--;
            
            for(int i=re;i>=rs;i--){
                ans[i][cs]=count;
                count++;
            }cs++;
        }
        return ans;
    }
};