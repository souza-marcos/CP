#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1 ; i < n; i ++){
        int p; cin >> p; p--;
        g[p].push_back(i);
    }
    vector<int> colors(n); for(auto& el: colors) cin >> el;

    auto dfs = [&](auto dfs, int p, int v) -> int {
        int sum = 0;
        for(int u: g[v]) sum += dfs(dfs, v, u); 
        if(p >= 0 and colors[v] != colors[p]) sum ++;
        return sum;
    };
    int res = dfs(dfs, -1, 0);
    cout << res + 1 << endl;

    return 0;
} 
