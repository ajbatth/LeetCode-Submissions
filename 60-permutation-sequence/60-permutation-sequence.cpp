class Solution {
private:
    int fact(int n){
        int f=1;
        for(int i=2;i<=n;i++){
            f*=i;
        }
        return f;
    }
public:
    
    string getPermutation(int n, int k) {
        vector<int>v;
        string ans;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        k--;
        while(1){
            n--;
            int f=fact(n);
            int i=k/f;
            ans.push_back(v[i]+'0');
            v.erase(v.begin()+i);
            if(k==0)break;
            k=k%f;
        }
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i]+'0');
        }
        return ans;
    }
};