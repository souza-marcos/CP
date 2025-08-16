#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _

    int n, q; cin >> n >> q;
    vector<ll> pre(n + 1);
    for(int i = 1; i <= n; i ++){
        ll a; cin >> a;
        pre[i] = pre[i-1] + a;
    }

    while(q--){
        int l, r; cin >> l >> r; l--;
        cout << (pre[r] - pre[l]) << endl;
    }

    return 0;
} 
