// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Edge{
    public:
    int wt;
    int u;
    int v;
    Edge(int w,int U,int V){
        wt=w;
        u=U;
        v=V;
    }
};
bool cmp(Edge& a, Edge& b){
    return a.wt<b.wt;
}
void makeset(vector<int>&parent){
    int n=parent.size();
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
}
int findParent(int node,vector<int>&parent){
    if(parent[node]==node)return node;
    return parent[node] = findParent(parent[node],parent);
}
void unian(int u, int v, vector<int>&parent,vector<int>&rank){
    int u_parent=findParent(u,parent);
    int v_parent=findParent(v,parent);
    if(rank[u_parent]<rank[v_parent]){
        parent[u_parent]=v_parent;
    }
    else if(rank[u_parent]>rank[v_parent]){
        parent[v_parent] = u_parent;
    }
    else{
        parent[u_parent] = v_parent;
        rank[u_parent]++;
    }
}

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<int>parent(V),rank(V,0);
       vector<Edge>edges;
       
       for(int i=0;i<V;i++){
           for(auto ch:adj[i]){
               Edge edge=Edge(ch[1],i,ch[0]);
               edges.push_back(edge);
           }
       }
       sort(edges.begin(),edges.end(),cmp);
       
       makeset(parent);
       
       int N=edges.size();
       int ans=0;
       for(int i=0;i<N;i++){
           if(findParent(edges[i].u, parent)!=findParent(edges[i].v, parent)){
               ans+=edges[i].wt;
               unian(edges[i].u,edges[i].v,parent,rank);
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
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends