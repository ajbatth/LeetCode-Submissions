class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char>st={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int c1=0,c2=0;
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(st.count(s[i])){
                c1++;
            }
        }
        for(int i=n/2;i<n;i++){
            if(st.count(s[i]))c2++;
        }
        return c1==c2;
    }
};