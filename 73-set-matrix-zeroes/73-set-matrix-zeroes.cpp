class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //vector<pair<int,int>>vp;
        bool flag=1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    // vp.push_back(make_pair(i,j));
                    if(i==0){
                        flag=0;
                    }
                    else{
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                    }
                }
            }
        }
        
//         for(int i=0;i<vp.size();i++){
//             for(int m=0;m<matrix[0].size();m++){
//                 matrix[vp[i].first][m]=0;
//             }
            
//             for(int m=0;m<matrix.size();m++){
//                 matrix[m][vp[i].second]=0;
//             }
        
        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]==0){
                for(int j=1;j<matrix[i].size();j++){
                    matrix[i][j]=0;
                }
            }
        }
        
            
        for(int j=1;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                for(int i=1;i<matrix.size();i++){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
        if(flag==0){
            for(int i=0;i<matrix[0].size();i++){
                matrix[0][i]=0;
            }
        }
    }
};