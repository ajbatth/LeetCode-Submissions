class Solution {
int sink(int i,int j,vector<vector<char>>&grid){
    if(i<0 || j<0 || i==grid.size() || j==grid[i].size() || grid[i][j]=='0' || grid[i][j]=='#'){
        return 0;
    }
    grid[i][j]='#';
    sink(i+1,j,grid);
    sink(i,j+1,grid);
    sink(i-1,j,grid);
    sink(i,j-1,grid);
    return 1;
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count+=sink(i,j,grid);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='#')grid[i][j]='1';
            }
        }
        return count;
    }
};