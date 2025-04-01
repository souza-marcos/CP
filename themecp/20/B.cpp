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
    int nnew = n;
    int to_most = 32 - __builtin_clz(n);
    vector<int> ans; ans.push_back(n);
    for(int i = 0; i < to_most-1; i ++){
        if((1 << i) & n) n &= ~(1 << i), ans.push_back(n);
    }
    for(int i = to_most-1; i > 0; i --) n >>= 1, ans.push_back(n);

    cout << sz(ans) << endl;
    for(auto el : ans) cout << el << " ";
    cout << endl;

}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
