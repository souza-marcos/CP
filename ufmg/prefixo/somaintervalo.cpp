#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ //_
    int n, q; cin >> n >> q;
    vector<ll> arr(n), pref(n + 1);
    for(auto& el: arr) cin >> el;
    pref[0] = 0;
    for(int i = 1; i <= n ; i++){
        pref[i] = arr[i - 1] + pref[i-1];
    }

    while(q --){
        int l, r; cin >> l >> r;
        cout << (pref[r] - pref[l - 1]) << endl;
    }

    return 0;
} 
