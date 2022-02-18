class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> stk;
        int n=num.size();
        int i;
        for(i=0;i<n && k>0;i++){
            int temp=num[i]-'0';
            if(stk.size()==0)stk.push_back(temp);
            else if(temp>=stk.back())stk.push_back(temp);
            else {
                while(k>0 && stk.size()!=0 && temp<stk.back()){
                    stk.pop_back();
                    k--;
                }
                stk.push_back(temp);
            }
            
        }
         while(k>0){
            stk.pop_back();
            k--;
        }
        string ans;
        int j=0;
        while(j<stk.size() && stk[j]==0){
            j++;
        }
        for(;j<stk.size();j++){
            ans+=stk[j]+'0';
        }
        
        if(ans.size()==0){
            for(;i<n && num[i]=='0';i++){
                continue;
            }
        }
        for(;i<n;i++){
            ans+=num[i];
        }
        if(ans.size()==0){
            ans+='0';
        }
        
        return ans;
    }
};