#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
// #define int ll

void solve(){

    int n, s; cin >> n >> s;
    int cnt = 0;
    for(int i = 0; i < n ; i ++){
        int d1, d2, p1, p2; cin >> d1 >> d2 >> p1 >> p2;
        cnt += ((d1 == d2 and p1 == p2) or (d1 == -d2 and p1 == (s - p2)));
    }  
    cout << cnt << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
