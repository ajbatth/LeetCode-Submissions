class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>m;
        for(auto x:arr){
            m[x]++;
        }
        vector<pair<int,int>>v;
        for(auto x:m){
            v.push_back({x.second,x.first});
        }
        sort(v.rbegin(),v.rend());
        int n=arr.size();
        int sz=n;
        int ans=0;
        for(auto x:v){
            if(sz>n/2){
                ans++;
                sz-=x.first;
            }
        }
        return ans;
    }
};