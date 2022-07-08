// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    void toposort(int node, vector<int>adj[], stack<int>&st, vector<int>& vis){
        vis[node]=1;
        
        for(auto ad:adj[node]){
            if(!vis[ad]){
                toposort(ad,adj,st,vis);
                
            }
        }
        st.push(node);
    }
    void Dfs(int node, vector<int>adj[], vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it])
            Dfs(it,adj,vis);
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int>st;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                toposort(i,adj,st,vis);
            }
        }
        vector<int>revAdj[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                revAdj[it].push_back(i);
            }
        }
        int ans=0;
        vector<int>Vis(V,0);
        while(!st.empty()){
            int i=st.top();
            st.pop();
            if(!Vis[i]){
                ans++;
                Dfs(i,revAdj,Vis);
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends