#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

/*
1 4 3 2
2 1 4 3
3 2 1 4
4 3 2 1
*/

void solve(){

    int n; cin >> n;
    vector<tuple<int, int, int>> res;
    for(int i = 0; i < n; i ++){
        if(i + 1 > 1) res.emplace_back(i + 1, 1, i + 1);
        if(i + 2 < n) res.emplace_back(i + 1, i + 2, n);
    }
    cout << sz(res) << endl;
    for(auto [a, b, c]: res) cout << a << " " << b << " " << c << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
