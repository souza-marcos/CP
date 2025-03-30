#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){

    int n; cin >> n;
    string s, t; cin >> s >> t;
    int cnt1[2] = {0, 0}, cnt2[2] = {0, 0};
    bool ok = true;
    for(int i = 0; i < n; i ++) {
        cnt1[i%2] += s[i] == '1';
        cnt2[i%2] += t[i] == '0';
    }
    ok = cnt1[0] <= cnt2[1] and cnt1[1] <= cnt2[0];
    cout << (ok? "YES\n" : "NO\n");

}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
