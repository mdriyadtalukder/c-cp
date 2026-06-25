// graph er node k 2 ta grp e vag krbo..emn vabe jate grp er elements adjecency(connected na thke) na hy eke oporer..
// odd length er circle hole bipartite grp hbena
// red then blue eivabe color dite thkbo..j color thkbe tar neighbor bipodid color er thkbe..ekta ekta node er jbo and er size ba er childs gular color assign krbo or check krbo j soman nki
#include <bits/stdc++.h>
using namespace std;
bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 0;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int j = 0; j < adj[node].size(); j++)
                {

                    // color not assigned
                    if (color[adj[node][j]] == -1)
                    {
                        color[adj[node][j]] = (color[node] + 1) % 2;
                        q.push(adj[node][j]);
                    }
                    // color already assigned
                    else
                    {
                        if (color[node] == color[adj[node][j]]) // color[node] parent r er neighbors/child color[adj[node][j]] soman hote parbe na
                        {
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}