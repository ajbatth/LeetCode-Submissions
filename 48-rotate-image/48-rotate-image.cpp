class Solution {
public:
    void swap(vector<vector<int>>& matrix,int i,int j,int k,int l){
        int temp=matrix[i][j];
        matrix[i][j]=matrix[k][l];
        matrix[k][l]=temp;        
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int k,l;
        
        for(int i=0;i<n;i++){
            int c=1;
            for (int j=0;j<n;j++){
                
                if(j>i){
                    k=i+c,l=j-c;
                    swap(matrix,i,j,k,l);
                    c++;
                }
            }
             k=0,l=n-1;
            while(k<l) {
                swap(matrix,i,k,i,l);
                k++;
                l--;
            }
        }
    }
};