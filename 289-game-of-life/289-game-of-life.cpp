class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //vector<pair<int,int>>v;
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int one=0;
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        if(x==0 && y==0)continue;
                        if(i+x<m && i+x>=0 && j+y>=0 && j+y<n)
                        if((board[i+x][j+y])%2==1)one++;
                        
                    }
                }
                // if(board[i][j]==1 && one<2)v.push_back({i,j});
                // else if(board[i][j]==1 && one>3)v.push_back({i,j});
                // else if(board[i][j]==0 && one==3)v.push_back({i,j});
                if(board[i][j]%2==1 && one<2)board[i][j]+=2;
                else if(board[i][j]%2==1 && one>3)board[i][j]+=2;
                else if(board[i][j]%2==0 && one==3)board[i][j]+=2;
                
            }
        }
        // for(auto it:v){
        //     int i=it.first,j=it.second;
        //     board[i][j]=(board[i][j]+1)%2;
        // }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]>1){
                    board[i][j]=(board[i][j]+1)%2;
                }
            }
        }
        
    }
};