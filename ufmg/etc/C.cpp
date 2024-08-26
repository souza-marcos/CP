#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

void solve(){
    int n; cin >> n;
    vector<int> v(32, 0);

    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        int s = 32 - __builtin_clz(a);
        v[s] ++;
    }   

    ll ans = 0;
    for(auto el: v){
        ans += (ll)el * (el - 1)/2;
    }
    cout << ans << endl;
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
