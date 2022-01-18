class Solution {
private:
    void solve(vector<int> &check,int n,int row,int &ans){
        if(row==n){
            ans+=1;
            return;
        }
       
        for(int col=0;col<n;col++){
            int upper_right_Dia=n+row+col;
            int upper_left_Dia=n+((2*n)-1)+(n-1)+(col-row);
            if(check[col]==0 && check[upper_right_Dia]==0 && check[upper_left_Dia]==0){
                check[col]=1;
                check[upper_right_Dia]=1;
                check[upper_left_Dia]=1;
                
                solve(check,n,row+1,ans);
                
                check[col]=0;
                check[upper_right_Dia]=0;
                check[upper_left_Dia]=0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<int>check(5*n,0);
        int ans=0;
        solve(check,n,0,ans);
        return ans;
    }
};