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
    if (n <= 2) cout << n << endl;
    else {
        int el = 4, res = 2;
        while(el < n) el += el + 2, res ++;
        cout << res << endl;
    }

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
