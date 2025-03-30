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
    set<ll> pref = {0};
    ll acc = 0;
    int cnt = 0;
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        acc += a;
        if(pref.count(acc)){
            cnt ++; acc = 0;
            pref.clear(); pref = {0};
        }else pref.insert(acc);
    }

    cout << cnt << endl;
}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
