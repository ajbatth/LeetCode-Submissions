class Solution {
public:
    int calPoints(vector<string>& ops) {
       vector<int>ans;
        int n=ops.size();
        for(int i=0;i<n;i++){
            if(ops[i]=="C"){
                ans.pop_back();
            }
            else if( ops[i]=="D"){
                ans.push_back(2*ans.back());
            }
            else if(ops[i]=="+"){
                int N=ans.size();
                ans.push_back(ans[N-1]+ans[N-2]);
            }
            else{
                ans.push_back(stoi(ops[i]));
            }
        }
        int N=ans.size();
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=ans[i];
        }
        return sum;
    }
};