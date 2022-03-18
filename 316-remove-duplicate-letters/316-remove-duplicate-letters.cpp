class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        vector<char>st;
        vector<int>taken(26,0);
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(int i=0;i<n;i++){
            while(st.size()!=0 && s[i]<st.back() && mp[st.back()]>1&& taken[s[i]-'a']==0){
                mp[st.back()]--;
                taken[st.back()-'a']=0;
                st.pop_back();
                
            }
            
            if(taken[s[i]-'a']==0){
                st.push_back(s[i]);
                taken[s[i]-'a']=1;
            }
            else
                mp[s[i]]--;
            
            
        }
        n=st.size();
        string ans="";
        for(int i=0;i<n;i++){
            ans.push_back(st[i]);
        }
        return ans;
       
    }
};