class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
           mp[s[i]]=i;
        }
        int e=mp[s[0]],sum=1;
        vector<int>ans;
        ans.push_back(-1);
        for(int i=0;i<=n;i++){
            if(i>e|| i==n){
                ans.push_back(i-sum+1);
                sum+=ans.back();
                if(i<n)
                e=mp[s[i]];
            }
            else if(i<e && mp[s[i]]>e){
                e=mp[s[i]];
            }
            
        }
        ans.erase(ans.begin());
        return ans;
        
    }
};