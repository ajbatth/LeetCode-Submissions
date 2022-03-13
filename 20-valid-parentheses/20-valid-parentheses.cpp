class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        unordered_map<char,int>m={{'(',1},{')',-1},{'{',2},{'}',-2},{'[',3},{']',-3}};
        stack<int>st;
        for(int i=0;i<n;i++){
            if(m[s[i]]>0)st.push(m[s[i]]);
            if(m[s[i]]<0){
                //if(st.empty())return false;
                if(!st.empty() && m[s[i]]+st.top()==0)st.pop();
                else return false;
            }
        }
        if(st.empty())return true;
        else return false;
    }
};