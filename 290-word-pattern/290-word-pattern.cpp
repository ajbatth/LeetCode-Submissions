class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>vs;
        string temp;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                vs.push_back(temp);
                temp="";
            }
            else{
                temp.push_back(s[i]);
            }
        }
        vs.push_back(temp);
        
        unordered_map<char,string>mp;
        unordered_set<string>ss;
        if(pattern.size()!=vs.size())return false;
        for(int i=0;i<pattern.size();i++){
            if(mp.find(pattern[i])==mp.end()){
                mp[pattern[i]]=vs[i];
            }
            else if(vs[i]!=mp[pattern[i]])return false;
            ss.insert(vs[i]);
        }
        return mp.size()==ss.size();
    }
};