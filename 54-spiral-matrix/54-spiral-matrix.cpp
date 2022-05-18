class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),
            n=matrix[0].size();
        vector<int>ans;
        int rs=0,re=n-1,cs=0,ce=m-1;
        while(rs<=re && cs<=ce){
            if(rs<=re && cs<=ce){
                for(int i=rs;i<=re;i++){
                    ans.push_back(matrix[cs][i]);
                }
                cs++;
            }
            
            if(rs<=re && cs<=ce){
                for(int i=cs;i<=ce;i++){
                    ans.push_back(matrix[i][re]);
                }
                re--;
            }
            
            if(rs<=re && cs<=ce){
                for(int i=re;i>=rs;i--){
                    ans.push_back(matrix[ce][i]);
                }
                ce--;
            }
            
            if(rs<=re && cs<=ce){
                for(int i=ce;i>=cs;i--){
                    ans.push_back(matrix[i][rs]);
                }
                rs++;
            }
                    
        }
        return ans;
    }
};