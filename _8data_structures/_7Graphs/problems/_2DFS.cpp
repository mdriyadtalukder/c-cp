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
            ans.push_back(node); // 1st push 0

            // push neighbors (reverse for same order as recursion)
            for (int j = adj[node].size() - 1; j >= 0; j--) // reverse coz--Because stack is LIFO (Last In First Out).
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
/*

stack version
      0
     / \
    1   2
   / \
  3   4

adj[0] = {1, 2} ---stack reverse kore dibe(Because stack is LIFO (Last In First Out)) like 2,1 then 1 pick hbe
adj[1] = {0, 3, 4}--reverse krbe like 4,3..so pic 3,4 then back giye 2..so 0,1,3,4,2
adj[2] = {0}
adj[3] = {1}
adj[4] = {1}

DFS-0 → 1 → 3 → 4 → 2

*/
//vector<int> dfsOfGraph(int V, vector<int> adj[])