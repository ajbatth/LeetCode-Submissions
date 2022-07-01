class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<int>q;
        vector<int>visited(n,-1);
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