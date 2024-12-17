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
    vector<int> cnt(n);
    int res = 0;

    // ceil(Cnt apenas 1 / 2)
    int diff = 0;
    for(int i = 0 ; i < n; i ++){
        int a; cin >> a; a--; cnt [a] ++;
        if(cnt[a] == 1) diff ++;
        if(cnt[a] == 2) res ++;
    }

    int jo = diff - res;
    res = ceil(jo /2.0);
    res += diff - (jo/2);
    cout << res << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
