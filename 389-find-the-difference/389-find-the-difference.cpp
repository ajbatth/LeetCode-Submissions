class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_multiset<char>t_set;
        for(int i=0;i<t.size();i++){
            t_set.insert(t[i]);
        }
        
        for(int i=0;i<s.size();i++){
            auto it=t_set.find(s[i]);
            t_set.erase(it);
        }
        
        return *t_set.begin();
    }
};