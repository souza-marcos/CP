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
    
    if(m%2 == 1 and n > 0){
        cout << -1 << endl;
        return;
    }

    while(n != 0){
        while(n < m) cnt += n, n <<= 1;
        n -= m;
    }
    cout << cnt << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
