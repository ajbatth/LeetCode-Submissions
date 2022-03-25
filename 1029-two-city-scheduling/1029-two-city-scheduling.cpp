class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int>A,B;
        int n=costs.size();
        for(int i=0;i<n;i++){
            if(costs[i][0]<costs[i][1]){
                A.push_back(i);
            }
            else{
                B.push_back(i);
            }
        }
        
        if(A.size()<B.size()){
            int diff=abs((int)A.size()-(int)B.size())/2;
            sort(B.begin(),B.end(),
                 [&costs](int a,int b)->bool {
                       return costs[a][0]-costs[a][1] >costs[b][0]-costs[b][1] ;
                    }
                );
            while(diff>0){
                A.push_back(B.back());
                B.pop_back();
                diff--;
            }
        }
        else{
            int diff=abs((int)A.size()-(int)B.size())/2;
            sort(A.begin(),A.end(),
                 [&costs](int a,int b)->bool {
                       return costs[a][1]-costs[a][0]>costs[b][1]-costs[b][0];
                    }
                );
            while(diff>0){
                B.push_back(A.back());
                A.pop_back();
                diff--;
            }
        }
        int ans=0;
        for(int i=0;i<n/2;i++){
            ans+=costs[A[i]][0];
            ans+=costs[B[i]][1];
        }
        return ans;
    }
};