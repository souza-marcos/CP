#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    
    int n, q; cin >> n >> q;
    int MAX = log2(1e9) + 1;
    int up[n][MAX];
    for(int i = 0; i < n; i ++){
        int a; cin >> a; a--;
        up[i][0] = a;
    }

    for(int h = 1; h < MAX; h ++){
        for(int i = 0; i < n; i ++){
            up[i][h] = up[up[i][h-1]][h-1];
        }
    }

    while(q--){
        int x, k; cin >> x >> k;
        x --;
        for(ll i = MAX-1, j = (1LL << i); i >= 0; i --, j >>= 1){
            if(k >= j) x = up[x][i], k -= j;
        }
        cout << x + 1 << endl;
    }


}
