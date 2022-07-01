class Solution {
public:
    bool dfsCheck(int root,vector<vector<int>>&graph,vector<int>& visited){
        for(auto it:graph[root]){
            if(visited[it]==-1){
                visited[it]=(visited[root]+1)%2;
                if(!dfsCheck(it,graph,visited))return false;
            }
            else if(visited[it]==visited[root])return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<int>q;
        vector<int>visited(n,-1);
                //using dfs
                
                bool ans=1;
                for(int i=0;i<n;i++){
                    if(visited[i]==-1){
                        visited[i]=1;
                        ans=ans && dfsCheck(i,graph,visited);
                    }
                    if(!ans)return false;
                }
                return ans;
        //using bfs
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                q.push(i);
                visited[i]=0;
                while(!q.empty()){
                    int curr=q.front();
                    q.pop();
                    for(auto child:graph[curr]){
                        if(visited[child]==-1){
                            q.push(child);
                            visited[child]=(visited[curr]+1)%2;
                        }
                        else if(visited[child]==visited[curr])return false;
                    }
                }
            }
            
        }
        return true;
    }
};