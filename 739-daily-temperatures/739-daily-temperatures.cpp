class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>stk;
        vector<int>ans;
        int n=temp.size();
        for(int i=n-1;i>=0;i--){
            
            while(!stk.empty() && temp[stk.top()]<=temp[i]){
                stk.pop();
            }
            if(stk.empty()){
                ans.push_back(0);
                stk.push(i);
                continue;
            }
            ans.push_back(stk.top()-i);
            stk.push(i);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};