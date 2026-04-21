// TC=O(v+e)..SC=O(v)
// ekta node select krbo then oita explore krte then pre step e back krbo j right side e aro node ase nki er jnno.
//.eivbe root e back krbo and next child expore krbo..so on
#include <bits/stdc++.h>
using namespace std;
void DFS(int node, vector<int> adj[], vector<int> &ans, vector<bool> &visited)
{
    visited[node] = 1;
    ans.push_back(node);

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
        {
            DFS(adj[node][j], adj, ans, visited);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> visited(V, 0);
    vector<int> ans;

    DFS(0, adj, ans, visited);

    return ans;
}

// stack version
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> visited(V, 0);
    vector<int> ans;
    stack<int> st;

    st.push(0);

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            visited[node] = 1;
            ans.push_back(node);

            // push neighbors (reverse for same order as recursion)
            for (int j = adj[node].size() - 1; j >= 0; j--)
            {
                if (!visited[adj[node][j]])
                {
                    st.push(adj[node][j]);
                }
            }
        }
    }

    return ans;
}