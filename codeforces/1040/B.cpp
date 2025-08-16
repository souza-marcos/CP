#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
// #define int ll

void solve(){

    int n, s; cin >> n >> s;
    vector<int> cnt(3);

    int r = 0;
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        cnt[a] ++;
        r += a;
    }

    if(r == s){
        cout << -1 << endl;
    }
    else if(s < r) {
        for(int i = 0; i < 3; i ++){
            while(cnt[i]--) cout << i << " ";
        }
        cout << endl;
    }
    else {
        s -= r;
        if(s > 1){
            cout << -1 << endl;
            return;
        }
        while(cnt[1]--) cout << 1 << " ";
        while(cnt[2]--) cout << 2 << " ";
        while(cnt[0]--) cout << 0 << " ";
        cout << endl;
    }

}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
