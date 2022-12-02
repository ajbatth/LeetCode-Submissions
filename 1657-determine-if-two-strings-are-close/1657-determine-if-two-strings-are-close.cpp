class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int>m1,m2;
        for(auto x:word1){
            m1[x]++;
        }
        for(auto x:word2){
            m2[x]++;
        }
        vector<char>v1,v2;
        multiset<int>s1,s2;
        for(auto x:m1){
            v1.push_back(x.first);
            s1.insert(x.second);
        }
        for(auto x:m2){
            v2.push_back(x.first);
            s2.insert(x.second);
        }
        return v1==v2 && s1==s2;
    }
};