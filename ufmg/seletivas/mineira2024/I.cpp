#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;
#define endl "\n"
#define sz(x) (int)x.size()


void solve(){
    int n; cin >> n;
    vector<int> v(n), pre(n), pos(n); 
    cin >> v[0];
    pre[0] = v[0];
    pair<int, int> 
    for(int i = 1; i < n; i ++){
        cin >> v[i]; 
        pre[i] = v[i] + pre[i-1];
    }
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
