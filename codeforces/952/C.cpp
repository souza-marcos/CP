#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sx(x) (int)x.size()
#define endl "\n"

void solve(){
    int n; cin >> n;
    vector<ll> v(n);

    for(ll& el: v) cin >> el;

    ll acc = v[0];
    ll max_val = v[0];
    int cnt = (v[0] == 0);
    for(int i = 1; i < n; i++){
        acc += v[i];
        max_val = max(max_val, v[i]);
        if((acc - max_val) == max_val) cnt ++;
    }

    cout << cnt << endl;
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
