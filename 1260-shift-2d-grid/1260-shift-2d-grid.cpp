class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        k=k%(m*n);
        
        while(k>0){
            for(int i=0;i<m;i++){
                vector<int>temp=grid[i];
                grid[i][0]=temp[n-1];
                for(int j=1;j<n;j++){
                    grid[i][j]=temp[j-1];
                }
                
            }
            vector<int>temp(m);
            for(int i=0;i<m;i++){
                temp[i]=grid[i][0];
            }
            grid[0][0]=temp[m-1];
            for(int i=1;i<m;i++){
                grid[i][0]=temp[i-1];
            }
            k--;
        }
        return grid;
    }
};