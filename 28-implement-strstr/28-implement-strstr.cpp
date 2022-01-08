class Solution {
public:
    int strStr(string haystack, string needle) {
        int ns=needle.length();
        int idx=-1;
        if(needle=="")return 0;
        if(haystack=="")return -1;
        if(needle.size()>haystack.size()) return -1;
        for(int i=0;i<=haystack.length()-ns;i++){
            if(haystack.substr(i,ns)==needle){
                idx=i;
                break;
            }
        }
        return idx;
    }
};