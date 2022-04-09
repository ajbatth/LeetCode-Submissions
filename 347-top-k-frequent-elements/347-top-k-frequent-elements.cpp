bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.first>b.first;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>um;
        vector<pair<int,int>>vp;
        int n=nums.size();
        for(auto i:nums){
            um[i]++;
        }
        for(auto it=um.begin();it!=um.end();it++){
            vp.push_back({it->second,it->first});
        }
        sort(vp.begin(),vp.end(),cmp);
        vector<int>v;
        
        
        auto it=0;
        while(k>0){
            v.push_back(vp[it].second);
            it++;
            k--;
        }
        
        return v;
    }
};