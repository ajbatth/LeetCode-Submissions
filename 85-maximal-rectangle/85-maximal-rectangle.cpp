class Solution {
    int MAH(vector<int>&v){
        stack<int>s,st;
        vector<int>left,right;
        int n=v.size();
        
        // nearest smallest to the left
        for(int i=0;i<n;i++){
            while(!st.empty() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.empty()){
                left.push_back(-1);
                st.push(i);
                continue;
            }
            left.push_back(st.top());
            st.push(i);
        }
        
        // nearest smaller to right
        for(int i=n-1;i>=0;i--){
             while(!s.empty() && v[s.top()]>=v[i]){
                s.pop();
            }
            if(s.empty()){
                right.push_back(n);
                s.push(i);
                continue;
            }
            right.push_back(s.top());
            s.push(i);
        }
        reverse(right.begin(),right.end());
        
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,(right[i]-left[i]-1)*v[i]);
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>v(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') v[j]+=1;
                else v[j]=0;
            }
            ans=max(ans,MAH(v));
        }
        return ans;
        
    }
};








