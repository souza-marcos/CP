#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n, m, q; cin >> n >> m >> q;
    ll d[n][n]; 
    for(int i=0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            d[i][j]=LINF;

    for(int i = 0; i < n; i ++)
        d[i][i] = 0;

    for(int i = 0; i < m; i ++){
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        d[a][b] = d[b][a] =  min(d[a][b], c);
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    while(q--){
        int a, b; cin >> a >> b; a--, b--;
        ll val = min(d[a][b], d[b][a]);
        cout << (val >= LINF ? -1: val) << endl;
    }
}
