class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int>v(7,0);
        int n=tops.size();
        for(int i=0;i<n;i++){
            v[tops[i]]++;
            v[bottoms[i]]++;
        }
        int ans=INT_MAX;
        for(int i=1;i<7;i++){
            if(v[i]>=n){
                int t=0,b=0;
                bool flag=1;
                for(int j=0;j<n;j++){
                    if(tops[j]==i)t++;
                    if(bottoms[j]==i)b++;
                    if(tops[j]!=i && bottoms[j]!=i){
                        flag=0;
                        break;
                    }
                }
                if(flag)ans=min(n-t,n-b);
            }
        }
        if(ans==INT_MAX)return -1;
        else return ans;
    }
};