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
    int res = 0;
    vector<int> a(n), b(m), zero(32);
    for(auto &el : a) {
        cin >> el;
        res ^= el;
    }

    int bo = 0;
    for(auto& el: b) cin >> el, bo |= el;

    int minv = res, maxv = res;
    if(n % 2 == 0){
        minv ^= bo;
    } else maxv |= bo;

    cout << minv << " " << maxv << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
