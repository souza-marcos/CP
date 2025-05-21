#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    
    int n; cin >> n;
    ll last = 0, cnt = 0, lastcnt = 0;
    for(int i =0; i <n ; i++){
        ll a, aux; cin >> a; aux = a;
        while(a < last) a *= 2, cnt ++;
        last = aux;
    }
    cout << cnt << endl;
}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
