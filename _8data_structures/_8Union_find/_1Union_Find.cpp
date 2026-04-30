#include <iostream>
#include <vector>
using namespace std;

class DisjointSetUnion
{
public:
    int n;
    vector<int> par, rank;

    DisjointSetUnion(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) // initally parent will be ownself and rank will be 0
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) // parent find kre dibe
    {
        if (par[x] == x)
        {
            return x;
        }
       // return find(par[x]); 
        return par[x] = find(par[x]); // path compression-- 0->2->3->4..0 and 2 er parent 0..so amra 3,4 er parent o 0 kre dibo..er jnno TC=O(1)
    }

    void unionByRank(int a, int b) // a b merge krbe
    {
        int parA = find(a); // a er parent khujbe
        int parB = find(b); // b er parent khujbe

        if (parA == parB)
            return;

        if (rank[parA] == rank[parB]) // rank 2 tar soman hole
        {                             // case 1
            par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB]) // A er rank boro hole
        {                                 // case 2
            par[parB] = parA;
        }
        else // B er rank boro hole
        {    // case 3
            par[parA] = parB;
        }
    }

    void getInfo()
    {
        for (int i = 0; i < n; i++)
        {
            cout << par[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < n; i++)
        {
            cout << rank[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DisjointSetUnion dsu(6);

    dsu.unionByRank(0, 2);
    cout << dsu.find(2) << endl;

    dsu.unionByRank(1, 3);
    dsu.unionByRank(2, 5);
    dsu.unionByRank(0, 3);

    cout << dsu.find(2) << endl;

    dsu.unionByRank(0, 4);

    dsu.getInfo();

    return 0;
}