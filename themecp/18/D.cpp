#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    
    int n, m; cin >> n >> m;
    priority_queue<ll> a, b;
    for(int i = 0; i < n; i ++) {
        int el; cin >> el;
        a.push(el);
    }
    for(int i = 0; i < m; i ++) {
        int el; cin >> el;
        b.push(el);
    }

    auto remove = [&](){
        if(sz(b) <= 0) return;
        ll bfront = b.top(), afront = a.top();
        b.pop(), a.pop();
        while(bfront == afront and sz(b) > 0){
            bfront = b.top(); b.pop();
            afront = a.top(); a.pop();
        }
        if(afront != bfront) 
            b.push(bfront), a.push(afront);
    };

    remove();
    while(sz(b) < sz(a) and sz(b) > 0){
        ll bfront = b.top(); b.pop();
        ll xl = bfront/2; 
        ll xr = bfront - xl;
        b.push(xl), b.push(xr);
        remove();
    }
    remove();
    bool ok = !(sz(b)|sz(a));
    cout << (ok ? "Yes\n":"No\n") ;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
