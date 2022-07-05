class Solution {
bool hasCycle(int node, vector<int>adj[], vector<int>&vis, vector<int>&dfsVis, vector<int>&st){
    vis[node]=1;
    dfsVis[node]=1;
    
    for(auto child:adj[node]){
        if(!vis[child]){
            if(hasCycle(child,adj,vis,dfsVis,st))return true;
        }
        else if(dfsVis[child])return true;
    }
    dfsVis[node]=0;
    st.push_back(node);
    return false;
}
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(int i=0;i<pre.size();i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int> vis(n), dfsVis(n),ans;
        vector<int>st;
        bool flag=1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                flag=flag&&(!hasCycle(i,adj,vis,dfsVis,st));
            }
            if(!flag)return ans;
        }
        return st;
    }
};