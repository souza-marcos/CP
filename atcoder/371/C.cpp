#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);

#define sz(x) (int)x.size()

int main(){ _

    int n, mg; cin >> n >> mg;
    vector<vector<bool>> g(n, vector<bool>(n, 0)), h(n, vector<bool>(n, 0));
    int v, u;
    for(int i = 0; i < mg; i ++){
        cin >> u >> v; u --, v --;
        g[u][v] = g[v][u] = 1;
    }

    int mh; cin >> mh;
    for(int i = 0; i < mh; i ++){
        cin >> u >> v; u --, v --;
        h[u][v] = h[v][u] = 1;
    }

    vector<vector<int>> a(n);
    for(int i = 0; i < n-1; i ++){
        a[i].resize(n);
        for(int j = i + 1; j < n; j ++){
            cin >> a[i][j];
        }
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    ll minv = LINF;

    do{
        // Edge i ?= Edge p[i]
        ll sum = 0;
        for(int i = 0; i < n; i ++){
            for(int j = i+1; j < n; j ++){
                if(g[p[i]][p[j]] ^ h[i][j]) sum += a[i][j];
            }
        }

        if(sum < minv) minv = sum;
    }while(next_permutation(p.begin(), p.end()));

    cout << minv << endl;
    return 0;
} 
