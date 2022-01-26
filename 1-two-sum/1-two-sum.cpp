#include <bits/stdc++.h>
bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.first<b.first;
    }
class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans(2);
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({nums[i],i});
        }
        sort(vp.begin(),vp.end(),cmp);
        int i=0,j=n-1;
        while(i<j){
            if(vp[i].first+vp[j].first==target){
                ans[0]=vp[i].second;
                ans[1]=vp[j].second;
                break;
            }
            else if(vp[i].first+vp[j].first<target)i++;
            else if(vp[i].first+vp[j].first>target)j--;
        }
        return ans;
    }
};