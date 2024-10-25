#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n; cin >> n;
    map<int, int> mp;
    for(int i = -n + 1; i < n; i ++) {
        mp[i] = 0;
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            int a;
            cin >> a; a *= -1;
            mp[j-i] = max(mp[j-i], a);
        }
    }
    ll cnt = 0;
    for(auto [k, el]: mp){
        cnt += el;
    }
    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
