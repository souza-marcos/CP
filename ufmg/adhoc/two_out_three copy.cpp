#include <bits/stdc++.h>

using namespace std;
const int N = 100;

void solve()
{
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &el : arr) cin >> el;


    vector<int> b(n, 1);
    vector<vector<int>> inds(N + 1);
    for (int i = 0; i < n; i++)
    {
        inds[arr[i]].push_back(i); // Val x in index x
    }

    int k = 2;
    for (int x = 1; x <= N; x++)
    {
        if ((int)inds[x].size() >= 2)
        {
            b[inds[x][0]] = k;
            k++;
            if (k > 3) break;
        }
    }
    if (k <= 3)
    {
        cout << "-1\n";
        return;
    }
    
    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}