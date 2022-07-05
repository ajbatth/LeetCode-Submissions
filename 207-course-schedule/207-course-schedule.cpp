class Solution {
    bool hasCycle(int node,vector<int>adj[],vector<int>&vis,vector<int>& dfsvis){
        vis[node]=1;
        dfsvis[node]=1;
        
        for(auto child:adj[node]){
            if(!vis[child] && !dfsvis[child]){
                if(hasCycle(child,adj,vis,dfsvis))return true;
            }
            else if(dfsvis[child])return true;            
        }
        dfsvis[node]=0;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        int N=pre.size();
        for(int i=0;i<N;i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int>vis(n,0),dfsvis(n,0);
        bool ans=1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans=ans&&(!hasCycle(i,adj,vis,dfsvis));
            }
            if(!ans)return false;
        }
        return ans;
        
    }
};