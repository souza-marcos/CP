#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    if(k > 3) cout << 0 << endl;
    else if(k == 1){
        cout << 1 << endl;
    } else if(k == 2){
        if(m >= n){
            ll qtd = m/n + n - 1;
            cout << qtd << endl;
        }else { 
            cout << n-1 << endl;
        }
    } else{
        if(m <= n) cout << 0 << endl;
        else{
            cout << m - n - m/n + 1 << endl;
        }
    }



}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
