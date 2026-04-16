// meeting start time and end time deoya thbe..2 ta meeting ek sthe hote parbe na..koita meeting hbe ta ans dite hbe.
// end1<start2 hote hbe..
#include <bits/stdc++.h>
using namespace std;

static bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second; // sort by end time..jeta boro seta age ashbe..
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> timer;

    // store all meetings
    for (int i = 0; i < n; i++)
    {
        timer.push_back({start[i], end[i]});
    }

    // sort by ending time
    sort(timer.begin(), timer.end(), comp);

    int total = 0;
    int ending = -1;

    // greedy selection
    for (int i = 0; i < n; i++)
    {
        if (timer[i].first > ending)
        {
            total++;
            ending = timer[i].second;
        }
    }

    return total;
}
