#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n, m; cin >> n >> m;
    ll cur = 4 * m;
    int a, b; cin >> a >> b;
    while(--n){
        cin >> a >> b;
        cur += 2 * a + 2 * b;
    }
    cout << cur << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
