#include <bits/stdc++.h>
using namespace std;

//with extra space
int main() {
    vector<vector<int>> ar = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int r = ar.size();
    int c = ar[0].size();

    vector<vector<int>> ans(c, vector<int>(r));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans[j][i] = ar[i][j];
        }
    }

    // print transpose matrix
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}