class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string>ans;
        if(n==0)return ans;
        int start=nums[0];       
        int counting=nums[0];
        stack<int>st;
        for(int i=0;i<n;i++){
            if( !st.empty() && nums[i]>(st.top()+1)){
                if(st.size()==1){
                    ans.push_back(to_string(start));
                    start=nums[i];
                    while(!st.empty())st.pop();
                }
                else if(st.size()>1){
                    string temp=to_string(start);
                    temp+="->";
                    temp+=to_string(st.top());
                    ans.push_back(temp);
                    start=nums[i];
                    while(!st.empty())st.pop();
                }
            }
            st.push(nums[i]);
        }
                   if(st.size()==1){
                    ans.push_back(to_string(start));
                    
                }
                else if(st.size()>1){
                    string temp=to_string(start);
                    temp+="->";
                    temp+=to_string(st.top());
                    ans.push_back(temp);
                    
                }
        
        
        return ans;
    }
};