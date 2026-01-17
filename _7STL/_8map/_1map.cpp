#include <bits/stdc++.h>
using namespace std;
int main()
{
    // key vlue pair..alway sort hoye ashe key and key unique thke..
    map<string, int> m;
    m["tv"] = 100;
    m["tv2"] = 50;
    m["tv3"] = 20;
    m["phone"] = 10;
    m.insert({"iphn", 300});
    m.emplace("iphn17", 70);

    m.erase("tv3"); // tv3 rmv krbe

    for (auto e : m)
    {
        cout << e.first << " " << e.second;
        cout << endl;
    }
    cout << m.count("iphn17") << endl; // koita iphn17 key ase oi map e ta blbe..total 1 ta ase.

    if (m.find("tv2") != m.end())
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }

    cout << m.size() << endl;
    cout << m.empty();

    // multimal same as map..has some chnage ..those are:

    multimap<string, int> m2;

    // m[2"tv"] = 100; it does not work in multi map
    m2.insert({"iphn", 300});
    m2.insert({"iphn", 300});
    m2.insert({"iphn", 300});
    m2.insert({"iphn", 300});

    // ekhn print krle sob print hbe but map e sudu ekbr holo..coz sob same;

    m2.erase(m2.find("iphn")); // ekhn ekta ekta rmv hbe memory location dekhe dekhe
    m2.erase("iphn");          // sob rmv kre dibe

    // unordered_map same as map..it print values in random way..not sort way..its very usefull then map then multimap:

    unordered_map<string, int> m3;
    m3["tv"] = 100;
    m3["tv2"] = 50;
    m3["tv3"] = 20;
    m3["phone"] = 10;

    for (auto el : m3)
    {
        cout << el.first << " " << el.second;
        cout << endl;
    }

    // unorder_map vs map------map's count,erase,insert..... TC=O(logn) but unorder_map is O(1);
}