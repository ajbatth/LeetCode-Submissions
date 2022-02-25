class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>ver1,ver2;
        string temp1,temp2;
        int n1=version1.size(),n2=version2.size();
        for(int i=0;i<n1;i++){
            if(version1[i]=='.'|| i==n1-1){
                if(i==n1-1)temp1.push_back(version1[i]);
                ver1.push_back(stoi(temp1));
                temp1="";
            }
            else{
                temp1.push_back(version1[i]);
            }
        }
        for(int i=0;i<n2;i++){
            if(version2[i]=='.'|| i==n2-1){
                if(i==n2-1)temp2.push_back(version2[i]);
                ver2.push_back(stoi(temp2));
                temp2="";
            }
            else{
                temp2.push_back(version2[i]);
            }
        }
        if(ver1.size()<ver2.size()){
            int diff=ver2.size()-ver1.size();
            for(int i=0;i<diff;i++){
                ver1.push_back(0);
            }
        }
        else if(ver1.size()>ver2.size()){
            int diff=ver1.size()-ver2.size();
            for(int i=0;i<diff;i++){
                ver2.push_back(0);
            }
        }
        
        int n=ver1.size();
    
        for(int i=0;i<n;i++){
            if(ver1[i]==ver2[i])continue;
            if(ver1[i]<ver2[i])return -1;
            if(ver1[i]>ver2[i])return 1;
        }
        return 0;
    }
};