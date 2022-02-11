class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())return false;
        vector<int>h1(26,0),h2(26,0);
        int n=s1.size();
        int m=s2.size();
        for(int i=0;i<n;i++){
            h1[s1[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            h2[s2[i]-'a']++;
        }
        for(int i=n;i<m;i++){
            int flag=1;
            for(int j=0;j<26;j++){
                if(h1[j]!=h2[j]){
                    flag=0;
                    break;
                }
            }
            if(flag)return true;
            h2[s2[i-n]-'a']--;
            h2[s2[i]-'a']++;
            
        }
        int flag=1;
            for(int j=0;j<26;j++){
                if(h1[j]!=h2[j]){
                    flag=0;
                    break;
                }
            }
            if(flag)return true;
        return false;
    }
};