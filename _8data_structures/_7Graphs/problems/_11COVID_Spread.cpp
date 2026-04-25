// 2d d array thkbe..jar jar value 2 taile oita covid patient.jar covid j tar upor,nich,dan,bam er cell re covid dibe mane 2 hbe
// koto unit time lgbe..like 2d te 4ta 2 ase tahole 4 ta 2 tar ashepashe covid dibe 1 unit e.
//.then latest patient tader ashe pashe covid dibe 1 unit e...1+1=2..so on

#include <bits/stdc++.h>
using namespace std;
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

int r;
int c;

bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

int helpaterp(vector<vector<int>> hospital)
{
    r = hospital.size();
    c = hospital[0].size();

    queue<pair<int, int>> q;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (hospital[i][j] == 2)
                q.push(make_pair(i, j));

    int timer = 0;

    while (!q.empty())
    {
        int curr_patient = q.size();

        while (curr_patient--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                if (valid(i + row[k], j + col[k]) &&
                    hospital[i + row[k]][j + col[k]] == 1)
                {
                    hospital[i + row[k]][j + col[k]] = 2;
                    q.push(make_pair(i + row[k], j + col[k]));
                }
            }
        }

        if (!q.empty()) // 🔥 FIX: only increase time if next level exists
            timer++;
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (hospital[i][j] == 1)
                return -1;

    return timer;
}
