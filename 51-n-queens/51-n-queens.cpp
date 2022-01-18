class Solution {
private:
    bool can_place(vector<string>&arrg,int row,int col){
        int n=arrg.size();
        int i=row,j=col;
        while(i>=0 && j>=0){
            if(arrg[i][j]=='Q')return false;
            i--;j--;
        }
        i=row;
        while(i>=0){
            if(arrg[i][col]=='Q') return false;
            i--;
        }
        i=row;j=col;
        while(i>=0 && j<n){
            if(arrg[i][j]=='Q')return false;
            i--;j++;
        }
        return true;
    }
    
    void solve(vector<vector<string>> &ans, vector<string>&arrg,int row){
        int n=arrg.size();
        if(row>=n){
            ans.push_back(arrg);
            return;
        }
        
            for(int j=0;j<n;j++){
                if(can_place(arrg,row,j)){
                    arrg[row][j]='Q';
                    solve(ans,arrg,row+1);
                    arrg[row][j]='.';
                }
            }
        
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<vector<string>>ans;
        vector<string>arrg(n,s);
        //arrg[1][1]='Q';
        //ans.push_back(arrg);
        solve(ans,arrg,0);
        return ans;
    }
};