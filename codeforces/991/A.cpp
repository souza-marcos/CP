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
    int cnt = 0;
    while(n--){
        string s; cin >> s;
        m -= sz(s);
        if(m >= 0) cnt ++;
    }

    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
