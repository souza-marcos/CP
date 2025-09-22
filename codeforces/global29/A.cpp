#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _

    int t; cin >> t;
    while(t --){
        int x, y; cin >> x >> y;
        if(y > x) cout << 2 << endl;
        else if(x >= y + 2 and y > 1) cout << 3 << endl;
        else cout << -1 << endl;
    }
} 
// 
