#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int n, m; cin >> n >> m;
    ll a[n], b[n];
    for(ll& el: a) cin >> el;
    for(ll& el: b) cin >> el;
    
    ll ans = 1e18, now = 0;
    for(int i = n; i--; ){
        if(i < m) ans = min(ans, now + a[i]);
        now += min(a[i], b[i]);
    }
    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;
    while(t -- )solve();


    return 0;
} 
