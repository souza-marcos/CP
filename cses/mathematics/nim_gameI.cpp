#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
const int MOD = 1e9 + 7;

int32_t main(){

    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        int res = 0, a;
        while(n --) cin >> a, res ^= a;
        cout << (res != 0 ? "first\n" : "second\n");
    }

}

// 1 + 1 + 1
// 1 + 2
// 2 + 1
// 3