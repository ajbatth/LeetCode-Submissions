class Solution {
public:
    double champagneTower(double poured, int query_row, int query_glass) {
        vector<vector<double>>v(101,vector<double>(101,0));
        v[0][0]=poured;
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                if(v[i][j]>1){
                    v[i+1][j]+=(v[i][j]-1)/2.0;
                    v[i+1][j+1]+=(v[i][j]-1)/2.0;
                }
                if(i==query_row && j==query_glass){
                    if(v[i][j]>1)return 1;
                    return v[i][j];
                }
            }
        }
        return v[query_row][query_glass];
        
    }
};