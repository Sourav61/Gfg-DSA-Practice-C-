// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &res)
    {
        res.push_back(node);
        vis[node] = 1;

        for (auto x : adj[node])
        {
            if (!vis[x])
                dfs(x, vis, adj, res);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> res;
        vector<int> vis(V + 1, 0);

        dfs(0, vis, adj, res);

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends