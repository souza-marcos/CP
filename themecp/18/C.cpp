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
    ll cnt =0;
    n %= m;
    
    ll ops = 0;
    while(n != 0 and ops < 500){
        while(n < m) cnt += n, n <<= 1;
        n -= m;
        ops ++;
    }
    if(n == 0) cout << cnt << endl;
    else cout << -1 << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
