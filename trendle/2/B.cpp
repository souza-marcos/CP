#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){
    int n; cin >> n;
    ll res = 0;
    vector<int> arr(n); for(auto& el: arr) {
        cin >> el;
        res += el - 1;
    }

    if(res&1) cout << "errorgorn\n";
    else cout << "maomao90\n";

}

int main(){ _ 
    int t; cin >> t;
    while(t --) solve();
} 
