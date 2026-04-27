// dijkstra algo negative weight er jnno fail kre
// so bellman ford negative er jnno kaj kre..directed weighted graph...undirected graph er upor eita use krbona.undirected graph e negative weight thkle oitar shortest path ber kra jbe na..ans possibe na..
// negative circle er shortest path ber kra impossible..negative circle means all weight er sum negative songkha hbe
// step-1: initially sob node er dist value infinite thkbe..just 0 er 0 hbe..  0---3(weight)--->2...dis[u]+w<dist[v]--dist[0]+3<dist[2]..condition mille update hbe..mane 2 no index dist[0]+3 value ta hbe..v-1 bar ei loop cholbe and value updtae hbe--edges relax koranor formolla
// step-2:  v-1.after that r ekbar loop chalabo mane edges relax korabo jdi eibr value update hy tahole eita negative circle ase..so shortest path ber kra jbe na..otherwise we got shortest path

// time complexity:
// Worst case: V*E
// Best case: E
// Space:V
#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int V, vector<vector<int>> &edges, int S)
{
    // Code here
    vector<int> dist(V, 1e8);

    // 1e8 = 10^8
    dist[S] = 0;

    int e = edges.size();

    for (int i = 0; i < V - 1; i++)
    {
        // Relax all the edges
        int flag = 0;
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] == 1e8)
                continue;

            if (dist[u] + wt < dist[v])

            {
                flag = 1;
                dist[v] = dist[u] + wt;
            }
        }
        if (!flag)
            return dist;
    }

    // To detect the cycle
    for (int j = 0; j < e; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] == 1e8)
            continue;

        if (dist[u] + wt < dist[v])
        {
            // cycle detected
            vector<int> ans;
            ans.push_back(-1);
            return ans;
        }
    }

    return dist;
}