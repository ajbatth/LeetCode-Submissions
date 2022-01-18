class Solution {
private:
    bool possible(vector<vector<char>>&board,int row,int col, char ch){
        for(int i=0;i<9;i++){
            if(board[row][i]==ch)return false;
            
            if(board[i][col]==ch) return false;
            
            int r=3*(row/3)+(i/3);
            int c=3*(col/3)+(i%3);
            if(board[r][c]==ch)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(possible(board,i,j,k)){
                            board[i][j]=k;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};