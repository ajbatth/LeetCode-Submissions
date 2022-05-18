class Solution {
    bool f(vector<vector<char>>& board,string word,int I,int J,int K){
        int m=board.size(),n=board[0].size();
        if(K==word.size())return true;
        if(I<0 || J<0 || I>=m || J>=n)return false;
        if(word[K]!=board[I][J])return false;
        board[I][J]='0';
        bool ans=0;
        ans=ans|f(board,word,I+1,J,K+1);
        ans=ans|f(board,word,I-1,J,K+1);
        ans=ans|f(board,word,I,J+1,K+1);
        ans=ans|f(board,word,I,J-1,K+1);
        
        board[I][J]=word[K];
        return ans;
        
        
       
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        bool ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=ans|f(board,word,i,j,0);
            }
        }
        return ans;
    }
};